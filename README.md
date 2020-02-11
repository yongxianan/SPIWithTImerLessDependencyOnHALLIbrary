# SPI with timer
## Objective
Use 2 SPI to communicate with each other, SPI1 as master and SPI 4 as slave. Use SPI1 with timer to delay sending after sending the first command, so that slave have enough time to read from GPIO. 32F429IDISCOVERY Board is used in the practical.
## Physical Connection & Configuration
![](https://trello-attachments.s3.amazonaws.com/5e4279e34658360c891fb7ff/5e427a25210f643e75da9bf6/466712d63be71b7e7522612c97adfcc7/image.png)
<h6>Figure 1: SPI conneciton.

![](https://trello-attachments.s3.amazonaws.com/5e4279e34658360c891fb7ff/5e427a25210f643e75da9bf6/21c25c917eae98828eca86b3c51469d3/image.png)
<h6>Figure 2: pins configuration

![](https://trello-attachments.s3.amazonaws.com/5e4279e34658360c891fb7ff/5e427a25210f643e75da9bf6/b6db1b7c5f321453dc4c2af89844e799/image.png)
<h6>Figure 3: SPI & timer configuration

SPI configure with unidirectional data mode, 8-bit data frame, full duplex (transmit & receive), master configuration, frame format is Motorola, polarity to 0 when idle, first clock is the first data capture edge, MSB transmit first, RX interrupt. Timer configure as one pulse mode.
void configPSC(TIMx *TIM,uint32_t intFreq,double period);
is to configure using internal frequency and desired period for each timer tick. For example, 0.001 is 1ms.
void configARR(TIMx *TIM,uint32_t ARR);
configure for ARR, how many tick before interrupt.
void sendData(SPIx *SPI,uint8_t data);
used by the state machine to send data to SPI buffer.
![](https://trello-attachments.s3.amazonaws.com/5e4279e34658360c891fb7ff/5e427a25210f643e75da9bf6/e9feb378efe764c2a87450d549c257a5/SPI_state_machine.png)
<h6>Figure 4: state machine
  
  
Slave used interrupt to wait and run according to commands, 0x23 for button command event, 0x45 for led command event. Master only using timer interrupt event to send command and shift data out from slave.
