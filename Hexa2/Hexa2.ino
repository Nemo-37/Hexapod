//  Раскомментируйте для программной реализации шины I2C:   //
//  #define pin_SW_SDA 3                                    // Назначение любого вывода Arduino для работы в качестве линии SDA программной шины I2C.
//  #define pin_SW_SCL 9                                    // Назначение любого вывода Arduino для работы в качестве линии SCL программной шины I2C.
//  Раскомментируйте для совместимости с большинством плат: //
//  #include <Wire.h>                                       // Библиотека iarduino_MultiServo будет использовать методы и функции библиотеки Wire.
//  Ссылки для ознакомления:                                //
//  Подробная информация о подключении модуля к шине I2C:   // http://wiki.iarduino.ru/page/i2c_connection/
//  Подробная информация о функциях и методах библиотеки:   // http://wiki.iarduino.ru/page/multi-servo-shield-na-16-servoprivodov/
//
#include <iarduino_MultiServo.h>  // Подключаем библиотеку
iarduino_MultiServo MSS;
iarduino_MultiServo MSS1;  // Объявляем переменную MSS, для работы с библиотекой (объект класса iarduino_MultiServo).
int pos = 0;
int time = 100;
int time1 = 200;
int q = 90;
//
void setup() {
  pinMode(2, OUTPUT);
  pinMode(43, INPUT);
  pinMode(41, INPUT);
  pinMode(39, INPUT);
  pinMode(37, INPUT);
  pinMode(35, INPUT);
  pinMode(33, INPUT);

  //
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
  MSS.servoWrite(0, q);  //0
  if (digitalRead(43) == HIGH) {

    MSS.servoWrite(0, 90);    //0
    MSS.servoWrite(5, 90);    //1
    MSS.servoWrite(6, 180);   //2
    MSS.servoWrite(7, 90);    //3
    MSS.servoWrite(9, 90);    //4
    MSS.servoWrite(10, 180);  //5
    MSS.servoWrite(11, 90);   //6
    MSS.servoWrite(13, 90);   //7
    MSS.servoWrite(14, 180);  //8
    MSS.servoWrite(15, 90);   //9

    MSS1.servoWrite(10, 90);  //10
    MSS1.servoWrite(9, 0);    //11
    MSS1.servoWrite(8, 90);   //12
    MSS1.servoWrite(6, 90);   //13
    MSS1.servoWrite(5, 0);    //14
    MSS1.servoWrite(4, 90);   //15
    MSS1.servoWrite(2, 90);   //16
    MSS1.servoWrite(1, 0);    //17
    MSS1.servoWrite(0, 90);   //18

    for (pos = 0; pos <= 60; pos += 1) {  // от 0 до 180 градусов
      // шаг в один градус
      MSS.servoWrite(6, 180 - pos);
      MSS.servoWrite(10, 180 - pos);
      MSS.servoWrite(14, 180 - pos);

      MSS1.servoWrite(9, 0 + pos);
      MSS1.servoWrite(5, 0 + pos);
      MSS1.servoWrite(1, 0 + pos);

      delay(30);  // ждём 15ms для достижения позиции
    }

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

    delay(200);
    MSS.servoWrite(6, 180);
    delay(200);
    MSS.servoWrite(6, 120);
    delay(200);
    MSS.servoWrite(10, 180);
    delay(200);
    MSS.servoWrite(10, 120);
    delay(200);
    MSS.servoWrite(14, 180);
    delay(200);
    MSS.servoWrite(14, 120);
    delay(200);

    MSS1.servoWrite(9, 0);
    delay(200);
    MSS1.servoWrite(9, 60);
    delay(200);
    MSS1.servoWrite(5, 0);
    delay(200);
    MSS1.servoWrite(5, 60);
    delay(200);
    MSS1.servoWrite(1, 0);
    delay(200);
    MSS1.servoWrite(1, 60);
    delay(200);

    MSS.servoWrite(6, 180);
    MSS.servoWrite(14, 180);
    MSS1.servoWrite(5, 0);
    for (pos = 0; pos <= 60; pos += 1) {  // от 0 до 180 градусов
      // шаг в один градус
      MSS.servoWrite(6, 180 - pos);
      MSS.servoWrite(14, 180 - pos);
      MSS1.servoWrite(5, 0 + pos);

      delay(20);  // ждём 15ms для достижения позиции
    }
    MSS.servoWrite(10, 180);
    MSS1.servoWrite(9, 0);
    MSS1.servoWrite(1, 0);
    for (pos = 0; pos <= 60; pos += 1) {  // от 0 до 180 градусов
      // шаг в один градус
      MSS.servoWrite(10, 180 - pos);
      MSS1.servoWrite(9, 0 + pos);
      MSS1.servoWrite(1, 0 + pos);

      delay(20);  // ждём 15ms для достижения позиции
    }

    delay(200);
    MSS.servoWrite(6, 180);
    delay(200);
    MSS.servoWrite(6, 120);
    delay(200);
    MSS.servoWrite(10, 180);
    delay(200);
    MSS.servoWrite(10, 120);
    delay(200);
    MSS.servoWrite(14, 180);
    delay(200);
    MSS.servoWrite(14, 120);
    delay(200);

    MSS1.servoWrite(9, 0);
    delay(200);
    MSS1.servoWrite(9, 60);
    delay(200);
    MSS1.servoWrite(5, 0);
    delay(200);
    MSS1.servoWrite(5, 60);
    delay(200);
    MSS1.servoWrite(1, 0);
    delay(200);
    MSS1.servoWrite(1, 60);
    delay(200);

    while (true) {
      if (digitalRead(33) == HIGH) {
        MSS1.servoWrite(0, 90);  //18 ставим несущие ноги
        MSS1.servoWrite(1, 60);  //17/
        MSS1.servoWrite(2, 90);  //16

        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(10, 120);  //5/
        MSS.servoWrite(9, 90);    //4

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11/
        MSS1.servoWrite(8, 90);   //12
        delay(time);
        MSS.servoWrite(6, 160);   //2. 120 поднимаем идущие ноги
        MSS.servoWrite(14, 160);  //8. 120 110
        MSS1.servoWrite(5, 20);   //14
        delay(time);
        MSS.servoWrite(5, 90);    //1 90 переставляем идущие ноги в исходное положение
        MSS.servoWrite(13, 130);  //7. 90 130
        MSS1.servoWrite(6, 90);   //13
        delay(time);
        MSS.servoWrite(6, 120);   //2. 120 ставим идущие ноги
        MSS.servoWrite(7, 90);    //3. 110
        MSS.servoWrite(14, 110);  //8. 120 110
        MSS.servoWrite(15, 110);  //9. 90 110
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        delay(time);
        MSS1.servoWrite(1, 20);   //17/ поднимаем несущие ноги
        MSS.servoWrite(10, 160);  //5/
        MSS1.servoWrite(9, 20);   //11/
        delay(time);

        // начало шага 2,8,14
        for (float pos0 = 0, pos = 0, pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 90, pos7 = 0, pos8 = 0; pos <= 25; pos += 1, pos1 += 0.2, pos2 += 0.4, pos4 += 0.4, pos3 += 1.6, pos5 += 0.8, pos6 += 1.2, pos7 += 0.32, pos8 += 0.96) {  //сгибание середина лево 1

          MSS.servoWrite(5, 90 - pos);    //1 90
          MSS.servoWrite(6, 120 - pos1);  //2. 120
          MSS.servoWrite(7, 90 + pos2);   //3. 110

          MSS.servoWrite(13, 130 - pos3);  //7. 90 130
          MSS.servoWrite(14, 110 + pos4);  //8. 120 110
          MSS.servoWrite(15, 110 - pos5);  //9. 90 110

          MSS1.servoWrite(6, pos6);       //13
          MSS1.servoWrite(5, 60 + pos7);  //14
          MSS1.servoWrite(4, 90 + pos8);  //15


          delay(15);
        }
        //шаг 2,8,14 прошел
        //for (float pos0 = 0, pos = 25, pos1 = 5, pos2 = 10, pos3 = 40, pos4 = 0, pos5 = 0, pos6 = 90, pos7 = 0, pos8 = 0; pos <= 50; pos += 1, pos1 += 0.2, pos2 += 0.4, pos4 += 0.4, pos5 += 1.2, pos6 += 1.6, pos7 += 0.32, pos8 += 0.96 ) {  //сгибание середина лево 1

        // MSS.servoWrite(5, 90 - pos);    //1 90
        //MSS.servoWrite(6, 120 - pos1);   //2. 120
        //MSS.servoWrite(7, 90 + pos2);    //3. 110

        //MSS.servoWrite(13, 90);   //7. 90 130
        ///MSS.servoWrite(14, 120 - pos4);  //8. 120 110
        //MSS.servoWrite(15, 90 - pos5);   //9. 90 110
        //MSS1.servoWrite(6, pos6);   //13
        //MSS1.servoWrite(5, 70 - pos7);   //14
        //MSS1.servoWrite(4, 120 - pos8);   //15


        ///MSS1.servoWrite(6, pos6);    //13
        //MSS1.servoWrite(5, 60 + pos7);  //14
        //MSS1.servoWrite(4, 90 + pos8);   //15


        //delay(30);
        // }
        MSS1.servoWrite(0, 90);  //18 ставим несущие ноги
        MSS1.servoWrite(1, 60);  //17/
        MSS1.servoWrite(2, 90);  //16

        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(10, 120);  //5/
        MSS.servoWrite(9, 90);    //4

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11/
        MSS1.servoWrite(8, 90);   //12
        delay(time);
        MSS.servoWrite(6, 160);   //2 поднимаем ноги которые шли
        MSS.servoWrite(14, 160);  //8.
        MSS1.servoWrite(5, 20);   //14
        delay(time);
        MSS.servoWrite(5, 90);   //1  переставляем ноги которые шли
        MSS.servoWrite(13, 90);  //7.
        MSS1.servoWrite(6, 90);  //13
        delay(time);
        MSS.servoWrite(6, 120);   //2 ставим ноги которые шли
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(14, 120);  //8.
        MSS.servoWrite(15, 90);   //9. 90 110
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        delay(time);              //все ноги стоят на месте по умолчанию
        MSS.servoWrite(10, 160);  //5 поднимаем ноги которые будут идти
        MSS1.servoWrite(9, 20);   //11. 120
        MSS1.servoWrite(1, 20);   //17. 120 110
        delay(time);
        MSS.servoWrite(9, 90);    //4 переставлям ноги которые будит идти
        MSS1.servoWrite(10, 80);  //10 90
        MSS1.servoWrite(2, 40);   //16. 90 130
        delay(time);
        MSS.servoWrite(10, 120);  //5 ставим ноги которые будут идти
        MSS.servoWrite(11, 90);   //6
        MSS1.servoWrite(9, 60);   //11. 120
        MSS1.servoWrite(9, 60);   //11. 120
        MSS1.servoWrite(1, 70);   //17. 120 110
        MSS1.servoWrite(0, 70);   //18. 90 110
        delay(time);
        MSS.servoWrite(6, 160);   //2 поднимаем несущие ноги
        MSS.servoWrite(14, 160);  //8
        MSS1.servoWrite(5, 20);   //14
        delay(time);


        // начало движения 5,11,17
        for (float pos3 = 0, pos4 = 0, pos8 = 0, pos = 0, pos1 = 0, pos2 = 0, pos5 = 0, pos6 = 0, pos7 = 0; pos5 <= 50; pos5 += 1, pos6 += 0.2, pos7 += 0.6, pos += 0.5, pos1 += 0.1, pos2 += 0.2, pos3 += 0.8, pos4 += 0.2, pos8 += 0.4) {  //сгибание середина лево 1

          MSS.servoWrite(9, 90 - pos5 * 0.8);  //4
          MSS.servoWrite(10, 120 - pos6);      //5
          MSS.servoWrite(11, 90 - pos7);       //6

          MSS1.servoWrite(10, 80 + pos);  //10 90
          MSS1.servoWrite(9, 60 + pos1);  //11. 120
          MSS1.servoWrite(8, 90 - pos2);  //12. 110

          MSS1.servoWrite(2, 40 + pos3);  //16. 90 130
          MSS1.servoWrite(1, 70 - pos4);  //17. 120 110
          MSS1.servoWrite(0, 70 + pos8);  //18. 90 110

          delay(5);
        }

        // for (float pos3 = 40, pos4 = 0, pos8 = 0, pos = 25, pos1 = 5, pos2 = 10, pos5 = 40, pos6 = 0, pos7 = 0; pos5 <= 90; pos5 += 1, pos6 += 0.2, pos7 += 0.6, pos += 0.5, pos1 += 0.1, pos2 += 0.2, pos3 += 1, pos4 += 0.2, pos8 += 0.6) {  //разгибание середина лево 2

        ///MSS.servoWrite(9, 130 - pos5);    //4
        //MSS.servoWrite(10, 120 - pos6);  //5
        //MSS.servoWrite(11, 90 - pos7);   //6

        //MSS1.servoWrite(10, 80 + pos);    //10 90
        //MSS1.servoWrite(9, 60 + pos1);   //11. 120
        //MSS1.servoWrite(8, 90 - pos2);    //12. 110

        //MSS1.servoWrite(2, 80);   //7. 90 130MSS.servoWrite(9, 180 - pos5);    //4 MSS.servoWrite(10, 110 + pos6);  //5 MSS.servoWrite(11, 60 + pos7);   //6
        //MSS1.servoWrite(1, 60 + pos4);  //8. 120 110
        //MSS1.servoWrite(0, 90 + pos8);   //9. 90 110


        //delay(30);
        // }
        MSS.servoWrite(6, 120);   //2 стваим несущие ноги
        MSS.servoWrite(14, 120);  //8
        MSS1.servoWrite(5, 60);   //14
        delay(time);
        MSS.servoWrite(10, 160);  //5 поднимаем ноги которые шли
        MSS1.servoWrite(9, 20);   //11. 120
        MSS1.servoWrite(1, 20);   //17. 120 110
        delay(time);
        MSS.servoWrite(9, 90);    //4 переставляем ноги которые шли
        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(2, 90);   //16
        delay(time);
        MSS.servoWrite(10, 120);  //5 ставим ноги которые шли
        MSS.servoWrite(11, 90);   //6
        MSS1.servoWrite(9, 60);   //11. 120
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(1, 60);   //17. 120 110
        MSS1.servoWrite(0, 90);   //18
      }
      if (digitalRead(35) == HIGH) {
        MSS.servoWrite(5, 90);    //1
        MSS.servoWrite(6, 120);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 90);   //7. 90 130
        MSS.servoWrite(14, 120);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 90);   //13
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 90);    //1
        MSS.servoWrite(6, 160);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 90);   //7. 90 130
        MSS.servoWrite(14, 160);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 90);   //13
        MSS1.servoWrite(5, 20);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 40);    //1
        MSS.servoWrite(6, 160);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 40);   //7. 90 130
        MSS.servoWrite(14, 160);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 40);   //13
        MSS1.servoWrite(5, 20);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 40);    //1
        MSS.servoWrite(6, 120);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 40);   //7. 90 130
        MSS.servoWrite(14, 120);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 40);   //13
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 40);    //1
        MSS.servoWrite(6, 120);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 160);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 40);   //7. 90 130
        MSS.servoWrite(14, 120);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 20);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 40);   //13
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 20);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);
      }
      if (digitalRead(37) == HIGH) {
        MSS.servoWrite(5, 90);    //1
        MSS.servoWrite(6, 120);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 90);   //7. 90 130
        MSS.servoWrite(14, 120);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 90);   //13
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 90);    //1
        MSS.servoWrite(6, 160);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 90);   //7. 90 130
        MSS.servoWrite(14, 160);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 90);   //13
        MSS1.servoWrite(5, 20);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 140);   //1
        MSS.servoWrite(6, 160);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 140);  //7. 90 130
        MSS.servoWrite(14, 160);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 140);  //13
        MSS1.servoWrite(5, 20);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 140);   //1
        MSS.servoWrite(6, 120);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 120);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 140);  //7. 90 130
        MSS.servoWrite(14, 120);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 60);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 140);  //13
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 60);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);

        MSS.servoWrite(5, 140);   //1
        MSS.servoWrite(6, 120);   //2
        MSS.servoWrite(7, 90);    //3
        MSS.servoWrite(9, 90);    //4
        MSS.servoWrite(10, 160);  //5
        MSS.servoWrite(11, 90);   //6
        MSS.servoWrite(13, 140);  //7. 90 130
        MSS.servoWrite(14, 120);  //8. 120 110
        MSS.servoWrite(15, 90);   //9. 90 110

        MSS1.servoWrite(10, 90);  //10
        MSS1.servoWrite(9, 20);   //11
        MSS1.servoWrite(8, 90);   //12
        MSS1.servoWrite(6, 140);  //13
        MSS1.servoWrite(5, 60);   //14
        MSS1.servoWrite(4, 90);   //15
        MSS1.servoWrite(2, 90);   //16
        MSS1.servoWrite(1, 20);   //17
        MSS1.servoWrite(0, 90);   //18

        delay(time1);
      }
      if (digitalRead(41) == HIGH) {
        q -= 5;
        MSS.servoWrite(0, q);  //0
        delay(50);
      }
      if (digitalRead(39) == HIGH) {
        q += 5;
        MSS.servoWrite(0, q);  //0
        delay(50);
      } else {
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
        if (digitalRead(41) == HIGH) {
          q -= 5;
          MSS.servoWrite(0, q);  //0
          delay(50);
        }
        if (digitalRead(39) == HIGH) {
          q += 5;
          MSS.servoWrite(0, q);  //0
          delay(50);
        }
      }
    }
  } else {
    MSS.servoWrite(5, 90);    //1
    MSS.servoWrite(6, 180);   //2
    MSS.servoWrite(7, 90);    //3
    MSS.servoWrite(9, 90);    //4
    MSS.servoWrite(10, 180);  //5
    MSS.servoWrite(11, 90);   //6
    MSS.servoWrite(13, 90);   //7
    MSS.servoWrite(14, 180);  //8
    MSS.servoWrite(15, 90);   //9

    MSS1.servoWrite(10, 90);  //10
    MSS1.servoWrite(9, 0);    //11
    MSS1.servoWrite(8, 90);   //12
    MSS1.servoWrite(6, 90);   //13
    MSS1.servoWrite(5, 0);    //14
    MSS1.servoWrite(4, 90);   //15
    MSS1.servoWrite(2, 90);   //16
    MSS1.servoWrite(1, 0);    //17
    MSS1.servoWrite(0, 90);   //18
    if (digitalRead(41) == HIGH) {
      q -= 5;
      MSS.servoWrite(0, q);  //0
      delay(50);
    }
    if (digitalRead(39) == HIGH) {
      q += 5;
      MSS.servoWrite(0, q);  //0
      delay(50);
    }
  }
}