---
layout: page
title: Future Direction
sidebar:
  nav: "docs"
permalink: /futuredirection/
---
In conclusion, we were able to develop an application that sets a basis for human-computer interaction utilizing the Myo Armband. Our design was able to translate 7 gestures into 9 outputs given the 'shift' functionality. Overall, typing with our interface was properly implemented with the inclusion of a 600 ms latency associated with our threshold operations.
### Strengths
#### 1) Demonstration of translating natural typing motions into an interface with sEMG
* Our design captures subtle finger movements via sEMG signal analysis. We were able to recognize these movements at a real-time rate with our algorithms and convert them into a set of input characters. While also providing a new platform for human-computer interaction with personal devices, the new interface can also be utilized to interact with IoT. Therefore, comfortable movements associated with keyboard input can be translated into a similar input platform performed both wirelessly and away from the keyboard.* 


#### 2) Mobility
*The interface that we created is highly mobile and requires a single Myo Armband to utilize. The absence of restrictive hardware, such as wires or additional sensors, allow for the convenience of an interactive environment with free-range.*


#### 3) Introduction of a new gesture set
*To the best of our knowledge, our implementation of these natural typing movements as a recognizable gesture set with the Myo Armband has not been explored within previous works given the same hardware. Neither previous papers nor the NinaPro DB5 contained the gestures we were able to recognize with our design.*
      
* * *
      
### Limitations
#### 1) Intermediate Gestures
*Unfortunately, our design did not account for the fact that our gestures produced additional intermediate gestures alongside the correct classification. For example, an index finger tap would not only produce index finger tap classifications, but also a variety of other finger taps as well. Additionally, with higher frequency devices, this stream of both correct and inccorect classifications will both increase. Therefore, it demonstrates an issue that will need to be resolved prior to the completion for this interface*
#### 2) The small and non-diverse dataset
*Although our design worked well amongst ourselves, we did not collect a holistically diverse dataset. The compiled data of two subjects will most likely be insufficient to translate the sEMG signals on a universal scale. There is an expectation that the features will vary between different individuals, and remains a potential source of unreliability given the relatively non-diverse set of sEMG signals.*
#### 3) Requirement of low muscle noise
*Within our design, there remains some difficulty differentiating the gestures when the user provokes the Myo Armband beyond the finger taps and subtle finger extensions associated with our gesture set. Due to the low sEMG signal amplitudes of these given gestures, additional muscle noise in the background will perturb the dataset and lead to incorrect classifications from our model.*
#### 4) Fixed Location of the Myo Armband
*The Myo Armband was maintained within the same location throughout both data collection and interface. Therefore, it was a stringent requirement that the Myo Armband needed to be placed precisely throughout.*
    
* * *
    <html>
  <body>
    <h3>Improvements to Future Iterations</h3>
    <p>
    <h4>1) Implementation of a filtering algorithm</h4>
    <i>By removing background noise from the datasets, our application could be implemented with more flexibility within a moer casual environment. This will solve the need for low muscle noise within our application and allow people to more comfortably utilize the interface in any environment.<br><br></i>
    <h4>2) Develop a position-independent recognition algorithm</h4>
    <i>Given more free-range to place the Myo Armband, there will be less reliance on the user's placement of the sensor. By removing this inconvenient requirement of our application, a position-independent recognition algorithm will make our interface much more user-friendly.<br><br></i>
    <h4>3) Test different neural network architectures</h4>
    <i>Based upon the works of other Myo Armband-related papers, there remains other neural network architectures that can be tested within our design. This could potentially provide a better classifier and improve any qualities our current model might lack, including an alleviation of an overfitting model.<br><br></i>
    <h4>4) Gather more datasets along with a larger pool of subjects</h4>
    <i>Within our design, the datasets were collected from only two participants. Due to our limited pool, our model was highly likely to overfit with our particular sEMG signals. Therefore, by collecting more overall datasets with more subjects, our interface can be utilized across a larger group of people. Additionally, our current dataset was seen to overfit with the keyboard surface as well. It would be ideal to gather multiple types of surfaces across a dataset which would lead to a more versatile model.<br><br></i>
    <h4>5) Utilize stronger sEMG signal collection hardware</h4>
    <i>Recently, a research group released a paper detailing their new sEMG armband that collects five times more samples per second than the Myo Armband. Along with additional quality tests, their armband was seen to be an overall better method of gathering sEMG signals. While it is not commercially available at the moment, it demonstrates the possibility of upcoming hardware that could outperform the Myo Armband and improve our own interface<br><br></i>
  </p>
  </body></html>
