---
layout: post
title: "Research Paper Summaries"
author: "Michael Kim and Viacheslav Inderiakin"
---
<html>
  <body>
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
      <li><u>Hardware</u>:                Standard Bipolar Electrodes</li>
      <li><u>Number of Subjects</u>:      2 participants</li>
      <li><u>Gesture Set</u>:             Roll, Pitch, Yaw, Twirl</li>
      <li><u>Time Domain Features</u>:    RMS, WL, ZC</li>
      <li><u>Time Window Length</u>:      200 ms</li>
      <li><u>NN Architecture</u>:         Random forests regression</li>
    </ul>
    <h4><i>Machine Learning Algorithms for Characterization of EMG Signals (2014)</i></h4>
    <ul>
      <li><u>Hardware</u>:                Standard Bipolar Electrodes</li>
      <li><u>Number of Subjects</u>:      1 participant</li>
      <li><u>Gesture Set</u>:             Wrist flexors and wrist extensors</li>
      <li><u>Time Domain Features</u>:    WPT, WT, AR-X, FFT, etc.</li>
      <li><u>NN Architecture</u>:         NNC, LDA, KNN, etc.</li>
    </ul>
    <h4><i>Simultaneous sEMG Classification of Hand/Wrist Gestures and Forces (2019)</i></h4>
    <ul>
      <li><u>Hardware</u>:                CyberGlove and Standard Bipolar Electrodes</li>
      <li><u>Number of Subjects</u>:      31 participants</li>
      <li><u>Gesture Set</u>:             7 whole-hand gestures (including pointing index finger and pinch)</li>
      <li><u>Time Domain Features</u>:    MAV, RMS, WL, SSC, Variance</li>
      <li><u>Time Window Length</u>:      150 ms w/ 100 ms overlap</li>
      <li><u>NN Architecture</u>:         LDA and Non-Linear Logistic Regression (NLR)</li>
      <li><u>Side</u>:                    Smallest margin of error (~10%) when differentiating a set of wrist gestures and a pinch at different levels of intensity with NLR</li>
    </ul>
    <h4><i>Deep Learning for Electromyographic Hand Gesture Signal Classification Using Transfer Learning (2019)</i></h4>
    <ul>
      <li><u>Hardware</u>:                Myo Armband</li>
      <li><u>Number of Subjects</u>:      19 participants/ 17 participants</li>
      <li><u>Gesture Set</u>:             Wrist Flexions and Hand Opened/Closed</li>
      <li><u>Time Domain Features</u>:    MAV, SSC, WL, ZC</li>
      <li><u>Time Window Length</u>:      260 ms</li>
      <li><u>NN Architecture</u>:         CNN</li>
    </ul>
    <h4><i>Inferring Static Hand Poses from a Low-Cost Non-Intrusive sEMG Sensor (2019)</i></h4>
    <ul>
      <li><u>Hardware</u>:                Myo Armband</li>
      <li><u>Number of Subjects</u>:      35 participants</li>
      <li><u>Gesture Set</u>:             Wrist Flexion, Opened/Closed Hand, Victory Sign, and Two-finger Tap</li>
      <li><u>Time Domain Features</u>:    None (Raw input)</li>
      <li><u>Time Window Length</u>:      188 ms w/ 20 ms offset</li>
      <li><u>NN Architecture</u>:         GRU</li>
    </ul>
    <h4><i>An Recognition–Verification Mechanism for Real-Time Chinese Sign Language Recognition Based on Multi-Information Fusion (2019)</i></h4>
    <ul>
      <li><u>Hardware</u>:                Myo Armband</li>
      <li><u>Number of Subjects</u>:      20 participants</li>
      <li><u>Gesture Set</u>:             Sign Language (consisting of both hand and arm motions)</li>
      <li><u>Time Domain Features</u>:    RMS, ZC, ARC, FFT, PSD, WT</li>
      <li><u>Time Window Length</u>:      128 ms</li>
      <li><u>NN Architecture</u>:         CNN based on VGG architecture</li>
      <li><u>Side</u>:                    The accelerometer and the gyroscope of the Myo Armband were utilized in order to track the motion of the arm (some SL gestures require both arms and wide movements)</li>
    </ul>
    </p></body></html>
