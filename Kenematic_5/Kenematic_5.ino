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

  for (float pos6 = 30, pos7 = 0, pos8 = 0; pos6 <= 90; pos6 += 1, pos7 += 0.2, pos8 += 0.6) {  // 60 сгибание середина лево 1
    
MSS1.servoWrite(6, pos6);   //13
MSS1.servoWrite(5, 70 - pos7);   //14
MSS1.servoWrite(4, 120 - pos8);   //15


    delay(30);  
  }

  for (float pos6 = 90, pos7 = 0, pos8 = 0; pos6 <= 130; pos6 += 1, pos7 += 0.2, pos8 += 0.6) {  // 40 разгибание середина лево 2
    
MSS1.servoWrite(6, pos6);    //13
MSS1.servoWrite(5, 60 + pos7);  //14
MSS1.servoWrite(4, 90 + pos8);   //15


    delay(30);  
  }

MSS1.servoWrite(6, 30);    //13
MSS1.servoWrite(5, 20);  //14
delay(300);
}
}