const int pinIN3 = 7;   // Dirección motor
const int pinIN4 = 8;   // Dirección opuesta
const int pinENB = 9;   // PWM (control de velocidad)

void setup() {
  pinMode(pinIN3, OUTPUT);//josepp cabrazoo
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
}

void loop() {
  // Sentido antihorario (izquierda)
  digitalWrite(pinIN3, LOW);   // IN3 a 0
  digitalWrite(pinIN4, HIGH);  // IN4 a 1
  analogWrite(pinENB, 200);    // Velocidad moderada (0–255)