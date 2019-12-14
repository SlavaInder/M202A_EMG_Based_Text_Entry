---
layout: page
title: Implementation
permalink: /implementation/
---

<html>
  <body>
    <p>In order to demonstrate the functionality of our gesture-recognition algorithm, we created an interactive application within Android Studios. The goal of the application would be to cover all the bases for typical human-computer interaction such as typing and cursor control.</p>
    <h1>Demonstration</h1>
      <center><iframe width="500" height="350" src="https://www.youtube.com/embed/cRu21NTDe1Y" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe></center>
    <h3>Results</h3>
    <p>After training our artificial neural network, our evaluation of the model yielded strong results. The model was able to evaluate the 8 gestures at around a 90% mark. The accuracy reports can be seen below.</p>
  </body></html>
  ```
  Train on 23048 samples, validate on 2656 samples
  Epoch 1/10
  23048/23048 [==============================] - 1s 47us/sample - loss: 0.3597 - accuracy: 0.8740 - val_loss: 0.2761 - val_accuracy: 0.8919
  Epoch 2/10
  23048/23048 [==============================] - 1s 33us/sample - loss: 0.2309 - accuracy: 0.9101 - val_loss: 0.2425 - val_accuracy: 0.9059
  Epoch 3/10
  23048/23048 [==============================] - 1s 34us/sample - loss: 0.2191 - accuracy: 0.9174 - val_loss: 0.2546 - val_accuracy: 0.9044
  Epoch 4/10
  23048/23048 [==============================] - 1s 34us/sample - loss: 0.2199 - accuracy: 0.9171 - val_loss: 0.2327 - val_accuracy: 0.9160
  Epoch 5/10
  23048/23048 [==============================] - 1s 37us/sample - loss: 0.2212 - accuracy: 0.9171 - val_loss: 0.2415 - val_accuracy: 0.9115
  Epoch 6/10
  23048/23048 [==============================] - 1s 38us/sample - loss: 0.2071 - accuracy: 0.9223 - val_loss: 0.2565 - val_accuracy: 0.9044
  Epoch 7/10
  23048/23048 [==============================] - 1s 37us/sample - loss: 0.2069 - accuracy: 0.9222 - val_loss: 0.2114 - val_accuracy: 0.9059
  Epoch 8/10
  23048/23048 [==============================] - 1s 33us/sample - loss: 0.2044 - accuracy: 0.9226 - val_loss: 0.2523 - val_accuracy: 0.9104
  Epoch 9/10
  23048/23048 [==============================] - 1s 35us/sample - loss: 0.2086 - accuracy: 0.9209 - val_loss: 0.2560 - val_accuracy: 0.9051
  Epoch 10/10
  23048/23048 [==============================] - 1s 33us/sample - loss: 0.2198 - accuracy: 0.9167 - val_loss: 0.2511 - val_accuracy: 0.8998
  ```
 The confusion matrix for our model also yielded strong results:
  ```
  [[1142    6   94    5   10    0    3    3]
  [   0  170    0    3    0   12    2    5]
  [  16    0  290    0    0    0    5    0]
  [   1    0    0  268    0    0    0   11]
  [  10    0    0    0  202    0    0    0]
  [   0   18    0    0    0  127    0    0]
  [   7    1    6    1    6    1   82    1]
  [   7    3    0   23    0    1    5  109]]
  ```
