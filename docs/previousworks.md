---
layout: page
title: Prior Works
permalink: /previousworks/
---
<html>
  <body>
    <h3>Discussion</h3>
    <h4>Neural Network Architecture</h4>
      <p>There have been many previous designs revolved around determining the best machine learning model to predict gestures from sEMG signal analysis. The many different models and algorithms include: gated recurrent unit (GRU), stacked sparse auto encoders (SSAE), latent Dirichlet allocation (LDA), convolutional neural networks (CNN), and artificial neural networks (ANN). Based upon these documented results, we concluded that the best model for our system would be a supervised ANN with a time-domain feature extracted dataset. The proposed ANN would consist of a single main hidden layer and a total of 6 features will be extracted from all 8 channels of each EMG dataset. Given a strong dataset, the ANN will be able to predict and differentiate between the different gestures prior to gesture completion, demonstrating real-time signal interpretation.</p>
    <h4>Gesture Set</h4>
      <p>All previous designs consistently looked to differentiate from, essentially, the same gesture set. The main gestures include iterations of wrist flexion (waves), multiple finger taps, closed hand, and open hand.
      <center><figure>
          <img class = "size" src="https://miro.medium.com/max/2604/1*9uvS5j1EZXdQuIoqyb5syA.jpeg" style="max-width:50%;">
          <center><figcaption>An example gesture set of a Myo Armband-based paper</figcaption></center>
      </figure></center>
      The overlying theme across all these gesture sets is the requirement of every finger to stimulate muscle activity. Whether a finger is voluntarily curled, straightened, or flexed, it produces a noticeable change within the sEMG signal. Therefore, these gestures can be considered dissimilar and more easily differentiable. Single-finger gestures, however, were not covered in any relevant literatures on the Myo Armband. These gestures are much more difficult to identify due to the lack of overall signal strength and activity. We want to emulate typing movements; therefore, our gesture set was defined by the standard motions involved when typing on a QWERTY keyboard. Additionally, since there are no previous works involving the recognition of these gestures, the method of handling and sampling these single-finger gestures were all unique to our design.</p>
    <h4>Interface</h4>
    <p>Interfacing between the Myo Armband and personal devices have traditionally revolved around the implementation of whole-hand gestures. This can be difficult considering the unnatural and slow-paced nature of performing these sets.
      <br>The video below demonstrates an example of a previous design for EMG-based typing:
      <center><iframe width="560" height="315" src="https://www.youtube.com/embed/w5zwfulRW9o" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></center>
      <br>The image below demonstrates an EMG-based cursor:<br><br>
      <center><img class="ll ng df t u hb ak hk" width="800" height="481" role="presentation" src="https://miro.medium.com/max/800/0*zlXqfPArv3Ok2c0n.gif" style="width:500px;height:auto"></center><br>
      By creating a design revolved around user experience, our application translates natural typing motion into input with a single Myo Armband. This application can then be further improved upon to create a fully functional interface with personal devices and IoT without the restrictions of a mouse or keyboard.</p>
    <h3>Main Research Papers</h3>
    <h4><i>Multiday EMG Classification of Hand Motions with Deep Learning Techniques</i></h4>
    <p>The experiment detailed within this paper looks to determine what neural network would be best suited for EMG predictions for the purposes of real-time simulation. There were seven total subjects and each of their data were independently processed using four methods of machine learning: linear determinant analysis (LDA) with handcrafted features, unsupervised stacked sparse auto encoders (SSAE), SSAE with handcrafted features, and an unsupervised convolutional neural network (CNN). The data was filtered using a third order Butterworth high-pass filter and a sliding window was implemented to account for the time domain features: mean average value (MAV), waveform length (WL), slope-sign change (SSC), and zero-change (ZC). Data was collected over a course of 15 days with four different sets of data: within-session, between-session, between pairs of days, and leave-one-out between days. Ultimately, the research concluded that the unsupervised CNN with 3 layers (input, hidden, and output with fully connected (FC) layers and a softmax) produced much more precise and accurate results in comparison to the other algorithms; the SSAE with handcrafted features produced the next best results. Therefore, within our model, we decided to implement a similar model of CNN with the addition of the handcrafted time-domain features</p>
    <h4><i>Real-Time Surface EMG Pattern Recognition for Hand Gestures Based on an Artificial Neural Networks</i></h4>
    <p>The main goal of this paper was to implement a neural network to demonstrate a real-time sEMG signal analysis that attempts to recognize a gesture prior to completion. Although similar to the goal in the previous literature, this design utilized a feed-forward artificial neural network (ANN) along with 7 time-domain handcrafted features to attempt EMG gesture prediction. The 7 features included MAV, WL, SSC, root mean squared (RMS), Activity Hjorth Parameter (AHP), Mobility Hjorth Parameter (MHP), and Complexity Hjorth Parameter (CHP). Five dissimilar gestures consisting of whole-hand movements were predicted at a 98.7% accuracy. The paper also delves into the implementation of other iterations of neural network models (unsupervised models, SVM, LDA, etc.) and concludes that the ANN was the best-fit model for real-time EMG processing. Our model was closely aligned to the one presented due to its high mark of accuracy and overall relevancy with the conclusions described in other works.</p>
    <h4><i>Comparison of six electromyography acquisition setups on hand movement classification tasks</i></h4>
    <p>This paper explains the basis for the benchmark Myo Armband EMG datasets from the NinaPro EMG Database. The main premise was to classify multiple methods of EMG signal extraction with systems ranging from a few hundred dollars to several thousands of dollars. The NinaPro Database is considered the benchmark for EMG signal analysis and has been highly impactful in the understanding of muscle activity within the arm. Within this large EMG database, there exists the NinaPro Database 5, which was collected via Myo Armbands. This database includes EMG signal activity for a large set of gestures, including both single-finger and whole-hand gestures. Although this dataset consists of multiple single-finger gestures, these were gathered using two Myo Armbands and a CyberGlove with 22 points of haptic feedback. Our single-finger gesture design remains unique in comparison to this paper due to the sizable difference in both equipment and application.</p>
    <h3>Other Related Papers</h3>
    <p>
    <h4><i>EMG Based Decoding of Object Motion in Dexterous, In-Hand Manipulation Tasks (2018)</i></h4>
    <ul>
      <li>Hardware: Standard Bipolar Electrodes</li>
      <li>Number of Subjects: 2 male</li>
      <li>Gesture Set: Roll, Pitch, Yaw, Twirl</li>
      <li>Time Domain Features: RMS, WL, ZC</li>
      <li>Time Window Length: 200 ms</li>
      <li>NN Architecture: Random forests regression</li>
    </ul>
    <h4><i>Machine Learning Algorithms for Characterization of EMG Signals (2014)</i></h4>
    <ul>
      <li>Hardware: Standard Bipolar Electrodes</li>
      <li>Number of Subjects: 1</li>
      <li>Gesture Set: Wrist flexors and wrist extensors</li>
      <li>Time Domain Features: WPT, WT, AR-X, FFT, etc.</li>
      <li>NN Architecture: NNC, LDA, KNN, etc.</li>
    </ul>
    <h4><i>Simultaneous sEMG Classification of Hand/Wrist Gestures and Forces (2019)</i></h4>
    <ul>
      <li>Hardware: CyberGlove and Standard Bipolar Electrodes</li>
      <li>Number of Subjects: 31 participants</li>
      <li>Gesture Set: 7 whole-hand gestures (including pointing index finer)</li>
      <li>Time Domain Features: MAV, RMS, WL, SSC, Variance</li>
      <li>Time Window Length: 150 ms w/ 100 ms overlap</li>
      <li>NN Architecture: LDA and Non-Linear Logistic Regression (NLR)</li>
      <li>Side: Smallest margin of error (~10%) when differentiating a set of wrist gestures and a pinch at different levels of intensity with NLR</li>
    </ul>
    <h4><i>Deep Learning for Electromyographic Hand Gesture Signal Classification Using Transfer Learning (2019)</i></h4>
    <ul>
      <li>Hardware: Myo Armband</li>
      <li>Number of Subjects: 19 participants for first dataset, 17 participants for second dataset</li>
      <li>Gesture Set: Wrist Flexions and Hand Opened/Closed</li>
      <li>Time Domain Features: MAV, SSC, WL, ZC</li>
      <li>Time Window Length: 260 ms</li>
      <li>NN Architecture: CNN</li>
    </ul>
    <h4><i>Inferring Static Hand Poses from a Low-Cost Non-Intrusive sEMG Sensor (2019)</i></h4>
    <ul>
      <li>Hardware: Myo Armband</li>
      <li>Number of Subjects: 35 participants</li>
      <li>Gesture Set: Wrist Flexion, Opened/Closed Hand, Victory Sign, and Two-finger Tap</li>
      <li>Time Domain Features: None (Raw input)</li>
      <li>Time Window Length: 188 ms w/ 20 ms offset</li>
      <li>NN Architecture: GRU</li>
    </ul>
    </p>
  </body>
</html>
