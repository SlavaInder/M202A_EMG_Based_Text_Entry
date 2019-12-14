---
layout: page
title: Implementation
permalink: /implementation/
---

<html>
  <body>
    <h2>Application</h2>
        <p>In order to demonstrate the functionality of our gesture-recognition algorithm, we created an interactive application within Android Studios. This application has three activities with parent activity called MainMenu and child activities called Scan and Keyboard. Scan activity allows the user to establish Bluetooth Low Energy connection with Mypband device. Connection itself is supported by singleton object MyoBandDevice shared among all three activities. Keyboard activity sets Myo armband to correct mode using MyocommandList helper class and acquires EMG data from Myoband device. This data is processed using featureprocessor helper class and then classified. Output of  classification algorithm was stored in array of fixed length. When array is full and a new input comes in, the first element of the array is popped out and the new one is appended. If number of occurrences for some gesture exceeded threshold, we print a corresponding symbol. This is made to filter out noise, and threshold values were set individually for each gesture. The array was chosen to be 60 samples long, based on the tradeoff between typing speed and accuracy.</p>
    <h2>Performance evaluation<h2>    
    <p></p>
    

    <h1>Demonstration</h1>
      <center><iframe width="500" height="350" src="https://www.youtube.com/embed/cRu21NTDe1Y" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></center>
    <h3>Results</h3>
    <p>After training our artificial neural network, our evaluation of the model yielded strong results. The model was able to evaluate the 8 gestures at around a 90% mark. The accuracy reports can be seen below.</p>
  </body></html>

 The confusion matrix for our model also yielded strong results:
  ```
  [[1142    6   94    5   10    0    3    3]
  [   0  170    0    3    0   12    2    5]
  [  16    0  290    0    0    0    5    0]
  [   1    0    0  268    0    0    0   11]
  [  10    0    0    0  202    0    0    0]
  [   0   18    0    0    0  127    0    0]
  [   7    1    6    1    6    1   82    1]
  [   7    3    0   23    0    1    5  109]]
  ```
### Application 
The application for our interface was created through Android Studios. The classes vital to the integration process are listed below. For code involving Myo Armband connection or other aspects of our application, please visit our Github Repo. 
#### Weights and Latency
When translating real-time gesture predictions into user input, weights were attached to each class in order to normalize the output and make a robust interface. 

