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
  </style>
  <body>
    <h3>Method</h3>
    <p>There have been many previous designs revolved around determining the best machine learning model to predict gestures from sEMG signal analysis. The many different models and algorithms included: GRU,</p>
    <h3>Gesture Set</h3>
    <p>For the purposes of our design, we will have two groups of gestures: whole-hand gestures and single-finger gestures. Since the novelty of our design lies within the differentiation of the single-finger gestures, we will be focusing on the classification of 7 single-finger gestures on the left arm.</p>
    <figure>
      <img id = "center" src="https://www.typing.academy/app/source/public/images/intro/en/basic-position.png">
      <center><figcaption><a href="https://www.typing.academy/app/source/public/images/intro/en/basic-position.png"> Img Source</a></figcaption></center>
    </figure>
    <h3>Datasets</h3>
    <p>The complete dataset for our project can be found on our GitHub repo or click here to download!</p>
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
  <p>After cleaning and removing noise from the data (mainly in the resting portions), the datasets were classified. The code samples below come from the m_class_editor class.</p>
  </html>
  ```python
  # Creates a new file with marked times based on frequency
  # m_class_editor = class_editor(frequency, filenames)
  m_class_editor = class_editor(200, "myo_emg_export_1574646877163.txt", "myo_emg_export_1574646877133.txt")
  m_class_editor.process_all_files()
  ```
  <html>
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
  # m_converter = converter(l, L, frequency, Gesture_Class, filenames)
  # l = number of samples per segment
  # L = number of segments per window
  m_converter = converter(2, 40, 200, 5, "emgset0")
  m_converter.process_all_files()
  ```
  <html>
    <body>
    <h3>Artifical Neural Network Architecture</h3>
    <p>Our model consists of 3 layers: the input layer, the hidden layer, and the output layer. The input layer contains 48 nodes (consisting of the 48 total features: 8 channels, 6 features each), the hidden layer contains 24 nodes (half of the input layer), and the output layer contains 15 nodes, correlating to the total number of gestures being classified including when the hand is at rest. The hidden layer consisted of a sigmoid activation function which worked in conjunction with the softmax layer. The sigmoid activation function works to restrict the output of the inlaid transfer function to values between the range of 0 and 1. This range of values is then normalized through the softmax function of the output layer to create a set of probabilities of each class adding up to 1.</p>
    <h3>ANN Model Code Samples</h3>
    <p></p>
    </body>
</html>
