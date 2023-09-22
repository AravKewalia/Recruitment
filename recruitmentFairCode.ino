#include <DHT11.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define DHT_PIN 2
#define MOTOR_PIN 3
#define Lcd
LiquidCrystal_I2C lcd(0x27,20,4);

// Create an instance of the DHT11 class and set the digital I/O pin.
DHT11 dht11(DHT_PIN);

void setup()
{
  pinMode(MOTOR_PIN, OUTPUT);
  lcd.init();                     
  lcd.init();
  lcd.backlight();
  Serial.begin(115200);
}

void loop()
{
    // Read the humidity from the sensor.
    float humidity = dht11.readHumidity();

    // Read the temperature from the sensor.
    float temperature = dht11.readTemperature();

    float fahrenheit = (dht11.readTemperature() * 9/5) + 32;

    // If the temperature and humidity readings were successful, print them to the serial monitor.
    if (temperature != -1 && humidity != -1)
    {
        lcd.print("Celsius: ");
        lcd.print(temperature);
        lcd.println(" C");

        lcd.print("Fahrenheit: ");
        lcd.print(fahrenheit);
        lcd.println(" F");

        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.println(" %");
    }
    else
    {
        // If the temperature or humidity reading failed, print an error message.
        lcd.println("Error reading data");
    }

    analogWrite(MOTOR_PIN, map(fahrenheit, 75, 82, 0, 255));

    // Wait for 2 seconds before the next reading.
    delay(300);
}
