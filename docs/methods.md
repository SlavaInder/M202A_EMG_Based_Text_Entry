---
layout: page
title: Methods
permalink: /methods/
---
<html>
  <style>
    * {
      box-sizing: border-box;
    }
  #center {
    display: block;
    margin-left: auto;
    margin-right: auto;
    width: 50%;
  }
  .column {
    float: left;
    width: 50%;
    padding: 5px;
  }
  table {
    border-collapse: collapse;
    width: 50%;
  }
  td, th {
    border: 1px solid #dddddd;
    text-align: left;
    padding: 8px;
  }

  tr:nth-child(even) {
    background-color: #dddddd;
  }
  .row::after {
    content: "";
    clear: both;
    display: table;
  }
  </style>
  <body>
    <h3>Hardware</h3>
    <p>To collect sEmg signals, we used a Myo Armband from Thalmic Labs (for elaborated discussion on this topic see <a href = "https://slavainder.github.io/M202A/previousworks/">Myo armband</a>). The Myo Armband provides 8 channels for sEMG recording with an 8-bit resolution and filtering was performed internally. It communicates with other devices via Bluetooth Low Energy. This interface provides 4 characteristics containing 2 sEMG recordings each. These characteristics were updated once per second.
      <br>
      For interfacing with Myo and performing real-time data processing and classification, we used <a href = "https://www.mi.com/my/redmi4x/">Xiaomi Redmi 4x</a>. The installed version of Android OS was 7.1.2.</p>
   <h3>Software</h3>
   <p>For all offline processing (cleaning, classification, feature extraction), Python 3.6 was used. ScyPy and Tensorflow 2 were used for data analysis and neural network training. Android Studios (Java) was used to implement the Android application. The TensorFlowLite package was used to provide support for a portable tflite classification format.
        <center><figure>
        <img src="https://www.researchgate.net/profile/Eduardo_Castello/publication/316538856/figure/fig9/AS:487955379822600@1493349036712/Myo-armband-by-Thalmic-Labs.png" style = "max-width:50%">
        <center><figcaption>Myo Armband Sensor</figcaption></center>
        </figure></center>
  </p>
    <h3>Gesture Set</h3>
    <p>Our design includes 2 types of gestures: finger taps (for letters A, S, D, F and whitespace, which are placed directly under the fingers when the hand is at rest) and finger extensions (for letters W, E, R and shift, which are pressed by stretching fingers). The amplitudes of the sEMG signals produced by these gestures are low, and we ensured that the hand was positioned comfortably and at rest throughout. Also, we ensured that during all experimentation the Myo Armband was placed at the same location (on the left hand, approximately 3 inches from the elbow) with the LED display facing towards the inner right arm.</p>
    <div class = "row">
      <div class = "column">
        <figure>
          <img id = "center" class="ll ng df t u hb ak hk" width="800" height="481" role="presentation" src="https://media.giphy.com/media/XI1G2dD3Ea6jLFLNSO/giphy.gif" style="width:250px;height:auto">
          <center><figcaption>Finger Tap</figcaption></center>
        </figure>
      </div>
      <div class = "column">
        <figure>
          <img id = "center" class="ll ng df t u hb ak hk" width="800" height="481" role="presentation" src="https://media.giphy.com/media/LOL3xcnZxHLyy6vwJA/giphy.gif" style="width:250px;height:auto">
          <center><figcaption>Finger Extension</figcaption></center>
        </figure>
      </div>
    </div>
    <figure>
      <img id = "center" src="https://www.typing.academy/app/source/public/images/intro/en/basic-position.png">
      <center><figcaption>Default Hand at Rest</figcaption></center>
    </figure>
    <h3>Datasets</h3>
    <p>Over the course of our project, we collected and sorted datasets totalling around 80,000 samples. This dataset can be accessed and downloaded from our Github repository at <a href="https://github.com/SlavaInder/M202A/tree/master/data">here</a>. This dataset is be divided into two parts: a training dataset and an evaluation dataset, both utilized with our neural network. Additionally, we did not utilize data that was found to be either too noisy or that did not integrate well into our interface. Our final dataset consists of 6 gestures plus the neutral position. All data is saved as *.txt files and separated into 4 groups: raw data, cleaned data, classified data, and features. </p>
    <h3>Features</h3>
    <p>To process data in real-time, we utilized a sliding window approach - that is we divided all our data into segments of a fixed size. A set of segments is combined to form a window and 6 time domain features were extracted from each window (6 features * 8 channels = 48 features). The sliding window is impemented such that the first segment is popped out of the window and another segment is added towards the end. For our design, this offset was a length of 10 ms. Features are extracted from this new window and the process is looped until the features in the final window are extracted. The features that we will observe are:
      <ul>
        <li>Mean average value (MAV): average of the absolute values of the sEMG amplitudes; characterizes muscle contraction levels</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/MAV.png"></center>
        <li>Root mean squared (RMS): mean power of the sEMG; characterizes the activity of the muscles</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/RMS.png"></center>
        <li>Slope sign change (SSC): number of times the slope sign changes within the current window; characterizes the frequency information of the sEMG signal</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/SSC.png"></center>
        <li>Waveform length (WL): total wavelength of the sEMG signal; characterizes signal complexity</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/WL.png"></center>
        <li>Activity Hjorth parameter (AHP): power spectrum of the frequency domain</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/AHP.png"></center>
        <li>Mobility Hjorth parameter (MHP): average frequency of the signal</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/MHP.png"></center>
      </ul></p>
    <h3>Code for Data Processing</h3>
      <p>Here we provide a code samples for the classes that we created to process our data.</p>
  </body></html>
  ```python
  # class allowing to delete or replace with reference noise parts of the signal 
  class emg_cleaner:
    # deletes "points" of points from the start 
    def delete_points_from_start(self, points)
    # deletes "points" of points from the end
    def delete_points_from_end(self, points)
    # adds "points" of points before the start; these points are copied from reference signal
    def add_points_to_start(self, points)
    # replaces points from point "start" to point "end" by reference signal
    def replace_points_in_middle(self, start, end):
    # adds "points" of points after the end; these points are copied from reference signal
    def add_points_to_end(self, points)
    # plots all 8 channels of the signal from x_segment[0] to x_segment[1] with resolution y_scale
    def mk_plots(self, x_segment, y_scale)
    # saves obtained file at "address"
    def save(self, address)
  ```
  ```python   
  # This class allows to classify file
  class class_editor:
      # this class sets assigns "class_name" class for all samples between edges[i][0], edges[i][1]
      def set_classification(self, edges, class_name)
      # plots all 8 channels of the signal from x_segment[0] to x_segment[1] with resolution y_scale
      def mk_plots(self, x_segment, y_scale)
      # saves obtained file at "address"
      def save(self, address)
  ```
  
  ```python
  # Extracts the features from the timestamped dataset from m_class_editor
  # This class allows to produce file output.csv file containing 7 features
  # for 8 channels of EMG signal with timestamps. Format of output data is
  #
  #   [[[MAV1,  [...,  [CHP1,      CLASS0,
  #      MAV1,   ...,   CHP1,      CLASS1,
  #      ...................,      ......,
  #      ...................,      ......,
  #      ...................,      ......,
  #      MAV1],  ...],  CHP1]],    CLASSN,
  class converter2:
    # this method extracts features from a dataset
    def process_file(self, custom_class = 1)
    # saves obtained file at "address"
    def save(self, address)
  
  ``` 
  <html>
  <p>Here we provide a table corresponding each gesture to their class label.</p> 
  <center><table>
    <tr>
      <th>Gesture</th>
      <th>Class</th>
    </tr>
    <tr>
      <td>No Movement</td>
      <td>0</td>
    </tr>
    <tr>
      <td>Index Finger Tap</td>
      <td>1</td>
    </tr>
    <tr>
      <td>Middle Finger Tap</td>
      <td>2</td>
    </tr>
    <tr>
      <td>Ring Finger Tap</td>
      <td>3</td>
    </tr>
    <tr>
      <td>Pinky Finger Tap</td>
      <td>4</td>
    </tr>
    <tr>
      <td>Index Finger Extension</td>
      <td>5</td>
    </tr>
    <tr>
      <td>Middle Finger Extension</td>
      <td>6</td>
    </tr>
    <tr>
      <td>Ring Finger Extension</td>
      <td>7</td>
    </tr>
    <tr>
      <td>Thumb Tap</td>
      <td>8</td>
    </tr>
    <tr>
      <td>Pinky Extension</td>
      <td>9</td>
    </tr>
    </table></center></html>

  <html>
    <body>
    <h3>Artifical Neural Network Architecture</h3>
    <p>Our model consists of 3 main layers: the input layer, the hidden layer, and the output layer. The input layer contains 48 nodes (consisting of the 48 total features: 8 channels, 6 features each), the hidden layer contains 24 nodes (half of the input layer), and the output layer contains 7 nodes, correlating to the total number of classified gestures. The number of nodes for the hidden layer were empirically determined given the size of our dataset and the number of input layers. Additionally, a sigmoid activation function was implemented to restrict the output of the inlaid transfer function to values between the range of 0 and 1. This range of values is then normalized through the softmax function of the output layer to create a set of probabilities of each class adding up to 1. This model demonstrated high accuracy and was chosen based upon the conclusions of outside research.</p>
    </body></html>
