// This code checks latency of analog reads.
// Latency is found to be 112 mks, frequency - 8900 Hz

void setup() {
  // init Serial to work on max speed
  Serial.begin(115200);
}

void loop() {
  int a;
  int i;
  unsigned long out;
  unsigned long t1, t2;

  // time 10^4 reads
  t1 = micros();
  for (i = 0; i < 10000; i++) {
    a = analogRead(A1);
  }
  t2 = micros();

  // calculate time for single operation
  out = (t2 - t1) / 10000;
  Serial.print(out);
  Serial.write("\n");
}
