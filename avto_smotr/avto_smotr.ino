#include <DHT.h>     // Подключение библиотеки
#define datc 6// pin Датчика
#define DHTTYPE DHT22   // тип датчика
#define vint 5 //pin винта
//Реле
#define relay1 1
#define relay2 2
#define relay3 3
#define relay4 4
//Реле
 
DHT dht(datc, DHTTYPE);
 
void setup() {
  //Датчик темп влаж
  Serial.begin(9600);
  dht.begin();
  //датчик темп влаж

  //реле
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);
  //реле

  //винты
  analogWrite(vint, 255);
  //винты
}
 
void loop() {
  // Датчик темп влаж
  delay(2000); // интервал
  float h = dht.readHumidity(); // влажность
  float c = dht.readTemperature(); // температура (в Цельсиях)
  
  if (isnan(h) || isnan(c)) // Проверка подключения датчика.
    {
      Serial.println(F("Failed to read from DHT sensor!")); 
      return;
    }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(c);
  // Датчик темп влаж
  
  //реле
  if (h<60 )
  {
    digitalWrite(relay1, HIGH);
    delay(1000);
  }
  else if (h>=70)
  {
    digitalWrite(relay1, LOW);
    delay(1000);
  }
  //реле

  //винты
  if (c <=16)
  {
    analogWrite(vint,0); //0%
    Serial.print("подмерзаемо");
    delay(100);
  }
  else if (c <=26)
  {
    analogWrite(vint,64); //25%
    Serial.print("Штатная работа");
    delay(100);
  }
  else if (c == 27)
  {
    analogWrite(vint,128); //50%
    Serial.print("Подогрелись");
    delay(100);
  }
  else if (c == 28)
  {
    analogWrite(vint,204); //80%
    Serial.print("Жарко");
    delay(100);
  }
  else if (c > 28)
  {
    analogWrite(vint,255); //100%
    Serial.print("Горим");
    delay(100);
  }
  //винты
}
