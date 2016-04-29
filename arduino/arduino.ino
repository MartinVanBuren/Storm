//Declare audio analysis pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1 

//Define audio analysis variables
int band;
int Frequencies_One[7];
int Frequencies_Two[7];

//Define led pins
int ledPins[7] = {13, 12, 11, 10, 9, 8, 7};

/********************Setup Loop*************************/
void setup() {
  Serial.begin(9600);
  
  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);
  for (int i=0; i<7; i++) {
    pinMode(ledPins[i], OUTPUT);  
  }
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);
  
  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);
  delay(1);
  digitalWrite(STROBE, HIGH);
  delay(1);
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, LOW);
}


/**************************Main Function Loop*****************************/
void loop() {
  Read_Frequencies();
  leds();
  //Graph_Frequencies();
  delay(10);
}

void leds() {
  for (int i=0; i<7; i++) {
    if(Frequencies_One[i] > 750) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

/*******************Pull frquencies from Spectrum Shield********************/
void Read_Frequencies(){
  //Read frequencies for each band
  for (band = 0; band<7; band++)
  {
    Frequencies_One[band] = analogRead(DC_One);
    Frequencies_Two[band] = analogRead(DC_Two); 
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }
}

/*******************Light LEDs based on frequencies*****************************/
void Graph_Frequencies(){
  Serial.println(Frequencies_One[0]);
  /*
   for(int i= 0; i<7; i++)
   {
     Serial.println(Frequencies_One[i]);
     Serial.print(" ");
     Serial.println(Frequencies_Two[i]);
     delay(10);
   }
   */
}
