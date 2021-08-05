//All the declared variables 
int MinTemp = 0;
int MaxTemp = 0;
int Temp = 0;
int MinHum = 0;
int MaxHum = 0;
int Hum = 0;
int AirQ = 0;
int Food = 0;

void setup(){
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop(){
  
  MinTemp = 19;
  MaxTemp = 30;
  
  MinHum = 50;
  MaxHum = 70;
  
  Temp = map(((analogRead(A5) - 20) * 3.04), 0, 1023, -40, 125);
  Hum = analogRead(A4) / 10.23;
  AirQ = map(analogRead(A3), 300, 750, 0, 100);
  Food = analogRead(A2) / 5.9;
  
  //TEMPERATURE//
  Serial.print("Temperature: ");
  Serial.print(Temp);
  Serial.println(" C ");
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);

  if (Temp < MinTemp) {
    Serial.println("Low Temperature...Turning on the heating");
    Serial.println(" -------------------------------------- ");
    digitalWrite(2, HIGH);
     digitalWrite(3, LOW);
  }
  if (Temp > MaxTemp) {
    Serial.println("High Temperature...Turning on the cooler");
    Serial.println(" -------------------------------------- ");
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
  //HUMIDITY//
  Serial.print("Humidity: ");
  Serial.print(Hum);
  Serial.println(" % ");
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  
  if (Hum < MinHum) {
    Serial.println("Low Humidity...Turning on the air extractor");
    Serial.println(" -------------------------------------- ");
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  if (Hum > MaxHum) {
    Serial.println("High Humidity...Turning on the humidifier");
    Serial.println(" -------------------------------------- ");
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
  }
  //AIR QUALITY//
  Serial.print("Air Quality: ");
  Serial.print(AirQ);
  Serial.println(" % ");
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  
  if (AirQ < 34) {
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }
  if (AirQ > 33 && AirQ < 67 ) {
    Serial.println("Alert with the Air Quality...Turning on the ceiling fan");
    Serial.println(" -------------------------------------- ");
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  }
  if (AirQ > 66 ) {
    Serial.println("Air Quality is dangerous...YOU NEED TO CHECK THE PLACE");
    Serial.println(" -------------------------------------- ");
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  //FOOD//
  Serial.print("Food: ");
  Serial.print(Food);
  Serial.println(" Kg ");
  digitalWrite(9, LOW);
  
  if (Food < 10){
    Serial.println("Compuerta Abierta");
    Serial.println(" -------------------------------------- ");
    digitalWrite(9, HIGH);
  }
  if (Food == 30){
    Serial.println("Compuerta Cerrada");
    Serial.println(" -------------------------------------- ");
  }
  Serial.println("  ");
  delay(1000); 
}
