
const int lm35Pin = A0;  // Pin analógico del LM35
const int decenaPins[] = {2, 3, 4, 5};  // Pines para la decenas 
const int unidadPins[] = {6, 7, 8, 9};  // Pines para la unidades 

void setup() {
  Serial.begin(9600);  // Comunicación serial
  for (int i = 0; i < 4; i++) {     // Se configuran los 8 pines usados (4 para decenas y 4 para unidades) como las salidas digitales.
    pinMode(decenaPins[i], OUTPUT);
    pinMode(unidadPins[i], OUTPUT);
  }
}
// josep cabrozaaaaazo
void loop() {
  int sensorValue = analogRead(lm35Pin);  
  int temperature = (sensorValue * 0.488);  // Conversión a temperatura entera

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");
  int unidad = temperature % 10;   // Extrae la unidad
  int decena = (temperature / 10) % 10;  // Extrae la decena

  // Prueba de encendido manual para ver si los pines están activando los segmentos
  Serial.println("Probando salida:");
  Serial.print("Decena: "); Serial.println(decena);
  Serial.print("Unidad: "); Serial.println(unidad);
  // Llama a una función para mostrar cada dígito en el display.
  mostrarNumero(decena, decenaPins); 
  mostrarNumero(unidad, unidadPins);
  delay(1000); 
  // Limitamos la temperatura a un máximo de 99°C
  if (temperature > 99) {
    temperature = 99;
  }
}

// Función para enviar el número en binario al integrado 7449
void mostrarNumero(int num, const int pins[]) {  //Esta función convertira el número decimal (0–9) a su representación binaria de 4 bits.
  Serial.print("Enviando bits: "); Serial.println(num);
  for (int i = 0; i < 4; i++) {
    Serial.print((num >> i) & 1);
    digitalWrite(pins[i], (num >> i) & 1);
  }
  Serial.println();
}
