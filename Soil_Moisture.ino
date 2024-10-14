#define relay 6
int sensor_pin = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor_pin, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
}

void loop(){

  int sensor_data = analogRead(sensor_pin);
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.println("\t | ");
  
  if(sensor_data > 700){

    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay, LOW);

  }

  else if(sensor_data <= 700){

    digitalWrite(relay, HIGH);
    Serial.println("Soil is wet");
  }

  delay(100);
}
