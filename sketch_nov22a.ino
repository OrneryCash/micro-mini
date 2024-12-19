#define IN1 12
#define IN2 14
#define IN3 27
#define IN4 26
#define BUTTON 13

void antiClockWise();
void clockWise();

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop()
{
  if (digitalRead(BUTTON) == LOW) {
    long direction = random(2);
    long ran = random(1000, 10001);
    unsigned long start = millis();
    unsigned long endtime = start;

    Serial.printf("%ul\n", endtime - start);

    while ((endtime - start) <= ran) {
      if (direction == 0) {
        clockWise();
      } else {
        antiClockWise();
      }
      endtime = millis();
    }
  }
}

void antiClockWise() {
  digitalWrite(IN1, HIGH);
  delay(2);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  delay(2);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2);
  digitalWrite(IN4, LOW);
}

void clockWise() {
  digitalWrite(IN4, HIGH);
  delay(2);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  delay(2);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  delay(2);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
  delay(2);
  digitalWrite(IN1, LOW);
}