---
layout: page
title: Implementation
permalink: /implementation/
---

<html>
  <body>
    <p>In order to demonstrate the functionality of our gesture-recognition algorithm, we created an interactive application within Android Studios. The goal of the application would be to cover all the bases for typical human-computer interaction such as typing and cursor control.</p>
    <h3>Results</h3>
    <p>After training our artificial neural network, our evaluation of the model yielded strong results. The model was able to evaluate the 8 gestures at around a 90% mark. The accuracy reports can be seen below.</p>
  </body></html>
  ```
  Train on 23048 samples, validate on 2656 samples
  Epoch 1/10
  23048/23048 [==============================] - 1s 47us/sample - loss: 0.3597 - accuracy: 0.8740 - val_loss: 0.2761 - val_accuracy: 0.8919
  Epoch 2/10
  23048/23048 [==============================] - 1s 33us/sample - loss: 0.2309 - accuracy: 0.9101 - val_loss: 0.2425 - val_accuracy: 0.9059
  Epoch 3/10
  23048/23048 [==============================] - 1s 34us/sample - loss: 0.2191 - accuracy: 0.9174 - val_loss: 0.2546 - val_accuracy: 0.9044
  Epoch 4/10
  23048/23048 [==============================] - 1s 34us/sample - loss: 0.2199 - accuracy: 0.9171 - val_loss: 0.2327 - val_accuracy: 0.9160
  Epoch 5/10
  23048/23048 [==============================] - 1s 37us/sample - loss: 0.2212 - accuracy: 0.9171 - val_loss: 0.2415 - val_accuracy: 0.9115
  Epoch 6/10
  23048/23048 [==============================] - 1s 38us/sample - loss: 0.2071 - accuracy: 0.9223 - val_loss: 0.2565 - val_accuracy: 0.9044
  Epoch 7/10
  23048/23048 [==============================] - 1s 37us/sample - loss: 0.2069 - accuracy: 0.9222 - val_loss: 0.2114 - val_accuracy: 0.9059
  Epoch 8/10
  23048/23048 [==============================] - 1s 33us/sample - loss: 0.2044 - accuracy: 0.9226 - val_loss: 0.2523 - val_accuracy: 0.9104
  Epoch 9/10
  23048/23048 [==============================] - 1s 35us/sample - loss: 0.2086 - accuracy: 0.9209 - val_loss: 0.2560 - val_accuracy: 0.9051
  Epoch 10/10
  23048/23048 [==============================] - 1s 33us/sample - loss: 0.2198 - accuracy: 0.9167 - val_loss: 0.2511 - val_accuracy: 0.8998
  ```
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
The application for our interface was created through Android Studios.

``` java
public static void main(String args[])
```

*** LIST OUT ALL OF THE JAVA CLASSES/ACTIVITES AND DESCRIBE
