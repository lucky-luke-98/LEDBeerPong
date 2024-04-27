int s_1 = 0;
int s_2 = 0;
int s_3 = 0;
int s_4 = 0;
int s_5 = 0;
int s_6 = 0;
int s_7 = 0;
int s_8 = 0;
int s_9 = 0;
int s_10 = 0;

void setup() {

Serial.begin(9600);
pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

s_1 = analogRead(A0);
s_2 = analogRead(A1);
s_3 = analogRead(A3);
s_4 = analogRead(A4);
s_5 = analogRead(A6);
s_6 = analogRead(A7);
s_7 = analogRead(A9);
s_8 = analogRead(A10);
s_9 = analogRead(A12);
s_10 = analogRead(A13);

Serial.print(s_1);
Serial.print("   ");
Serial.print(s_2);
Serial.print("   ");
Serial.print(s_3);
Serial.print("   ");
Serial.print(s_4);
Serial.print("   ");
Serial.print(s_5);
Serial.print("   ");
Serial.print(s_6);
Serial.print("   ");
Serial.print(s_7);
Serial.print("   ");
Serial.print(s_8);
Serial.print("   ");
Serial.print(s_9);
Serial.print("   ");
Serial.print(s_10);
Serial.print("   ");
Serial.println("");
delay(200);


}
