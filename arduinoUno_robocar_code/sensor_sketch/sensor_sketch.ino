
const int ULT_TRIGGER = A4, ULT_ECHO = A5;

float duration = 0, distance = 0;

unsigned long lastTriggerTime = 0, currentTime;

void setup() {
  pinMode(ULT_TRIGGER, OUTPUT);
  pinMode(ULT_ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  currentTime = millis();

  if (currentTime - lastTriggerTime >=  60){
    lastTriggerTime = currentTime;
    triggerSensor();
  }
}

void triggerSensor(){
  digitalWrite(ULT_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULT_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULT_TRIGGER, LOW);

  duration = pulseIn(ULT_ECHO, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
}