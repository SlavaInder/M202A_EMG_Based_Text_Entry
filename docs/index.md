---
#
# By default, content added below the "---" mark will appear in the home page
# between the top bar and the list of recent posts.
# To change the home page layout, edit the _layouts/home.html file.
layout: home
---

<html>
  <body>  
    <h1>Our Mission</h1>
    <p>Our goal is to create a multi-use application via EMG-sensors to simplify the process of everyday tasks. Imagine controlling your TV, projector, computer, or even mobile device simply by moving your hands! This is the aim of our project and through the recognition of gestures and movement, we look to accomplish this goal and set a new standard of innovation!<br><br>Goals of the Product:<br>1) Differentiate between a total of 8 EMG signals<br>2) Properly integrate machine learning algorithm, differentiation, and external output</p>
    <h1>About</h1>
    <p>The most recent wave of technology has been revolved around the concept of automation and improving quality of life. Neural networks and machine learning models have paved the pathway for such innovations and have allowed for smarter and more reliable applications. We decided to implement a machine learning model to the discontinued Myo Armband to bring back the product with a more modern application. The Myo Armband utilizes 8 channels to gather electromyography (EMG) signals from the mid-arm and transfers the data via Bluetooth. There have been many research papers performed around dissimilar gesture recognition from the Myo Armband, and more recently, experiments have attempted to implement a real-time feature to the product through neural networks. The novelty behind our own design is the inclusion of single-finger gestures in the gesture-recognition algorithm at a real-time rate. The goal of our design is to implement single-finger and whole-hand gesture recognition to demonstrate user expression within personal devices. Key features to fully demonstrate user expression include the ease of typing and basic click/pointer events such as the click of a cursor.</p>
    <h1>Overall Project Goal</h1>
    <p>Create a gesture recognition algorithm for purposes of interfacing EMG sensors with personal devices</p>
    <h1>Specific Aims</h1>
    <p><ul>
      <li>Propose a specific set of gestures to recognize based on trade-offs between accuracy and ease</li>
      <li>Develop feature extraction algorithm and neural network implementation</li>
      <li>Demonstrate translation of gesture recognition algorithm via Android application</li>
    </ul></p>
    <h1>Implications and Today's Status</h1>
    <p>Currently, there are no products that can adequately translate mimimal human motion into specific actions without environment-specific equipment or inefficient amounts of interactive hardware. Currently, the Tap Strap is the only commercially available product that is able to read single-finger gestures, but it requires the usage of 5 accelerometers attached to each finger. The expectation of this project is to demonstrate the capability of utilizing one Myo Armband to distinctively evaluate single-finger gestures at a real-time speed. This will allow for a new method of human interaction with personal devices, increasing the accessibility and efficiency of daily tasks.</p>
    <h1>Our Approach</h1>
    <p>In order to fulfill the aim of our project, we look to gather multiple EMG signals derived from the human hand and differentiate the multiple readings at real-time speeds. The implementation of machine learning algorithms will be vital in obtaining the results we desire. The consistency and workability of our initial model will then be rounded out through a series of tests and observations to create an improved final product.</p>
    
    <h1>Our Research</h1>
    <p>Surface electromyography signals (sEMG) can be monitored on many parts of the body, but for the purposes of our project, we will be focusing on the wrist area. In total, we aim to differentiate between the 8 sEMG signals that can be gathered from the wrist. The machine learning algorithm that will be mainly explored is the Linear Discriminant Analysis (LDA) in conjunction with wavelet packet transform (WPT) which have been observed to differentiate the most signals through EMG analysis.</p>

    <h1>Deliverables</h1>
    <p><ul>
      <li>Training set of data gathered from EMG sygnals</li>
      <li>Recognition algorithm and its implementation</li>
    </ul></p>

  <h1>Our Timeline</h1>
  <table>
    <tr>
      <th>time period</th>
      <th>task</th>
    </tr>
    
    <tr>
      <td>10/20/2019 - 10/25/2019 </td>
      <td>Create a detailed timeline and work breakdown for the project within the upcoming weeks</td>
    </tr>
  
    <tr>
      <td>10/26/2019 - 10/30/2019</td>
      <td>Dive into the literature to understand more about the required code and algorithm</td>
    </tr>
    
    <tr>
      <td>10/31/2019 - 11/06/2019</td>
      <td>Set up and test available equipment. Gather initial set of data</td>
    </tr>
    
    <tr>
      <td>11/07/2019 - 11/17/2019</td>
      <td>Make a prototype of recognition algorithm and its implementation</td>
    </tr>
    
    <tr>
      <td>11/18/2019 - 11/22/2019</td>
      <td>Detailed presentation of progress and results </td>
    </tr>
    
    <tr>
      <td>11/23/2019 - 11/22/2019</td>
      <td>Finalize the design; collect final set of data; fix arised issues. Measure percetage of right recognitions and latency.</td>
    </tr>
  </table>
 
 
  <h1>Work Breakdown</h1>
  <table>
  
    <tr>
      <th>Viacheslav Inderiakin</th>
      <th>Michael Kim</th>
    </tr>
  
    <tr>
      <td><ul>
          <li>Literature review on acquiring, filtering EMG signal and extracting valuable features from it;</li>
          <li>Configurating and testing hardware;</li>
          <li>EMG-signal data gathering and preprocessing;</li>
          <li>Integrating with external output;</li>
      </ul></td>
      <td><ul>
          <li>Literature review on Machine Learning algorithms for online pattern recognition;</li>
          <li>Creating a skeleton of algorithm's implementation;</li>
          <li>Testing algorithm performance on samples;</li>
          <li>Website updates and support;</li>
      </ul></td>
    </tr>
  </table>  
    
