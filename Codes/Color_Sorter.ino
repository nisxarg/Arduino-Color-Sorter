#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6

int frequency = 0;
int color = 0;

void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  analogWrite(S2, LOW); // Red
  analogWrite(S3, LOW);
  frequency = getColorFrequency();
  Serial.print("R= ");
  Serial.print(frequency);
  Serial.print("  ");

  analogWrite(S2, HIGH); // Green
  analogWrite(S3, HIGH);
  frequency = getColorFrequency();
  Serial.print("G= ");
  Serial.print(frequency);
  Serial.print("  ");

  analogWrite(S2, LOW); // Blue
  analogWrite(S3, HIGH);
  frequency = getColorFrequency();
  Serial.print("B= ");
  Serial.print(frequency);
  Serial.println("  ");

  // Determine color
  color = detectColor(frequency);
  
  // Move servo according to color
  moveServo(color);

  delay(300);
}

int getColorFrequency() {
  return pulseIn(sensorOut, LOW);
}

int detectColor(int frequency) {
  if (frequency > 32 && frequency < 45) {
    return 1; // Red
  } else if (frequency > 43 && frequency < 55) {
    return 2; // Orange
  } else if (frequency > 40 && frequency < 53) {
    return 3; // Green
  } else if (frequency > 24 && frequency < 38) {
    return 4; // Yellow
  } else if (frequency > 46 && frequency < 56) {
    return 5; // Brown
  } else if (frequency > 45 && frequency < 58) {
    return 6; // Blue
  } else {
    return 0; // Unknown
  }
}

void moveServo(int color) {
  switch (color) {
    case 1:
      // Move to position for red
      break;
    case 2:
      // Move to position for orange
      break;
    case 3:
      // Move to position for green
      break;
    case 4:
      // Move to position for yellow
      break;
    case 5:
      // Move to position for brown
      break;
    case 6:
      // Move to position for blue
      break;
    default:
      // Move to default position
      break;
  }
}
