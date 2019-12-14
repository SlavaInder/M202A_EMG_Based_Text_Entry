---
layout: page
title: Implementation
permalink: /implementation/
---

<html>
  <body>
    <h3>Application</h3>
        <p>In order to demonstrate the functionality of our gesture-recognition algorithm, we created an interactive application within Android Studios. This application has three activities: the parent activity "MainMenu" and child activities "Scan" and "Keyboard". The "Scan" activity allows the user to establish a Bluetooth Low Energy connection with the Myo Armband. The connection itself is supported by a singleton object called "MyoBandDevice" which is shared among all three activities. "Keyboard" activity sets the Myo Armband to the correct mode using the "MyocommandList" helper class and acquires sEMG signal information from the Myo Armband. This data is then processed using a "featureprocessor" helper class and is then classified. The output of the classification algorithm is stored in an array with a fixed length. When the array is filled up and a new input comes in, the first element of the array is popped out and the new input is appended. If the number of occurrences for some gesture exceeds the listed threshold, we print its corresponding symbol.  Each gesture was assigned its own threshold which was implemented to filter out noise. The array was chosen to contain a total of 60 samples based upon the tradeoff between typing speed and accuracy.</p>
    <h3>Performance evaluation</h3>    
    <p>Originally, our gesture set consisted of 9 gestures plus the neutral gesture. Although, the confusion matrix for this gesture set is up to our standards for integration, there were issues in regards to converting this accuracy into a real-time performance.<br> 
       <figure>
          <center><img id = "center" width="800" height="481" src="https://lh5.googleusercontent.com/Cn9PHvngl_Lu8kcibi3kCmw7eWgdb-qgsr2dqK4lcW4CyqGLhXD4zRyMw2gvuQvb6Ijui7arXoQZOWZCqygA_mnKX4PI0Eho9FwkB8JGpkNKGclFBvoxWLJGGNtYVmEhZ6dxcZiyhUc" style="width:550px;height:auto"></center>
          <center><figcaption>Original Gesture Set</figcaption></center>
        </figure><br>
      We noticed that the real-time interpretation for these gestures resulted in intermediate states that we did not initially account for. These intermediate states were easily confused with other gestures within our set and led to errs in classification. For example, an index finger extension might also ellicit multiple other gesture classifications. Therefore, it was difficult to properly distinguish the desired output from the real-time outputs of the classifier. In turn, a second gesture set was created using 5 finger taps and 1 finger extension. Within the confusion matrix of our final gesture set, there exists a relatively low value on 'D'. Due to our implementation of thresholds, this output did not pose a large threat to the stability of our model.<br>
      <figure>
          <center><img id = "center" width="800" height="481" src="https://scontent-lax3-1.xx.fbcdn.net/v/t1.15752-9/78785143_589167731857011_8276901187735781376_n.png?_nc_cat=105&_nc_ohc=HiyZDPvNN-gAQnKWT74IHK2T4ldSpnW186Xf8-n06bTB_q5I7FBIli07w&_nc_ht=scontent-lax3-1.xx&oh=3437efd26fd264f97e5b4b19dbb017a5&oe=5E829C70" style="width:550px;height:auto"></center>
          <center><figcaption>Finalized Gesture Set</figcaption></center>
        </figure>
    </p>
    <h3>Demonstration</h3>
      <center><iframe width="500" height="350" src="https://www.youtube.com/embed/cRu21NTDe1Y" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></center>
    <h3>Results</h3>
    <p>After training our artificial neural network, our evaluation of the model yielded strong results. The model was able to evaluate the 8 gestures at around a 90% mark. The accuracy reports can be seen below.</p>
  </body></html>
