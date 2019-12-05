---
layout: page
title: Future Direction
sidebar:
  nav: "docs"
permalink: /futuredirection/
---
<html>
  <body>
    <p>The ability to recognize single-finger gestures will allow for a new method of interaction between people and their personal devices, and this demonstrates great significance especially considering the new wave of technology that is IoT. Given additional time to develop, our design can be fully functional across both hands and across the spectrum for device input. This looks to include all characters on the keyboard and more robust control of these miscellaneous devices. The greatest features of our model include the ease of access and the novelty of our gesture set. The </p>
    <h2>Limitations</h2>
    <p>Overall, our project demonstrated the capabilities of a feature-extraction algorithm to distinguish single-finger gestures. Nevertheless, there remains a few limitations to the design that we present.<br>
    <h3>1) There exists ambiguity when attempting to distinguish additional single-finger gestures within the same hand</h3>
      <i>A solution to this limitation would be to extract additional time-domain features. There remains a handful of features that we came across, but did not implement due to their complexity such as (ironically) the complexity Hjorth parameter (CHP). By adding more features, we allow for more potential markers to distinguish these subtle and similar movements with higher accuracy and among a larger pool of labels.</i><br><br>
    <h3>2) The small and non-diverse dataset</h3>
      <i>Although our design worked well amongst ourselves, we did not collect a holistically diverse dataset. The compiled data of two subjects will most likely be insufficient to translate the sEMG signals on a universal scale. There is not an expectation that the features will vary greatly between different individuals, but remains a source of unreliability given the relatively small nature of sEMG signals.</i><br><br>
    <h3>3) The impact of miscellaneous movement</h3>
      <i>As stated earlier, the data was cleaned and classified prior to feature extraction and model training. The pre-processed data was to make the model as accurate as possible given the user remains at rest. The concept, however, extends beyond a defined resting state. Within our design, there remains some difficulty differentiating the gestures when the user provokes the Myo Armband beyond the single-finger or whole-hand movements. This can be alleviated by collecting much more data to help the model separate these actions. </i>
    </p>
  </body></html>
