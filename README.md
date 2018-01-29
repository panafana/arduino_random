# arduino_random
True Random Number Generator on Arduino

Using xorshift* function with 32bit integer values produces random numbers and uses seed from sensors and micros() function.
The use of sensor values as seed is done by xoring all the values you want to add to the seed into one variable and then feeding it into the function.
The function works as described in wiki:
https://en.wikipedia.org/wiki/Xorshift#xorshift*

Vastly superior performance compared to the default random() function.


*the use of 32bit integers is in place because it allows them to overflow in short terms and this adds to the randomness of the function but it can also work well enough with bigger inegeres
*the sensors used in our example circuit where: photoresistor with randomized led array (to improve given values) , sound sensor and a free cable connected to an analog input that senses random noise (common practice for arduino random() ).
