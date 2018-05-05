// Ses kontrollü tank
//coded by Semih GÜL
//supported by Rıza Ferit Külköylüoğlu






#include <X113647Stepper.h>
#include <Servo.h>
String voice;
//motor pinleri
#define SolMotorileri 12
#define SolMotorGeri 13
#define SagMotorileri 9
#define SagMotorGeri 10
 
//sensör pinleri
#define USTrigger 0
#define USEcho 1
#define Maksimum_uzaklik 100
#define role 5

static const int STEPS_PER_REVOLUTION = 64 * 32;
X113647Stepper myStepper(STEPS_PER_REVOLUTION, 8, 9, 10, 11);

Servo servoNesnesi;

void setup()
{
Serial.begin(9600); //iletişim ayarı

myStepper.setSpeed(6.5);


servoNesnesi.attach(9);

//motor çıkışları
pinMode(SolMotorileri, OUTPUT);
pinMode(SolMotorGeri, OUTPUT);
pinMode(SagMotorileri, OUTPUT);
pinMode(SagMotorGeri, OUTPUT);

pinMode(11, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);

pinMode(role, OUTPUT);
 
 digitalWrite(11, HIGH);
}
// sonsuz döngü
void loop() {
  
Serial.println ("loop ici");
while (Serial.available()){ //Okumak için kullanılabilir bayt olup olmadığını kontrol et
delay(10); //10 milisaniye bekle
char c = Serial.read(); //Seri okuma
if (c == '#') {break;} // # tespit edildiğinde döngüden çık
voice += c; //Ses = ses + c Steno
}
if (voice.length() > 0) {
Serial.println(voice);
 digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
 
if(voice == "*dön"||voice == "*dön") {don();}
if(voice == "*zero draw"||voice == "*zero draw") {don();}
else if(voice == "*git gel"||voice == "*git gel") {gitgel();}
else if(voice == "*Go here"||voice == "*Go here") {gitgel();}
else if(voice == "*ileri git"||voice == "*ileri git") {ileri();}
else if(voice == "*Go forward"||voice == "*Go forward") {ileri();}
else if(voice == "*geri gel"||voice == "*geri gel"){geri();}
else if(voice == "*come back"||voice == "*come back"){geri();}
else if(voice == "*sağa dön"||voice == "*sağ") {sag();}
else if(voice == "*right"||voice == "*right") {sag();}
else if(voice == "*sağa dön"||voice == "*sağa dön") {sag();}

else if(voice == "*sola dön"||voice == "*sor") {sol();}

else if(voice == "*sola dön"||voice == "*son") {sol();}
else if(voice == "*sola dön"||voice == "*sol") {sol();}
else if(voice == "*left"||voice == "*left") {sol();}
else if(voice == "*sola dön"||voice == "*sağol") {sol();}
else if(voice == "*dur"||voice == "*dur") {dur();}
else if(voice == "*stop"||voice == "*stop") {dur();}
else if(voice == "*tur"||voice == "*tur") {dur();}
else if(voice == "*az ileri"||voice == "*az git") {azileri();}
else if(voice == "*Go small"||voice == "*Go small") {azileri();}
else if(voice == "*az geri"||voice == "*az gel") {azgeri();}
else if(voice == "*few come"||voice == "*few come") {azgeri();}
else if(voice == "*az ileri"||voice == "*al git") {azileri();}
else if(voice == "*az geri"||voice == "*al gel") {azgeri();}
else if(voice == "*sol ileri"||voice == "*sola dön ileri git") {solileri();}
else if(voice == "*Go forward turn left"||voice == "*Go forward turn left") {solileri();}
else if(voice == "*sağ ileri"||voice == "*sağa dön ileri git") {sagileri();}
else if(voice == "*Go forward turn right"||voice == "*Go forward turn right") {sagileri();}
else if(voice == "*korna"||voice == "*korna") {korna();}
else if(voice == "*horn"||voice == "*horn") {korna();}
else if(voice == "*lamba"||voice == "*lamba") {lamba();}
else if(voice == "*lamp"||voice == "*lamp") {lamba();}
else if(voice == "*siren"||voice == "*siren") {siren();}
else if(voice == "*hooter"||voice == "*hooter") {siren();}
else if(voice == "*tren"||voice == "*tren") {siren();}
else if(voice == "*lamba yak ileri git"||voice == "*lamba yak ileri git") {lileri();}
else if(voice == "*Go forward lamp oil"||voice == "*Go forward lamp oil") {lileri();}
else if(voice == "*sol park et"||voice == "*sol park et") {solpark();}
else if(voice == "*left parked"||voice == "*left parked") {solpark();}
else if(voice == "*sağ park et"||voice == "*sağ park et") {spark();}
else if(voice == "*Right parked"||voice == "*Right parked") {spark();}
else if(voice == "*sağ park çık"||voice == "*sağ çık") {solcpark();}
else if(voice == "*right out"||voice == "*right out") {solcpark();}
else if(voice == "*sol park çık"||voice == "*sol çık") {scpark();}
else if(voice == "*left wing"||voice == "*left wing") {scpark();}
else if(voice == "*namlu sağa dön"||voice == "*namlu sağ") {namlusag();}
else if(voice == "*namlu sola dön"||voice == "*namlu sol") {namlusol();}
else if(voice == "*sol park çık"||voice == "*sağ açık") {solcpark();}
else if(voice == "*sol park çık"||voice == "*sol açık") {scpark();}
else if(voice == "*servo sağa döndür" ||voice == "*servo sağ") {servosag();}
else if(voice == "*servo sola döndür" ||voice == "*servo sol") {servosol();}
else if(voice == "*ateş at" ||voice == "*ateş") {atesat();}
voice="";}}
 
// robotun yön komutları
void scpark()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
delay(450);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
delay(450);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
}
void solcpark()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
delay(450);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
}
void solpark()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(450);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(100);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
}
void spark()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
delay(450);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(100);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
}
void lileri()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(8, HIGH);
digitalWrite(6, HIGH);

}
void korna()
{
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7, LOW);
delay(300);
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7, LOW);
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7, LOW);
delay(300);
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7, LOW);
}
void lamba()
{
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(6, HIGH);
delay(100);
digitalWrite(6, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
digitalWrite(8, HIGH);
delay(100);
digitalWrite(8, LOW);
delay(100);
}
void siren()
{
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(6, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(6, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
delay(100);
digitalWrite(8, HIGH);
digitalWrite(7, HIGH);
delay(100);
digitalWrite(8, LOW);
digitalWrite(7, LOW);
delay(100);
}
void gitgel()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
delay(100);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
delay(100);
}
void ileri()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);}
void azileri()
{
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);}
 
void geri()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);}
void azgeri()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);}
 void don()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
}
void sag()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);}
void solileri()
{
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
delay(100);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);}
void sagileri()
{
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, HIGH);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
delay(100);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, HIGH);
digitalWrite(SagMotorGeri, LOW);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
}
 
void sol()
{
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SolMotorileri, HIGH);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, HIGH);
delay(500);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);}

 
void dur()
{
digitalWrite(SolMotorGeri, LOW);
digitalWrite(SolMotorileri, LOW);
digitalWrite(SagMotorileri, LOW);
digitalWrite(SagMotorGeri, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
}

void atesat()
{
digitalWrite(role, HIGH);
delay(2000);
digitalWrite(role, LOW);
delay(2000);
}



void servosag()
{
servoNesnesi.write(100);  /* Motorun mili 100. dereceye donuyor */
delay(1000);
}



void servosol()
{
servoNesnesi.write(20);  /* Motorun mili 100. dereceye donuyor */
delay(1000);
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
