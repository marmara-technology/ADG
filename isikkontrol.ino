int durum = 0;
int i;
int out = 0;
//1. LAMBA
int kirmizi1=0;
int sari1=1;
int yesil1 =2;
//2. LAMBA
int kirmizi2= 3;
int sari2=4;
int yesil2=5;
 int cikis =  13;
// SENSÖRLER
int s1 = 6;
int s2 = 7;

int sensor1=0;
int sensor2=0;

 void setup() {
  pinMode(kirmizi1,OUTPUT);
  pinMode(sari1,OUTPUT);
  pinMode(yesil1,OUTPUT);
   pinMode(cikis,OUTPUT);
  pinMode(kirmizi2,OUTPUT);
  pinMode(sari2,OUTPUT);
  pinMode(yesil2,OUTPUT);

  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  
}

void loop () {
  digitalWrite(cikis,LOW);
  //SENSORLERİ KONTROL ET
sensor1 = digitalRead(s1);
sensor2 = digitalRead(s2);
if(sensor1 == HIGH)  {
    digitalWrite(kirmizi1,HIGH);
    digitalWrite(yesil2,HIGH);


     digitalWrite(kirmizi2,LOW);
    digitalWrite(yesil1,LOW);

    digitalWrite(sari1,LOW);
    digitalWrite(sari2,LOW);
}
if(sensor2 == HIGH)  {
  digitalWrite(kirmizi2,HIGH);
  digitalWrite(yesil1,HIGH);
 
 digitalWrite(kirmizi1,LOW);
 digitalWrite(yesil1,LOW);

 digitalWrite(sari1,LOW);
 digitalWrite(sari2,LOW);
}
if (sensor1==LOW && sensor2 == LOW) normal(10);
}


// LAMBA FONKSİYONLARI
void isik1(int x) {
  digitalWrite(yesil1,LOW);
  digitalWrite(kirmizi1,LOW);
  digitalWrite(sari1,HIGH);
  delay(600);
   // DÖNGÜNÜN 1 KEZ ÇALIŞMASI İÇİN while + break yaptık
  while(x == 1) {
digitalWrite(kirmizi1,HIGH);
digitalWrite(sari1,LOW);
break;
  }
  while (x == 0) {
digitalWrite(yesil1,HIGH);
digitalWrite(sari1,LOW);
break;
}
}

void isik2(int x) {
  digitalWrite(yesil2,LOW);
  digitalWrite(kirmizi2,LOW);
  digitalWrite(sari2,HIGH);
  delay(600); 
  // DÖNGÜNÜN 1 KEZ ÇALIŞMASI İÇİN while + break yaptık
  while (x == 1) {
 digitalWrite(kirmizi2,HIGH);
 digitalWrite(sari2,LOW);
break;
  }
 while (x == 0) {
digitalWrite(yesil2,HIGH);
digitalWrite(sari2,LOW);
break;  }
}

int bekle(int zaman) {

  zaman = 40*zaman;
  for (i=0;i<zaman;i++){
 sensor1= digitalRead(s1);
 sensor2= digitalRead(s2);
    if (sensor1==HIGH || sensor2 == HIGH)  break;
   
    delay(25);
    }
  }

int normal (int x) {
isik1(1);
isik2(0);
bekle(x);
//delay(x);
isik1(0);
isik2(1);
bekle(x);
//delay(x);
}


int yol1bosalt() {
   while(sensor1 == HIGH){  
   digitalWrite(kirmizi1,HIGH);
    digitalWrite(yesil2,HIGH);

     digitalWrite(kirmizi2,LOW);
    digitalWrite(yesil1,LOW);

    digitalWrite(sari1,LOW);
    digitalWrite(sari2,LOW);
  }
 
  //  if (sensor1 == LOW) exit(0);
}

int yol2bosalt() {
 do
 {digitalWrite(kirmizi2,HIGH);
 digitalWrite(yesil1,HIGH);
 
 digitalWrite(kirmizi1,LOW);
 digitalWrite(yesil1,LOW);

 digitalWrite(sari1,LOW);
 digitalWrite(sari2,LOW);
}
  while(sensor2 == HIGH);
 // if (sensor2 == LOW) exit(0);
}
