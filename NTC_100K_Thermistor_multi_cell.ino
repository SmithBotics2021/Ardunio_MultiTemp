// Works with 100K NTC Thermistor - Added in 3 more sensors for battery cells 1 thru 4 + PCB Temp Sensor
// Based off of a Sketch provided by Scott Campbell of CircuitBasics.com
// Modified by Smithbotics.com V1.0
// ARDUINO CIRCUIT WIRING BELOW
// 5vcc pin to one side of NTC 100K Thermistor
// Ground connected to 100K resistor lead
// A0 pin connected to other side of 100K resistor and Thermistor (S1 black wire)
// Connect seperate 100K resistor and Thermistor as above and connect to pin A1 (S2 blue wire)
// Connect seperate 100K resistor and Thermistor as above and connect to pin A2 (S3 green wire)
// Connect seperate 100K resistor and Thermistor as above and connect to pin A3 (S4 yellow wire)
// Connect seperate 100K resistor and Thermistor as above and connect to pin A4 (PCB mounted temp sensor)

int Thermistor1Pin = 0;
int Thermistor2Pin = 1;
int Thermistor3Pin = 2;
int Thermistor4Pin = 3;
int Thermistor5Pin = 4;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  Serial.begin(9600);
}

void loop() {

  Vo = analogRead(Thermistor1Pin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0) / 5.0 + 32.0;

  Serial.print("Temperature in Battery Cells S1: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

  delay(2000);

  Vo = analogRead(Thermistor2Pin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0) / 5.0 + 32.0;

  Serial.print("Temperature in Battery Cells S2: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

  delay(2000);


  Vo = analogRead(Thermistor3Pin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0) / 5.0 + 32.0;

  Serial.print("Temperature in Battery Cells S3: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

  delay(2000);


  Vo = analogRead(Thermistor4Pin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0) / 5.0 + 32.0;

  Serial.print("Temperature in Battery Cells S4: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

  delay(2000);


  Vo = analogRead(Thermistor5Pin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2 * logR2 + c3 * logR2 * logR2 * logR2));
  Tc = T - 273.15;
  Tf = (Tc * 9.0) / 5.0 + 32.0;

  Serial.print("===>>  Battery Sensor Board Temp: ");
  Serial.print(Tf);
  Serial.print(" F; ");
  Serial.print(Tc);
  Serial.println(" C");

  delay(3000);


}
