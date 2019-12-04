#include "unity.h"
#include "stateMachine.h"
#include "Error.h"
#include "Exception.h"
#include "CException.h"
#include "mock_gpio.h"
#include "mock_spi.h"
/*
#include "mock_timer.h" (example)
UpdateCCR3_Expect(10000); (example)

sendData_Expect(SPI4,0b00100000);
setResetGPIO_Expect(GPIOG,13,true);
readGPIO_ExpectAndReturn(GPIOA,0,true);
*/
void setUp(void)
{
}

void tearDown(void)
{
}



void test_stateMachineSlave_noDelayReadButtonCommands(void)
{
  //readGPIO will be call when
  //smInfo.state=READ_BUTTON_COMMAND;
  SMInfo smInfo;
  smInfo.delay=0;
  smInfo.slaveMsg=READ_BUTTON_COMMAND;
  smInfo.state=READ_BUTTON_COMMAND;
  readGPIO_ExpectAndReturn(GPIOA,0,true);
  stateMachineSlave(&smInfo);

  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(SENDBACK_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  sendData_Expect(SPI4,0b00100000);
  stateMachineSlave(&smInfo);

  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(DO_NOTHING,smInfo.state);
}

void test_stateMachineSlave_DelayReadButtonCommands(void)
{
  //readGPIO will be call when
  //smInfo.state=READ_BUTTON_COMMAND;
  SMInfo smInfo;
  smInfo.delay=2;
  smInfo.slaveMsg=READ_BUTTON_COMMAND;
  smInfo.state=READ_BUTTON_COMMAND;
  readGPIO_ExpectAndReturn(GPIOA,0,true);
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(1,smInfo.delay);
  TEST_ASSERT_EQUAL(WAIT_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(WAIT_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(SENDBACK_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  sendData_Expect(SPI4,0b00100000);
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(DO_NOTHING,smInfo.state);
}

void test_stateMachineSlave_toMakeSure_SENDBACK_BUTTON_STATE_correct(void)
{
  //readGPIO will be call when
  //smInfo.state=READ_BUTTON_COMMAND;
  SMInfo smInfo;
  smInfo.delay=2;
  smInfo.slaveMsg=READ_BUTTON_COMMAND;
  smInfo.state=READ_BUTTON_COMMAND;
  readGPIO_ExpectAndReturn(GPIOA,0,false);
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(1,smInfo.delay);
  TEST_ASSERT_EQUAL(WAIT_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(WAIT_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(SENDBACK_BUTTON_STATE,smInfo.state);

  smInfo.slaveMsg=0x00;
  sendData_Expect(SPI4,0b00000000);
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(0,smInfo.delay);
  TEST_ASSERT_EQUAL(DO_NOTHING,smInfo.state);
}

void test_stateMachineSlave_ledConfigCommands(void)
{
  SMInfo smInfo;
  smInfo.slaveMsg=CONTROL_LED_COMMMAND;
  smInfo.state=CONTROL_LED_COMMMAND;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(LED_CONFIG_STATE,smInfo.state);

  setResetGPIO_Expect(GPIOG,13,true);
  smInfo.slaveMsg=0b00100000;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(DO_NOTHING,smInfo.state);
}

void test_stateMachineSlave_makeSure_LED_CONFIG_STATE_correct(void)
{
  SMInfo smInfo;
  smInfo.slaveMsg=CONTROL_LED_COMMMAND;
  smInfo.state=CONTROL_LED_COMMMAND;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(LED_CONFIG_STATE,smInfo.state);

  setResetGPIO_Expect(GPIOG,13,false);
  smInfo.slaveMsg=0b00000000;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(DO_NOTHING,smInfo.state);
}

void test_stateMachineSlave_ignoreIrrevalentMessage(void)
{
  SMInfo smInfo;
  smInfo.slaveMsg=0x33;
  smInfo.state=DO_NOTHING;
  stateMachineSlave(&smInfo);
  TEST_ASSERT_EQUAL(DO_NOTHING,smInfo.state);
}
