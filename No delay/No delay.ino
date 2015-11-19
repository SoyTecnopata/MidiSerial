byte nota, Chn1 = 144, Chn2 = 145, Chn3 = 146, Chn4 = 147;
long previousMillis1A,previousMillis1B;

void setup()
{
    for(int i=5; i<=11; i=i+2)
    {
        pinMode(i, OUTPUT);   
    }

    for(int i=6; i<=12; i=i+2)
    {
        pinMode(i, INPUT);   
    }

  Serial.begin(9600);
}
void loop()
{
  while(1)  
  {   
      //Ultrasonico 1

        unsigned long currentMillis1A = millis();
        if(currentMillis1A - previousMillis1A > 200)
              {
                previousMillis1A = currentMillis1A;   
                      nota=distancia(5,6);
                      MIDImessage(Chn1, nota, 100);
                      byte prenote1 =note1;
              }

        unsigned long currentMillis1B = millis();
        if(currentMillis1B - previousMillis1B > 300)
              {
                previousMillis1B = currentMillis1B;   
                MIDImessage(Chn1, prenote1, 0);
              }

 
    
   }
}


void MIDImessage(byte command, byte data1, byte data2)
{
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}


byte distance(int trig, int eco)
{

 long tiempo=0;
 int distancia=0;

  digitalWrite(trig,LOW); 
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  
  int tiempo=pulseIn(eco, HIGH); 
  if(tiempo>=4117)
     {
          distancia=70;
     }
   else
      {
          distancia= int(0.017*tiempo);
      }

  byte note= map(distancia, 0, 70, 0, 127);

  return note;

}