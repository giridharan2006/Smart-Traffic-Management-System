#define L1_R 12
#define L1_G 14

#define L2_R 25
#define L2_G 27

int lane1 = 0, lane2 = 0;
int lastWinner = -1;

void setup() {
  Serial.begin(115200);

  pinMode(L1_R, OUTPUT);
  pinMode(L1_G, OUTPUT);
  pinMode(L2_R, OUTPUT);
  pinMode(L2_G, OUTPUT);

  // initial state
  digitalWrite(L1_R, HIGH);
  digitalWrite(L2_R, HIGH);
}

void allRed() {
  digitalWrite(L1_R, HIGH);
  digitalWrite(L2_R, HIGH);
  digitalWrite(L1_G, LOW);
  digitalWrite(L2_G, LOW);
}

void lane1Green(int duration) {
  digitalWrite(L1_G, HIGH);
  digitalWrite(L1_R, LOW);
  digitalWrite(L2_R, HIGH);
  digitalWrite(L2_G, LOW);

  delay(duration);

  allRed();
  delay(2000);
}

void lane2Green(int duration) {
  digitalWrite(L2_G, HIGH);
  digitalWrite(L2_R, LOW);
  digitalWrite(L1_R, HIGH);
  digitalWrite(L1_G, LOW);

  delay(duration);

  allRed();
  delay(2000);
}

void loop() {

  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');

    int commaIndex = data.indexOf(',');
    if (commaIndex > 0) {
      lane1 = data.substring(0, commaIndex).toInt();
      lane2 = data.substring(commaIndex + 1).toInt();

      Serial.print("Received: ");
      Serial.print(lane1);
      Serial.print(",");
      Serial.println(lane2);

      int baseTime = 60000;
      int buffer = 20000;

      if (lane1 > lane2) {
        int duration = baseTime;

        if (lastWinner == 0) duration += buffer;

        lane1Green(duration);
        lastWinner = 0;

        lane2Green(baseTime);

      } else {
        int duration = baseTime;

        if (lastWinner == 1) duration += buffer;

        lane2Green(duration);
        lastWinner = 1;

        lane1Green(baseTime);
      }
    }
  }
}
