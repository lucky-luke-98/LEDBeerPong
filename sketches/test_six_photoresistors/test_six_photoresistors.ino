/*
Projekt: Beerpong-Tisch
Part: 2
Autor: Lukas Jäschke
Date of Begin: 23.07.2020
*/

// Definition der Variablen

int hellig[] = {0, 0, 0, 0, 0, 0};

static int summe[] = {0, 0, 0, 0, 0, 0};
static int anzahl = 0;
int start[] = {0, 0, 0, 0, 0, 0};

int writ[] = {1, 2, 3, 4, 5, 6};


void setup() {

Serial.begin(9600);

for(int i=0; i<51; i++)
{
  for(int j=0; j<6; j++)
  {
    summe[j]+=analogRead(j);
    Serial.print(analogRead(j));
    Serial.print("    ");
  }
  Serial.println("");
  anzahl++;
  delay(200);
}

for(int i=0; i<6; i++)
{
  start[i] = summe[i]/anzahl;
  Serial.print(i+1);
  Serial.print(". Photoresistor:  ");
  Serial.println(start[i]);
}

}


void loop() {

for(int i=0; i<6; i++)
{
  hellig[i] = analogRead(i);  
}

for(int i=0; i<6; i++)
{
  if(hellig[i] > start[i] * 2)
  {
    Serial.println(writ[i]);
  }
}

delay(100);

}