### Application 
The application for our interface was created through Android Studios. The classes vital to the integration process are listed below. For code involving Myo Armband connection or other aspects of our application, please visit our Github Repo. 
#### Weights and Latency
When translating real-time gesture predictions into user input, weights were attached to each class in order to normalize the output and make a robust interface. 
#### AndroidManifest.xml
``` HTML
<?xml version="1.0" encoding="utf-8"?>
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.example.myo_keyboard">

    <uses-permission android:name="android.permission.BLUETOOTH" />
    <uses-permission android:name="android.permission.BLUETOOTH_ADMIN" />
    <uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" />

    <uses-feature
        android:name="android.hardware.bluetooth_le"
        android:required="true" />

    <application
        android:allowBackup="true"
        android:icon="@mipmap/ic_launcher"
        android:label="@string/app_name"
        android:roundIcon="@mipmap/ic_launcher_round"
        android:supportsRtl="true"
        android:theme="@style/AppTheme">
        <activity android:name=".Keyboard"
                  android:parentActivityName=".MainMenu"></activity>
        <activity
            android:name=".Scan"
            android:parentActivityName=".MainMenu"></activity>
        <activity android:name=".MainMenu">
            <intent-filter>
                <action android:name="android.intent.action.MAIN" />

                <category android:name="android.intent.category.LAUNCHER" />
            </intent-filter>
        </activity>
    </application>

</manifest>
```
#### FeatureProcessor.java
The class below is instantiated in order to extract the 6 time-domain features from the incoming sEMG dataset from the Myo Armband.
``` java
public class FeatureProcessor {
    public static float[] get_features(int[][] window) {
        // init array of features
        float[] features = new float[56];
        // init normalized window
        float[][] normalized_window = new float[8][80];

        // normalize data
        for (int i=0; i<8; i++) {
            for (int j=0; j<80; j++) {
                normalized_window[i][j] = (float) window[i][j] / 128;
            }
        }

        // get features
        float[] MAVs = get_MAVs(normalized_window);
        float[] RMSs = get_RMSs(normalized_window);
        float[] SSCs = get_SSCs(normalized_window);
        float[] WLs = get_WLs(normalized_window);
        float[] AHPs = get_AHPs(normalized_window);
        float[] MHPs = get_MHPs(normalized_window);


        // pack features
        for (int i=0; i<8; i++) {
            features[i * 7] = MAVs[i];
            features[1 + i * 7] = RMSs[i];
            features[2 + i * 7] = SSCs[i];
            features[3 + i * 7] = WLs[i];
            features[4 + i * 7] = AHPs[i];
            features[5 + i * 7] = MHPs[i];
        }

        return features;
    }


    public static float[] get_MAVs(float[][] window) {
        float[] MAVs = new float[8];

        for (int i=0; i<8; i++) {
            for (int j=0; j<80; j++) {
                MAVs[i] = MAVs[i] + window[i][j];
            }
            MAVs[i] = MAVs[i] / 80;
        }

        return MAVs;
    }


    public static float[] get_RMSs(float[][] window) {
        float[] RMSs = new float[8];

        for (int i=0; i<8; i++) {
            for (int j=0; j<80; j++) {
                RMSs[i] = RMSs[i] + window[i][j] * window[i][j];
            }
            RMSs[i] = (float) sqrt(RMSs[i] / 80);
        }

        return RMSs;
    }


    public static float[] get_SSCs(float[][] window) {
        float[] SSCs = new float[8];

        for (int i=0; i<8; i++) {
            for (int j=1; j<79; j++) {
                SSCs[i] = SSCs[i] + abs((window[i][j] - window[i][j-1]) * (window[i][j] - window[i][j+1]));
            }
        }

        return SSCs;
    }


    public static float[] get_WLs(float[][] window) {
        float[] WLs = new float[8];

        for (int i=0; i<8; i++) {
            for (int j=1; j<80; j++) {
                WLs[i] = WLs[i] + abs(window[i][j] - window[i][j-1]);
            }
        }

        return WLs;
    }


    public static float[] get_AHPs(float[][] window) {
        float[] AHPs = new float[8];

        for (int i=0; i<8; i++) {
            for (int j=0; j<80; j++) {
                AHPs[i] = AHPs[i] + window[i][j] * window[i][j];
            }
            AHPs[i] = AHPs[i] / 79;
        }

        return AHPs;
    }


    public static float[] get_MHPs(float[][] window) {
        float[] MHPs = new float[8];
        float[] temps = new float[8];

        for (int i=0; i<8; i++) {
            for (int j=0; j<79; j++) {
                MHPs[i] = MHPs[i] + (window[i][j+1] - window[i][j]) * (window[i][j+1] - window[i][j]);
            }
        }

        for (int i=0; i<8; i++) {
            for (int j=0; j<80; j++) {
                temps[i] = temps[i] + window[i][j] * window[i][j];
            }
        }

        for (int i=0; i<8;i++) {
            MHPs[i] = (float) sqrt(MHPs[i]/temps[i]);
        }

        return MHPs;
    }
}
```
#### Keyboard.java
The class below demonstrates the integration of the neural network model and the application. The incoming data from the Myo Armband goes through FeatureProcessor.get_features. The time-domain features of the sEMG signal stream is then predicted through our TensorFlowLite ANN model. The weights are applied and a decision on the incoming gesture is made. The prediction then outputs the corresponding character to the user interface.
``` java
/* ====================================== EMG Handler ====================================== */
@Override
public void OnReportEmg(int[][] channels) {

    // put your code here
    for (int i = 0; i < 8; i++) {
        // shift array on 1 segment
        for (int j = 0; j < 78; j++) {
            mwindow[i][j] = mwindow[i][j+2];
        }
        // add new elements from bluetooth
        mwindow[i][78] = channels[0][i];
        mwindow[i][79] = channels[1][i];
    }

    // get features from current window
    inputval = FeatureProcessor.get_features(mwindow);

    // pop up the earliest prediction
    prediction_values[predictions_order[0]] = prediction_values[predictions_order[0]] - 1;

    // shift order of predictions
    for (int i=0; i<MEAN_LEN - 1; i++) {
        predictions_order[i] = predictions_order[i+1];
    }

    // get new prediction
    predictions_order[MEAN_LEN-1] = doInference();
    prediction_values[predictions_order[MEAN_LEN-1]] = prediction_values[predictions_order[MEAN_LEN-1]] + 1;

    // make a decision
    decision = 0;
    for (int i=1; i<5; i++) {
        if ((i == 1) && (prediction_values[i] > MEAN_LEN *5/8)) {
            decision = i;
        }
        if ((i == 2) && (prediction_values[i] > MEAN_LEN *4/8)) {
            decision = i;
        }
        if ((i > 2) && (prediction_values[i] > MEAN_LEN * 3/4)) {
            decision = i;
        }
    }

    long current_time = System.currentTimeMillis();

    // update ui if necessary
    if ((decision > 0) && (current_time - prev_decision_time > TIME_CONST)) {
        prev_decision_time = current_time;
        uiHandler.sendEmptyMessage(decision);
    } else {
        uiHandler.sendEmptyMessage(0);
    }
}

/* ====================================== Ui  Handler ====================================== */

private class UiHandler extends Handler {
    private boolean isUpdating = false;
    private void startUpdate() {
        isUpdating = true;
    }
    private void stopUpdate() {
        isUpdating = false;
    }

    @Override
    public void handleMessage(Message msg) {
        super.handleMessage(msg);
        ClassNumberView.setText(Integer.toString(decision));

        if (msg.what > 0) {
            String current_text = TextEntryView.getText().toString();
            int current_selector = TextEntryView.getSelectionEnd();
            TextEntryView.setText(current_text.substring(0, current_selector) +  symbols.substring(msg.what, msg.what + 1) + current_text.substring(current_selector, current_text.length()));
            TextEntryView.setSelection(current_selector + 1);
        }
    }
}
```
