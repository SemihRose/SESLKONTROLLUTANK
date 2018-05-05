///////////////////////////////////////////////////////////////
//                                                          //
//                                                         //
//Arduino ile ses kontrollü tank                          //
//                                                       //
//                                                      //
// coded by Semih GÜL                                  //
// supported by Rıza Ferit Külköylüoğlu               //
//                                                   //
//////////////////////////////////////////////////////


#include <X113647Stepper.h>
#include <Servo.h>
#include<SoftwareSerial.h>
String voice;
//motor pinleri
#define SolMotorileri 10
#define SolMotorGeri 11
#define SagMotorileri 8
#define SagMotorGeri 9
#define SagMotorE 5
#define SolMotorE 6
SoftwareSerial bt(2,3); /* (Rx,Tx) */  

 
//sensör pinleri
#define role 7
static const int STEPS_PER_REVOLUTION = 64 * 32;
X113647Stepper myStepper(STEPS_PER_REVOLUTION, A5, A4, A3, A2);

void setup()
{
bt.begin(9600); 
myStepper.setSpeed(6.5);

//motor çıkışları
pinMode(SolMotorileri, OUTPUT);
pinMode(SolMotorGeri, OUTPUT);
pinMode(SagMotorileri, OUTPUT);
pinMode(SagMotorGeri, OUTPUT);
pinMode(SagMotorE, OUTPUT);
pinMode(SolMotorE, OUTPUT);

pinMode(A5, OUTPUT);
pinMode(A4, OUTPUT);
pinMode(A3, OUTPUT);
pinMode(A2, OUTPUT);

pinMode(role, OUTPUT);

}
// sonsuz döngü
void loop() {
  
Serial.println ("loop ici");
while (bt.available()){ //Okumak için kullanılabilir bayt olup olmadığını kontrol et
delay(10); //10 milisaniye bekle
char c = bt.read(); //Seri okuma
if (c == '#') {break;} // # tespit edildiğinde döngüden çık
voice += c; //Ses = ses + c Steno
}
if (voice.length() > 0) {
Serial.println(voice);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorE, LOW);
digitalWrite(SolMotorE, LOW);
 
if(voice == "dön"||voice == "dön") {don();}
if(voice == "zero draw"||voice == "zero draw") {don();}
else if(voice == "ileri git"||voice == "ileri") {ileri();}
else if(voice == "Go forward"||voice == "Go forward") {ileri();}
else if(voice == "geri gel"||voice == "geri"){geri();}
else if(voice == "come back"||voice == "come back"){geri();}
else if(voice == "sağa dön"||voice == "sağ") {sag();}
else if(voice == "right"||voice == "right") {sag();}
else if(voice == "sağa dön"||voice == "sağa dön") {sag();}
else if(voice == "sola dön"||voice == "sor") {sol();}
else if(voice == "sola dön"||voice == "son") {sol();}
else if(voice == "sola dön"||voice == "sol") {sol();}
else if(voice == "left"||voice == "left") {sol();}
else if(voice == "sola dön"||voice == "sol") {sol();}
else if(voice == "dur"||voice == "dur") {dur();}
else if(voice == "stop"||voice == "stop") {dur();}
else if(voice == "tur"||voice == "tur") {dur();}
else if(voice == "namlu sağa dön"||voice == "namlu sağ") {namlusag();}
else if(voice == "namlu sola dön"||voice == "namlu sol") {namlusol();}
else if(voice == "ateş at" ||voice == "ateş") {atesat();}
voice="";}}
 
// robotun yön komutları

void ileri()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorE, HIGH);
digitalWrite(SolMotorE, HIGH);
delay(5000);}
 
void geri()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
digitalWrite(SagMotorE, HIGH);
digitalWrite(SolMotorE, HIGH);
delay(5000);}

 void don()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorE, HIGH);
digitalWrite(SolMotorE, HIGH);
delay(5000);
}
void sag()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SolMotorE, HIGH);
delay(5000);}

 
void sol()
{

digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
digitalWrite(SagMotorE, HIGH);
delay(5000);}

 
void dur()
{
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorE, LOW);
digitalWrite(SolMotorE, LOW);
delay(5000);
}

void atesat()
{
digitalWrite(role, HIGH);
delay(2000);
digitalWrite(role, LOW);
delay(2000);
}

void namlusag()
{
myStepper.step(-STEPS_PER_REVOLUTION);
delay(500);
}


void namlusol()
{
myStepper.step(+STEPS_PER_REVOLUTION);
delay(500);
}
