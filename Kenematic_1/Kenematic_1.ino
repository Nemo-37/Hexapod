#include <iarduino_MultiServo.h>  // Подключаем библиотеку
iarduino_MultiServo MSS;
iarduino_MultiServo MSS1;  // Объявляем переменную MSS, для работы с библиотекой (объект класса iarduino_MultiServo).


//
void setup() {
  Serial2.begin(9600);
  pinMode(2, OUTPUT);  //
                       // MSS.servoSet(10,180,130,470);                            // Ручное позиционирование сервопривода (Подключён к выводу 10. Максимальный угол поворота 180°. ШИМ для 0° = 130. ШИМ для 180° = 470)
                       // MSS.servoSet(11,180,140,480);                            // Ручное позиционирование сервопривода (Подключён к выводу 11. Максимальный угол поворота 180°. ШИМ для 0° = 140. ШИМ для 180° = 480)
  MSS.servoSet(SERVO_ALL, SERVO_MG996R);
  MSS1.servoSet(SERVO_ALL, SERVO_MG996R);  // Авто   позиционирование сервопривода (Подключён к выводу 15. Название сервопривода)
                                           // Функция servoSet() вызывается для каждого сервопривода.
                                           // Если ко всем выводам подключены одинаковые сервоприводы, то допускается вызвать функцию servoSet() один раз, указав вместо номера вывода: SERVO_ALL
                                           // - Пример_1: MSS.servoSet(SERVO_ALL, SERVO_SG90); // Ко всем выводам подключены сервоприводы SG90
                                           // - Пример_2: MSS.servoSet(SERVO_ALL,180,140,480); // Ко всем выводам подключены одинаковые сервоприводы, параметры которых заданы вручную
  MSS.begin(0x40);
  MSS1.begin(0x41);  // Инициализация модуля (Адрес по умолчанию = 0x40. Частота по умолчанию = 50Гц)
}

void loop() {
  analogWrite(2, 55);
  MSS.servoWrite(5, 90);    //1
  MSS.servoWrite(6, 120);   //2
  MSS.servoWrite(7, 90);    //3
  MSS.servoWrite(9, 90);    //4
  MSS.servoWrite(10, 120);  //5
  MSS.servoWrite(11, 90);   //6
  MSS.servoWrite(13, 90);   //7
  MSS.servoWrite(14, 120);  //8
  MSS.servoWrite(15, 90);   //9

  MSS1.servoWrite(10, 90);  //10
  MSS1.servoWrite(9, 60);   //11
  MSS1.servoWrite(8, 90);   //12
  MSS1.servoWrite(6, 90);   //13
  MSS1.servoWrite(5, 60);   //14
  MSS1.servoWrite(4, 90);   //15
  MSS1.servoWrite(2, 90);   //16
  MSS1.servoWrite(1, 60);   //17
  MSS1.servoWrite(0, 90);   //18

while (true){
//delay(500);
//MSS.servoWrite(9, 140);    //4
//delay(500);
//MSS.servoWrite(10, 120);  //5
//delay(500);
//MSS.servoWrite(9, 40);    //4
//delay(500);
//MSS.servoWrite(10, 160);  //5

for (float pos = 0, pos1 = 0, pos2 = 0; pos <= 25; pos += 1, pos1 += 0.2, pos2 += 0.4) {  //сгибание середина лево 1
    
  MSS.servoWrite(5, 90 - pos);    //1 90
  MSS.servoWrite(6, 120 - pos1);   //2. 120
  MSS.servoWrite(7, 90 + pos2);    //3. 110


    delay(30);  
  }

  for (float pos = 25, pos1 = 5, pos2 = 10; pos <= 50; pos += 1, pos1 += 0.2, pos2 += 0.4) {  //сгибание середина лево 1
    
  MSS.servoWrite(5, 90 - pos);    //1 90
  MSS.servoWrite(6, 120 - pos1);   //2. 120
  MSS.servoWrite(7, 90 + pos2);    //3. 110


    delay(30);  
  }

    MSS.servoWrite(5, 90);    //1 90
  MSS.servoWrite(6, 160);   //2. 120
  MSS.servoWrite(7, 90);    //3. 110
  delay(300);

}
}
