---
layout: page
title: Work Breakdown
permalink: /workbreakdown/
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
    <div class = "row">
      <div class = "column">
         <center><h3>Michael</h3></center>
          <ul>
            <li>Literature Review</li>
              <li>EMG Data Collection</li>
              <li>Dataset Compilation</li> 
              <li>Feature Extraction Code</li>
              <li>ANN Training/Evaluating</li>
              <li>Website/Presentations</li> 
              <li>Documentation</li>
           </ul>
      </div>
      <div class = "column">
         <center><h3>Viacheslav</h3></center>
        <ul>
          <li>Literature Review</li>
            <li>EMG Cleaning</li>
            <li>EMG Data Collection</li>
            <li>Dataset Compilation</li> 
            <li>Feature Extraction Code</li>
            <li>ANN Training/Evaluating</li> 
            <li>Android Application</li>
           </ul>
      </div>
    </div>
     <h2>Our Timeline</h2>
  <table style="width:100%">
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
    <h1>Methodology Overview</h1>
  <p>Step 1: Reading through literatures on the topic
    <br>Step 2: Understanding algorithm and differentiation patterns
    <br>Step 3: Creating Application to connect to MyoBand
    <br>Step 4: Research/Observations with MyoBand
    <br>Step 5: Clean, classify, and extract features from dataset
    <br>Step 5: Create prototype of product
    <ul>
      <li>Test and determine accuracy of the gesture differentiation; multiple trials of each gesture</li>
      <li>Determine delay with EMG differentiation</li>
      <li>If needed, test accuracy of other algorithmic models with samples to determine best interpretation</li>
    </ul>
    Step 6: Integrate with application
    <ul>
      <li>Determine delay with integration</li>
      <li>Determine weights for each gesture</li>
    </ul>
    Step 7: Analysis of product
    <ul>
      <li>Success metrics:</li>
      <ol>
        <li>Less than 0.1 second delay</li>
        <li>>85% accuracy</li>
        <li>Typing and functions properly executed</li>
        <li>Reasonable speed of input</li>
      </ol>
    </ul></p>
  </body></html>
