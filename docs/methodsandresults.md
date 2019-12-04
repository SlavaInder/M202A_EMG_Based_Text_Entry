---
layout: page
title: Methods & Results
permalink: /methodsandresults/
---
<html>
  <body>
    <h3>Method</h3>
    <p>There have been many previous designs revolved around determining the best machine learning model to predict gestures from sEMG signal analysis. The many different models and algorithms included: GRU,</p>
    <h3>Gesture Set</h3>
    <p></p>
    <h3>Datasets</h3>
    <p></p>
    <h3>Algorithms</h3>
    <p></p>
    <h3>Feature Extraction Code Samples</h3>
    <p></p>
    <h3>Artifical Neural Network Architecture</h3>
    <p>Our model consists of 3 layers: the input layer, the hidden layer, and the output layer. The input layer consisted of 48 nodes (consisting of the 48 total features: 8 channels, 6 features each), the hidden layer consisted of 24 nodes (half of the input layer), and the output layer consisted of 15 nodes, correlating to the total number of gestures being classified including when the hand is at rest. The hidden layer consisted of a sigmoid activation function which worked in conjunction with the softmax layer. The sigmoid activation function works to restrict the output of the inlaid transfer function to values between the range of 0 and 1. This range of values is then normalized through the softmax function of the output layer to create a set of probabilities of each class adding up to 1.</p>
    <h3>ANN Model Code Samples</h3>
    <p></p>
    </body>
</html>
