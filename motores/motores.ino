const int pinIN3 = 7;   // Dirección motor
const int pinIN4 = 8;   // Dirección opuesta
const int pinENB = 9;   // PWM (control de velocidad)

void setup() {
  pinMode(pinIN3, OUTPUT);//josepp cabrazoo
  pinMode(pinIN4, OUTPUT);
  pinMode(pinENB, OUTPUT);
}

void loop() {
  // Sentido horario (derecha)
  digitalWrite(pinIN3,HIGH );   // IN3 a 0
  digitalWrite(pinIN4,LOW );  // IN4 a 1
  analogWrite(pinENB, 200);    // Velocidad moderada (0–255)
