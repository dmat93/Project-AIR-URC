# Arduino-IR-examples

_I would provide some example of code useful to interacts with IR Tx/Rx module using Arduino IDE._


## Setup

### Devices
In my case I've used some low-cost component that you can easily find on the web. I bought them on [AliExpress](https://best.aliexpress.com)

 - [IR transmitter](https://www.aliexpress.com/item/Free-Shipping-electronic-building-blocks-infrared-transmitter-module-IR-Transmitter-for-arduino/1972261135.html?spm=2114.search0104.3.8.912f5ac1FZRiFU&ws_ab_test=searchweb0_0,searchweb201602_3_10152_10151_10065_10344_10068_10342_10325_10343_10546_10340_10548_10341_10696_10084_10083_10618_10304_10307_5711211_10313_10059_10184_10534_100031_10103_10624_10623_443_10622_10621_10620_10811,searchweb201603_1,ppcSwitch_5&algo_expid=8f9b5a27-1a42-4be6-a34b-22f3c90e50c1-1&algo_pvid=8f9b5a27-1a42-4be6-a34b-22f3c90e50c1&transAbTest=ae803_5&priceBeautifyAB=0)  
  - [IR Receiver](https://www.aliexpress.com/item/3pin-KY-022-TL1838-VS1838B-1838-Universal-IR-Infrared-Sensor-Receiver-Module-for-Arduino-Diy-Starter/32776965303.html?spm=2114.10010108.1000023.13.5e5f568drk0WGU)
  - [Arduino Nano Clone CH340G](https://www.aliexpress.com/item/Freeshipping-1pcs-lot-Nano-3-0-controller-compatible-for-arduino-nano-CH340-USB-driver-NO-CABLE/32804787481.html?spm=2114.search0104.3.8.1ac82b20lJuM33&ws_ab_test=searchweb0_0,searchweb201602_3_10152_10151_10065_10344_10068_10342_10325_10343_10546_10340_10548_10341_10696_10084_10083_10618_10304_10307_5711215_10313_10059_10184_10534_100031_10103_10624_10623_443_10622_10621_10620_10811-10620,searchweb201603_1,ppcSwitch_5&algo_expid=81f49d39-7c1a-4acc-b954-d63d0d0fd424-0&algo_pvid=81f49d39-7c1a-4acc-b954-d63d0d0fd424&transAbTest=ae803_5&priceBeautifyAB=0)  
	- This clone can be a pain in your ass
	
Obviously you are not forced to use my same configuration, many other guides suggest to use single diodes as Tx and Rx instead modules.



### Connections
![Arduino-IR Connections](/media/scheme.jpg)  



## Code

Let's refer to the project you can find in _projects/_ 

##### Initialization of the recevier:  
`IRrecv irrecv(RECV_PIN)`  

##### Initialization of the sender:  
`IRsend irsend`  

##### Store the decoded results:  
`decode_results results`  

_Optionaly we can store more signals, according to each button of a remote control for example, and then we can send different signal pushing different buttons._

##### Get the value of the decoded signal
`results.value [unsigned long]`  

##### Get the number of bits of the decoded signal
`results.bit [int]`  

##### Send the received signal using value and number of bits
`irsend.send(results.value,32);`

_We can store the number of bit of the recevied signal into a variable and then we can use it to send the signal_

#### Consideration
##### Send function
`IRsend.send(unsigned long data, int n_bits)`

##### Decode funtion
`IRrecv.decode(&decode_results results)`

## Applications

 - Remote Controller

## Improvements

 - Store more decoded signals
 - Assign a button to a signal
 - Integration of display
 - (...)

[mattiaquadrini@gmail.com](mailto:mattiaquadrini@gmail.com)