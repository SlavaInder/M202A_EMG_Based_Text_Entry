// This code sends data from Arduino ADC-s in CSV format
// each analog read takes 112 mks
// each cycle of the i-loop takes 280 mks
// full cycle takes 925 mks => frequency is 1 kHz

void setup() {
  // init Serial to work on max speed
  Serial.begin(115200);
}

void loop() {
  // init necessary variables
  int a[6];
  int i;

  // get data from sensors
  a[0] = analogRead(A0);
  a[1] = analogRead(A1);
  a[2] = analogRead(A2);
  a[3] = analogRead(A3);
  a[4] = analogRead(A4);
  a[5] = analogRead(A5);

  // print them to the serial port
  for (i = 0; i < 6; i++) {
    Serial.print(a[i]);
    Serial.write(";");
  }
}
