const int analogIn = A0;
int humiditysensorOutput = 0;
// Defining Variables
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;

void setup(){  
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop(){
  
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  tempC = (Voltage-500) * 0.1; // 500 is the offset
  Serial.print("\t Temperature in C = ");
  Serial.print(tempC,1);
  Serial.println("%");
  humiditysensorOutput = analogRead(A1);
  Serial.print("\t Humidity =  "); // Printing out Humidity Percentage
  Serial.print(map(humiditysensorOutput, 0, 1023, 10, 70));
  Serial.println("%");
  delay(5000);  //iterate every 5 seconds

}