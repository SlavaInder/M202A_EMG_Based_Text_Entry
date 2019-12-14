---
layout: page
title: About
permalink: /about/
---

<html>
  <body>
    <p>Electromyogram, or EMG, is an electrical signal produced through the contraction of muscle cells. Surface EMGs, or sEMGs, are EMG signals gathered specifically from the skin. Currently, there are a variety of devices that can capture this signal. Unfortunately, there exists flaws associated with each form of sEMG signal collection. Traditional methods of sEMG signal collection employ an excessive amount of electrodes (wires) and require special preparation to operate. This makes it too cumbersome to setup and use on a daily basis while also inhibiting the goals of an interactive environment. On the other hand, portable devices like the Myo Armband, while less accurate, are much more convenient to use. Regardless, they lack popularity with the general public and have yet to find a place in human-computer interaction. One of the reasons is that the number of gestures that can be reliably recognized by this hardware remains limited. Our work aims to build upon that and propose a real-time classification algorithm on a novel gesture set.</p>
      <h3>Specific Aims</h3>
      <p><ul>
        <li>Propose a specific set of gestures to recognize based on trade-offs between accuracy and ease</li>
        <li>Develop a feature extraction algorithm and implement neural network for gesture recognition</li>
        <li>Demonstrate translation of our gesture recognition algorithm via Android application</li>
      </ul></p>
      <h3>Implications and Today's Status</h3>
      <p>Currently, there are no products that can adequately translate mimimal human motion into specific actions without environment-specific equipment or inefficient amounts of interactive hardware. Currently, the Tap Strap is the only commercially available product that is able to read our gesture set, but it requires the usage of 5 accelerometers attached to each finger. The expectation of this project is to demonstrate the capability of utilizing one Myo Armband to distinctively evaluate subtle single-finger gestures at a real-time speed. This will lay the basis of an new framework for human interaction with personal devices and IoT.</p>
      <!--<center><figure>
          <img class = "size" src="https://cnet1.cbsistatic.com/img/00XQEmFzx7Xio51Kw8V0E4zo_oE=/2017/11/21/b97d2dc7-e471-47b8-a2e0-9091b2d26bcd/fl-tapkeyboard-cnetstill.jpg" style="max-width:50%;">
          <center><figcaption>The Tap Strap translates the change in accelerometer readings to user input</figcaption></center>-->
        </figure></center>
  <h3>Novelty</h3>
  <p>Since the Myo Armband's release, there have not been iterations of Myo Armband-based applications involving the interpretation of single-finger gestures. Due to high similarities in sEMG signal output (especially with a commercially available product like the Myo Armband), these gestures become difficult for a neural network to distinguish. Our robust methods of cleaning and classifying allow for strong feature-extracted datasets that ultimately lead to a strong classifier to differentiate between these single-finger gestures. The ability to recognize subtle human movements can then be translated into a platform for human-computer interaction with personal devices and IoT. Traditional methods of gathering sEMG data required inconvenient amounts of hardware, making any form of interaction unfeasible. The ability to recognize and register natural typing movements with the low-budget and mobile Myo Armband brings sEMG signal analysis into greater perspective.</p>
  </body>
</html>
