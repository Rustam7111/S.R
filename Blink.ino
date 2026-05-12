const int sensorPin = A0;  // Пин датчика KS-272 (Аналоговый A0)
const int buzzerPin = 8;   // Пин пищалки
const int ledPin = 13;     // Пин светодиода

// ПОРОГ ЧУВСТВИТЕЛЬНОСТИ (Настройка датчика)
// Если сила тряски больше этого числа, сработает тревога. 
// Чем число больше - тем сильнее нужно ударить по столу.
int threshold = 100; 

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600); 
  Serial.println("Система с аналоговым датчиком KS-272 запущена!");
}

void loop() {
  // Читаем силу вибрации от 0 до 1023
  int vibrationValue = analogRead(sensorPin);

  // Если сила вибрации превышает наш порог
  if (vibrationValue > threshold) { 
    Serial.print("ТРЕВОГА! Сила удара: ");
    Serial.println(vibrationValue); // Печатаем силу удара в порт
    
    digitalWrite(ledPin, HIGH); // Включаем свет
    tone(buzzerPin, 1000);      // Включаем звук
    delay(1000);                // Сигнализация орет 1 секунду
    
  } else {
    // Всё спокойно
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  
  delay(10); // Небольшая пауза
}
