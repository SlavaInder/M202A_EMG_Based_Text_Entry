---
layout: page
title: Methods & Results
sidebar: contrib_sidebar
permalink: /methodsandresults/
---
<html>
  <style>
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
  </style>
  <body>
    <h3>Materials</h3>
    <p>The only hardware that was utilized within our research was a commercially available Myo Armband for surface EMG signal extraction. The Myo Armband consisted of 8 channels, 3 large segments and 5 small segments, to gather the sEMG data from two subjects. The raw data recieved from the Myo Armband will be normalized into a range of -127 to 128.<br>Software platforms include: 
      <ul>
        <li>Python: signal cleaning, window sampling, and feature extracting</li>
        <li>TensorFlow: creating and training our model; TensorFlowLite version was implemented into our application</li>
        <li>Android Studios: creating an application for translating sEMG signal data extraction into user interface.</li>           </ul>
    <h3>Gesture Set</h3>
    <p>For the purposes of our design, we will have two groups of gestures: whole-hand gestures and single-finger gestures. Since the novelty of our design lies within the differentiation of the single-finger gestures, we will be focusing on the classification of 6 single-finger gestures on the left arm. These include an index finger tap, middle finger tap, ring finger tap, pinky finger tap, thumb tap, and middle finger extension. A tap is determined by only vertical change of a finger. An extension is determined by both vertical and horizontal change of a finger.</p>
    <div class = "column">
      <figure>
        <img src="https://ak1.picdn.net/shutterstock/videos/13097291/thumb/3.jpg" style="width:100%">
        <center><figcaption>Finger Tap</figcaption></center>
      </figure>
    </div>
    <div class = "column">
      <figure>
        <img src="misc/fingerextension.jpg" style="width:100%">
        <center><figcaption>Finger Extension</figcaption></center>
      </figure>
    </div>
    <figure>
      <img id = "center" src="https://www.typing.academy/app/source/public/images/intro/en/basic-position.png">
      <center><figcaption>Default Hand at Rest</figcaption></center>
    </figure>
    <h3>Datasets</h3>
    <p>The complete dataset for our project can be found on our GitHub repo or click <a href="">here</a> to download. The dataset contains the 6 total gestures with 30 total samples each. Additionally, we have added whole-hand gestures corresponding to a hand (palm down) moving left, right, up and down for our own purposes of testing our design functionality. The dataset contains both the raw, normalized EMG values from the Myo Armband and their corresponding time-domain features.</p>
    <h3>Features</h3>
    <p>There will be 6 total features extracted from each window of each channel. Therefore, there will be 48 total features being extracted from each dataset via sliding window. The features include:
      <ul>
        <li>Mean average value (MAV): average of the absolute values of the sEMG amplitudes and characterizes muscle contraction level
        <br><center><math style="font-family:stix" xmlns="http://www.w3.org/1998/Math/MathML"><mstyle mathsize="22px"><mrow><mo>[</mo><mi>M</mi><mi>A</mi><mi>V</mi><mo>]</mo><mo>&#xA0;</mo><mo>=</mo><mo>&#xA0;</mo><mfrac><mn>1</mn><mi>N</mi></mfrac><munderover><mo>&#x2211;</mo><mrow><mi>k</mi><mo>=</mo><mn>1</mn></mrow><mi>N</mi></munderover><mo>&#xA0;</mo><mo>|</mo><mo>&#x2009;</mo><mi>s</mi><mo>(</mo><mi>k</mi><mo>)</mo><mo>|</mo></mrow></mstyle></math></center>
        <li>Root mean squared (RMS): mean power of the sEMG and characterizes the activity of the muscles
        <li>Slope sign change (SSC): number of times the slope sign changes within the current window and characterizes the frequency information of the sEMG signal
        <li>Waveform length (WL): total wavelength of the sEMG signal and characterizes signal complexity
        <li>Activity Hjorth parameter (AHP): power spectrum of the frequency domain
        <li>Mobility Hjorth parameter (MHP): average frequency of the signal
      </ul>
    <h3>PipeLine</h3>
      <h4>Cleaning</h4>
      <p>In order to  create a more reliable dataset, each dataset was plotted, then manually combed and processed. The code samples below come from the emg_cleaner class to create a stronger dataset.</p>
  </body></html>
  ```python
  class emg_cleaner:
    noise = []
 
  def delete_points_from_start(self, points):
    for i in range(points):
        for j in range(len(self.emg_channels)):
            self.emg_channels[j].pop(0)                
    self.timeline = [i for i in range(len(self.timeline) - points)]
  
  def delete_points_from_end(self, points):
    for i in range(points):
        for j in range(len(self.emg_channels)):
            self.emg_channels[j].pop()
    self.timeline = [i for i in range(len(self.timeline) - points)]
    
  def add_points_to_start(self, points):
    random_start = randint(0, len(emg_cleaner.noise[0]) - 1 - points)
    for i in range(points):
        for j in range(len(self.emg_channels)):
            self.emg_channels[j].insert(i, emg_cleaner.noise[j][random_start+i])
    self.timeline = [i for i in range(len(self.timeline) + points)]

  def replace_points_in_middle(self, start, end):
    random_start = randint(0, len(emg_cleaner.noise[0]) - 2 - end + start)
    for i in range(start, end + 1):
        for j in range(len(self.emg_channels)):

            self.emg_channels[j][i] = emg_cleaner.noise[j][random_start+i]
            
  def add_points_to_end(self, points):
    random_start = randint(0, len(emg_cleaner.noise[0]) - 1 - points)
    for i in range(points):
        for j in range(len(self.emg_channels)):
            self.emg_channels[j].append(emg_cleaner.noise[j][random_start+i])
    self.timeline = [i for i in range(len(self.timeline) + points)]
  ```
  <html>
  <h3>Classification</h3>
  <p>After cleaning and removing noise from the dataset (mainly in the resting portions), the signals were classified. By implementing the add/delete points methods of the emg_cleaner class, we were able to create standardized datasets with reliable timestamps which were then labelled accordingly. The code samples below come from the m_class_editor class.</p>
  </html>
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
  <h4>Classification Table</h4>
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
  <p>The cleaned and classified datasets are now ready for feature extraction. The feature extraction is done with a sliding window moving per 10 ms along the dataset. The code samples below come from the m_converter class.</p>
  </html>
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
    </body>
  </html>  
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
