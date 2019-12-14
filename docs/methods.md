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
    <p>To collect sEmg sygnals, we used a Myo Armband from Thalmic Labs (for elaborated discussion on this topic see <a href = "https://slavainder.github.io/M202A/previousworks/">Myo armband</a>). The Myo Armband provides 8 channels for sEMG recording with an 8-bit resolution and filtering done internally. It communicates with other devices via Bluetooth Low Energy interface. This interface provides 4 characteristics containing 2 sEMG recordings each. These characteristics were updated once per second.
      <br>
      For interfacing with Myo and performing real-time data processing and classification, we used <a href = "https://www.mi.com/my/redmi4x/">Xiaomi Redmi 4x</a>. The istalled version of Android OS was 7.1.2.</p>
   <h3>Software</h3>
   <p>For all offline processing (cleaning, classification, feature extraction), Python 3.6 was used. ScyPy and Tensorflow 2 were used for data analysis and NN training. Android Studios (Java) was used to implement the Android application. The TensorFlowLite package was used to provide support for a portable tflite classification format.
        <center><figure>
        <img src="/pictures/Myo-armband-by-Thalmic-Labs.png" style = "max-width:70%">
        <center><figcaption>Myo Armband Sensors</figcaption></center>
        </figure></center>
  </p>
    <h3>Gesture Set</h3>
    <p>Our design includes 2 types of gestures: finger taps (for letters A, S, D, F and whitespace, which are placed directly under the fingers when the hand is at rest) and finger extensions (for letters W, E, R and shift, which are pressed by stretching fingers). Amplitude of sEMG signal produced by these gestures in the forearm is low, and we ensured that the hand is positioned comfortably and rests throughout all of the experiment. Also, we ensured that during all of the experiments Myo Armband was placed at the same place (on the left hand, approximately 3 inches from the elbow with the LED display facing towards the inner right arm) </p>
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
    <p>Over the course of our project, we collected and sorted the dataset of almost 80,000 samples. This dataset can and downloaded from our Github repo at <a href="https://github.com/SlavaInder/M202A/tree/master/data">here</a>. This dataset is be divided into two parts - one is the data we used to train Neural Network for final version of our implementation, and the other is data we experimented with but did not include in final version. This "discarded" data was found to be either too noisy or from the gestures we did not included in final version. Final dataset consists of 6 gestures plus neutral position. All data is saved as *.txt files and separated in groups: raw data, cleaned data, classified data, features. </p>
    <h3>Features</h3>
    <p>To process data in real-time, we use sliding window approach - that is we divide all our data in segments of fixed size. A set of segments is combined into a window, and 6 time domain features are extracted from the window (so, overall there is 48 features for 8 channels). Then first segment is popped out of the window and new one is added in the and. Features are extracted again and this process runs in a loop until last window is processed. The features that we use include:
      <ul>
        <li>Mean average value (MAV): average of the absolute values of the sEMG amplitudes and characterizes muscle contraction level</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/MAV.png"></center>
        <li>Root mean squared (RMS): mean power of the sEMG and characterizes the activity of the muscles</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/RMS.png"></center>
        <li>Slope sign change (SSC): number of times the slope sign changes within the current window and characterizes the frequency information of the sEMG signal</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/SSC.png"></center>
        <li>Waveform length (WL): total wavelength of the sEMG signal and characterizes signal complexity</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/WL.png"></center>
        <li>Activity Hjorth parameter (AHP): power spectrum of the frequency domain</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/AHP.png"></center>
        <li>Mobility Hjorth parameter (MHP): average frequency of the signal</li>
        <center><img src = "https://raw.githubusercontent.com/SlavaInder/M202A/master/docs/misc/MHP.png"></center>
      </ul></p>
    <h3>Code for data processing</h3>
      <p>Here we provide interface for classes that we created to process data.</p>
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
  <html><body>
  <h3>Classification</h3>
  <p>After cleaning and removing noise from the dataset (mainly in the resting portions), the signals were classified. By implementing the add/delete points methods of the emg_cleaner class, we were able to create standardized datasets with reliable timestamps which were then labelled accordingly. The code samples below come from the m_class_editor class.</p></body></html>
  ```python   
  def set_classification(self, edges, class_name):
    self.classification = [0 for i in range(len(self.timeline))]
    self.classplot = [-50 for i in range(len(self.timeline))]
    for i in range(len(edges)):
        for j in range(edges[i][0], edges[i][1] + 1):
            self.classification[j] = class_name
            if class_name == 0: self.classplot[j] = -50
            else: self.classplot[j] = 50
            
  # m_class_editor = class_editor(frequency, filenames)
  m_class_editor = class_editor(200, "myo_emg_export_1574646877163.txt", "myo_emg_export_1574646877133.txt")
  m_class_editor.process_all_files()
  ```
  <html>
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
      <td>Thumb Tap</td>
      <td>5</td>
    </tr>
    <tr>
      <td>Ring Finger Extension</td>
      <td>6</td>
    </tr>
    </table></center>
  <h3>Feature Extraction</h3>
  <p>The cleaned and classified datasets are now ready for feature extraction. The feature extraction is done with a sliding window of length 200 ms and an offset of 10 ms. The code samples below come from the m_converter class.</p></html>
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
  
  # This function takes the window and calculates the Activity Hjorth Parameter for the window
  def get_MHP(self, w):
    # AHP w/ s
    sum1 = 0
    for x in range(0, len(w)):
        sum1 = sum1 + w[x]**2
    # AHP w/ s'
    sum2 = 0
    for x in range(0, len(w)-1):
        sum2 = sum2 + (w[x+1] - w[x])**2
    return (sum2/sum1)**(0.5)
  # m_converter = converter(l, L, frequency, Gesture_Class, filenames)
  # l = number of samples per segment
  # L = number of segments per window
  m_converter = converter(2, 40, 200, 5, "emgset0")
  m_converter.process_all_files()
  ```
  <html>
    <body>
    <h3>Artifical Neural Network Architecture</h3>
    <p>Our model consists of 3 main layers: the input layer, the hidden layer, and the output layer. The input layer contains 48 nodes (consisting of the 48 total features: 8 channels, 6 features each), the hidden layer contains 24 nodes (half of the input layer), and the output layer contains 7 nodes, correlating to the total number of classified gestures. The number of nodes for the hidden layer were empirically determined given the size of our dataset and the number of input layers. Additionally, a sigmoid activation function was implemented to restrict the output of the inlaid transfer function to values between the range of 0 and 1. This range of values is then normalized through the softmax function of the output layer to create a set of probabilities of each class adding up to 1. This model demonstrated high accuracy and was chosen based upon the conclusions of outside research.</p>
    <h3>ANN Model Code Samples</h3>
    <p>After training and evaluation, our model was able to demonstrate an accuracy of approximately 90% with the 8 different classes. The code samples below demonstrate how we trained and evaluted our model.</p>
    </body></html>
  ```python
  # init and compile NN network
  model = tf.keras.Sequential()
  model.add(layers.Dense(56))
  model.add(layers.Dense(28, activation='sigmoid'))
  model.add(layers.Dense(8, activation='softmax'))
  model.compile(optimizer=tf.keras.optimizers.Adam(0.01),
                loss='categorical_crossentropy',
                metrics=['accuracy'])
                
  # load data
  data = mvectors_producer.training_array
  labels = mvectors_producer.training_labels
  val_data = mvectors_producer.validation_array
  val_labels = mvectors_producer.validation_labels

  # train NN network
  model.fit(data, labels, epochs=10, batch_size=32,
            validation_data=(val_data, val_labels))
  ```