<p>Both Members will</p>
<ul>
  <li>Debug the fully assembled system (hardware + software</li>
  <li>Contribute to final report and presentations</li>
</ul>
      
  
  <h1>Methodology</h1>
  <p>Step 1: Reading through literatures on the topic and finding starting point based upon previous experiments
    <br>Step 2: Understanding algorithm and differentiation patterns
    <br>Step 3: Research/Observations with MyoBand<br>Step 4: Complete PCB and rough draft of code
    <br>Step 5: Create prototype of product
    <ul>
      <li>Test with multiple subjects and determine accuracy of the gesture differentiation between each individual's input; multiple trials of each gesture</li>
      <li>Determine delay with EMG differentiation</li>
      <li>If needed, test accuracy of other algorithmic models with samples to determine best fit interpretation</li>
    </ul>
    Step 6: Integrate with external monitor
    <ul>
      <li>Determine delay with integration</li>
      <li>Test application with same subjects</li>
    </ul>
    Step 7: Analysis of product
    <ul>
      <li>Success metrics:</li>
      <ol>
        <li>Less than 0.1 second delay</li>
        <li>>90% accuracy</li>
        <li>Typing and functions properly executed</li>
        <li>Reasonable speed of input</li>
      </ol>
    </ul>
  </p>
  
  <center><img src="ExampleTable1.png" alt="Example Table"/></center><p><center>Example table for analyzing the results from testing</center></p>
        
  <h1>References</h1>
  <p><ul>
    <li>"EMG Based Decoding of Object Motion in Dexterous, In-Hand Manipulation Tasks" by A. Dwivedi, Y. Kwon, et. al. 
      <br/>https://www.newdexterity.org/2018_BioRob_EMGDexterousManipulation.pdf</li>
    <li>"Real-Time Surface EMG Pattern Recognition for Hand Gestures Based on an Artificial Neural Network" by Z.  Zhang, K. Yang, et. al.
      <br/>https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6679304/</li>
    <li>"Machine Learning Algorithms for Characterization of EMG Signals" by Bekir Karlik , et. al.
      <br>http://www.ijiee.org/papers/433-S3002.pdf</li>
    <li>"Simultaneous sEMG Classification of Hand/Wrist Gestures and Forces" by Francesca Leone, et. al.
      <br>https://www.ncbi.nlm.nih.gov/pmc/articles/PMC6593108/</li>
  </ul></p>
  
  </body>
</html>
