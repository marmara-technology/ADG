
int durum = 0;
int i;
int trig=8;
int echo=9;
int kirmizi1=3;
int acilled = 12;
int yesil1 =4;
int acil = 0;
int kirmizi2= 6;
int yesil2=7;
int adb = 13;
long cevap,cm,inc;

 void setup() {
  pinMode(kirmizi1,OUTPUT);
  pinMode(yesil1,OUTPUT);
  pinMode(kirmizi2,OUTPUT);
  pinMode(yesil2,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(adb,INPUT);
  pinMode(acilled,OUTPUT);
}

void loop () {
 acil = digitalRead(adb);
if (acil != HIGH) {
  digitalWrite(acilled,LOW);
  normal(1);
}

 else if ( acil == HIGH) {
digitalWrite(acilled,HIGH);
konumkontrol();
if(cm < 10){
  yolbosalt(cm);
}
else if(cm>20) normal(3);
  }
}
void isik1(int x) {
  digitalWrite(yesil1,LOW);
  digitalWrite(kirmizi1,LOW);
  while(x == 1) {
digitalWrite(kirmizi1,HIGH);
break;
  }
  while (x == 0) {
digitalWrite(yesil1,HIGH);
break;
}
}

void isik2(int x) {
  digitalWrite(yesil2,LOW);
  digitalWrite(kirmizi2,LOW);
  while (x == 1) {
 digitalWrite(kirmizi2,HIGH);
break;
  }
 while (x == 0) {
digitalWrite(yesil2,HIGH);
break;  }
}

int bekle(int zaman) {

  zaman = 4*zaman;
  for (i=0;i<zaman;i++){
    if (acil==HIGH) {
     konumkontrol();
    if (cm <10) break;
    }
    delay(250);
   
    }
  }

int normal (int x) {
 
isik1(1);
isik2(0);
bekle(x);
isik1(0);
isik2(1);
bekle(x);
}

int konumkontrol() {
 
digitalWrite(trig,LOW);
delay(2);
digitalWrite(trig,HIGH);
delay(10);
digitalWrite(trig,LOW);
cevap = pulseIn(echo, HIGH);
cevir(cevap);

return cm;
}
void cevir(long x) {
  inc = x/74/2;
  cm = inc*2.54;
} 

int yolbosalt(int konum) {
 if(konum>0 && konum < 10){
    isik1(1);
    isik2(0);
  }
  
if (konum>10) exit(0);
}
