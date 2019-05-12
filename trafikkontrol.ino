
int i;

int kirmizi1=3;

int yesil1 =4;

int kirmizi2= 6;
int yesil2=7;

 void setup() {
  pinMode(kirmizi1,OUTPUT);
   pinMode(yesil1,OUTPUT);
   pinMode(kirmizi2,OUTPUT);
  pinMode(yesil2,OUTPUT);
}

void loop () {
isik1(1);
isik2(0);
bekle(4);
isik1(0);
isik2(1);
bekle(4);
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

void bekle(int x) {
  x*=1000;
  delay(x)
}

