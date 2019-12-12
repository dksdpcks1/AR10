#include <LiquidCrystal_I2C_Hangul.h>

#include <Servo.h>    // 서보모터 라이브러리

#include <IRremote.h>  // 적외선 리모컨 라이브러리

LiquidCrystal_I2C_Hangul lcd(0x27,16,2);

 

int remote = A0;    // 적외선 리모컨 수광 다이오드 신호선

int motor = 9;  // 서보모터

int led_blue = 8;   // 파란색 led

int led_red = 10;    // 빨간색 led

 

      int a,b,c,d,e,f,g;

 

Servo servo;          // servo 라이브러리를 사용해주기 위해 servo객체 생성

IRrecv irrecv(remote);    // IRremote를 사용해주기 위해 irrecv객체 생성

decode_results results;   // 디코드한 결과값

 

 

int angle = 0;    // 서보모터 각도 값

 

 

 

void setup() {

  Serial.begin(9600);

  servo.attach(motor,600,2400);    // 모터 시작

  irrecv.enableIRIn();    // 수광 다이오드 시작

  pinMode(remote, INPUT); // 수광 다이오드 입력

  pinMode(led_blue, OUTPUT);  // led 출력

  pinMode(led_red, OUTPUT);   // led 출력

  servo.write(angle);

lcd.init(); // LCD 설정

  lcd.clear();     

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("Press any key");

  lcd.setCursor(0,1);

  lcd.print("Here");

}

void loop() {

  if (irrecv.decode(&results)){  

    check();

  }

   if(angle >= 0 && angle <= 60)

 {

      digitalWrite(led_blue, HIGH);

      digitalWrite(led_red, LOW);

}

   else if (angle >= 120 && angle <= 180 )

   {

      digitalWrite(led_red, HIGH); 

      digitalWrite(led_blue, LOW);

   }

   else {  

       digitalWrite(led_blue, LOW);

       digitalWrite(led_red, LOW);

   }

} 

void check(){

 

 

 

   // 적외선 리모컨의 신호를 받을 때

 

    switch (results.value) {

 

      case 0xFFA25D:

      a=a+1;

      Serial.print("1번을");

      Serial.print(a);

      Serial.println("번 클릭");

  lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 1 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(a);

      break;

 

     

 

      case 0xFF629D:

 

      b+=1;

 

      Serial.print("2번을");

 

      Serial.print(b);

 

      Serial.println("번 클릭");

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 2 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(b);

      break;

 

     

 

      case 0xFFE21D:

 

      c+=1;     

 

      Serial.print("3번을");

 

      Serial.print(c);

 

      Serial.println("번 클릭");

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 3 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(c);

      break;

 

     

 

      case 0xFF22DD:

 

      d+=1;

 

      Serial.print("4번을");

 

      Serial.print(d);

 

      Serial.println("번 클릭");

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 4 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(d);

      break;

 

     

 

      case 0xFF02FD:

 

      e+=1;

 

      Serial.print("5번을");

 

      Serial.print(e);

 

      Serial.println("번 클릭");

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 5 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(e);

      break;

 

     

 

      case 0xFFC23D:

 

      f+=1;

 

      Serial.print("6번을");

 

      Serial.print(f);

 

      Serial.println("번 클릭");

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 6 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(f);

      break;

 

     

 

      case 0xFFE01F:

 

      g+=1;

 

      Serial.print("7번을");

 

      Serial.print(g);

 

      Serial.println("번 클릭");

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Button 7 ");

  lcd.setCursor(0,1);

  lcd.print("Press : ");  

  lcd.setCursor(9,1);

  lcd.print(g);

      break;

 

     

 

      case 0xFF906F:

 

      if(a==1&&b==2&&c==3&&d==4)

 

      {

 

      Serial.println("확인");

 

 

       

 

     

 

      angle += 120;  // 각도값 90 추가

 

        if (angle > 180)  // 각도가 180이 넘어갈 때

 

          angle = 180;    // 각도값 최대를 180으로

 

        servo.write(angle);

 

        Serial.println(angle);

 

        // 서보모터 각도 이동

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Open!! ");

  delay(1000);

  lcd.clear();     

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("Press any key");

  lcd.setCursor(0,1);

  lcd.print("Here");

      }

 

      else

 

      {

 

       

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("NO ");

delay(1000);

  lcd.clear();     

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("Reset Button is");

  lcd.setCursor(0,1);

  lcd.print("Button 0");

      }

 

     

 

        break;

 

       

 

      case 0xFF9867 :

 

      

 

      a=0;b=0;c=0;d=0;e=0;f=0;g=0;

 

       Serial.println(a);

 

        Serial.println(b);

 

         Serial.println(c);

 

          Serial.println(d);

 

           Serial.println(e);

 

            Serial.println(f);

 

             Serial.println(g);

 

          angle = 0;  // 각도값 최소값을 0으로

 

          Serial.println(angle);

 

           servo.write(angle);

lcd.clear();   

  lcd.setCursor(0,0);

  lcd.print("Lock!! ");

  delay(1000);

  lcd.clear();     

  lcd.backlight();

  lcd.setCursor(0,0);

  lcd.print("Press any key");

  lcd.setCursor(0,1);

  lcd.print("Here");

        break;

 

      case 0xFF18E7:  // +  버튼을 눌렀을 때

 

        angle += 15;  // 각도값 15 추가

 

        if (angle > 180)  // 각도가 180이 넘어갈 때

 

          angle = 180;    // 각도값 최대를 180으로

 

        servo.write(angle);

 

       

 

      Serial.println(angle);// 서보모터 각도 이동

 

        break;

 

       

 

      case 0xFF4AB5:  // - 버튼을 눌렀을 때

 

        angle -= 15;  // 각도값 15 감소

 

        if(angle < 0) // 각도값이 0도보다 적을 때

 

          angle = 0;  // 각도값 최소값을 0으로

 

        servo.write(angle);

 

       

 

      Serial.println(angle);

 

        break;

 

    }

 

    irrecv.resume();

 

 

 

}
