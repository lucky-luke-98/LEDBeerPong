
void setup() {

Serial.begin(9600);

int r[1000];
int erg[10] = {0,0,0,0,0,0,0,0,0,0};

randomSeed(analogRead(1));

for(int i = 0; i < 1000; i++){
  r[i] = random(0,10);
  Serial.print(r[i]);
  Serial.println("   ");
  if(r[i]==0){
    erg[0]++;
  }
  if(r[i]==1){
    erg[1]++;
  }
  if(r[i]==2){
    erg[2]++;
  }
  if(r[i]==3){
    erg[3]++;
  }
  if(r[i]==4){
    erg[4]++;
  }
  if(r[i]==5){
    erg[5]++;
  }
  if(r[i]==6){
    erg[6]++;
  }
  if(r[i]==7){
    erg[7]++;
  }
  if(r[i]==8){
    erg[8]++;
  }
  if(r[i]==9){
    erg[9]++;
  }
}

for(int i = 0; i < 10; i++){
  Serial.print(erg[i]);
  Serial.print("  ");
}

}

void loop() {

}
