---
layout: page
title: Prior Works
permalink: /previousworks/
---
<html>
  <body>
    <h3>Discussion</h3>
    <h4>Myo Armband</h4>
    <p>In order to gather sEMG signals and create an interactive-safe environment, we decided to utilize the Myo Armband for purposes of data collection and interface. What the Myo Armband shows for in mobility, it lacks in accuracy. For comparison, traditional methods of sEMG signal collection samples between 500 - 1000 Hz while the Myo Armband samples at 200 Hz. Therefore, while convenient for our design, the Myo Armband can be considered an area of improvement. Recently, a research paper released a comparison of their 3D printed sEMG armband with the Myo Armband and was able to demonstrate significant improvement, especially in terms of frequency, sampling at 1000 samples per second. While the said paper’s sEMG armband is not commercially available, it demonstrates the capabilities of improving mobile sEMG collection methods. </p>
    <h4>Neural Network Architecture</h4>
      <p>More recently, research on the Myo Armband has revolved around determining the best-fit neural network to recognize gestures at a real-time rate from sEMG signal analysis. The many different models and algorithms include: gated recurrent unit (GRU), stacked sparse auto encoders (SSAE), latent Dirichlet allocation (LDA), and convolutional and artificial neural networks (CNN and ANN). These papers manipulated many factors to determine the performances of each model given unique parameters; more specifically, they focused on making changes to attributes within the training set. The performances between unsupervised vs supervised sets and different time vs frequency features were explored. Given the results of these projects,  models such as LDA and SSAE were not considered within our own neural network design. The networks that demonstrated the strongest classifications across these papers were CNNs and ANNs. Common characteristics of these models included batch normalization layers, a rectified linear unit activation function (ReLu), a sigmoid activation function, and a softmax activation function. Each of these models were able to perform at >95% accuracy when classifying dissimilar large sEMG signal gestures. While CNNs demonstrated strong performances with unsupervised datasets, for the purposes of our project, we decided upon an ANN with 6 time-domain features. </p>
    <h4>Gesture Set</h4>
      <p>All previous designs consistently looked to differentiate from, essentially, the same gesture set. The main gestures include iterations of wrist flexion (waves), multiple finger taps, closed hand, and open hand.
      <center><figure>
          <img class = "size" src="https://miro.medium.com/max/2604/1*9uvS5j1EZXdQuIoqyb5syA.jpeg" style="max-width:50%;">
          <center><figcaption>An example gesture set of a Myo Armband-based paper</figcaption></center>
      </figure></center>
      The overlying theme across all these gesture sets is the requirement of every finger to stimulate muscle activity. Whether a finger is voluntarily curled, straightened, or flexed, it produces a noticeable change within the sEMG signal. Therefore, these gestures can be considered dissimilar and more easily differentiable. Additionally, the NinaPro EMG Database (DB5) is considered the benchmark for Myo Armband sEMG signal analysis/collection. It was captured through 2 Myo Armbands and a CyberGlove. Despite this standard, the database did not contain the gesture set we aim to differentiate. While it contained finger adductions, flexions, and extensions, it did not contain finger taps nor subtle finger extensions.<br>
To the best of our knowledge, our gesture set was not covered in any relevant literatures on the Myo Armband. These gestures are much more difficult to identify due to the lack of overall signal strength and activity. We want to emulate typing movements; therefore, our gesture set was defined by the standard motions involved when typing on a QWERTY keyboard. Additionally, since there are no previous works involving the recognition of these gestures, the method of handling and sampling these single-finger gestures were all unique to our design.</p>
  </body>
</html>
