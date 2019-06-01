const int buttonPins[6] = {2,3,4,5,6};

char buttonStates[6] = "00000";
boolean buttonsChanged = false;

void setup() {
  // put your setup code here, to run once:
  for (int i=0;i<5;i++){
    pinMode(buttonPins[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {

  buttonsChanged = false;
  for (int i=0;i<5;i++){
    int buttonState = digitalRead(buttonPins[i]);
    if (buttonState == HIGH) {
      if (buttonStates[i] == '0') buttonsChanged = true;
      buttonStates[i] = '1';
    } else {
      buttonStates[i] = '0';
    }
  }

  if (buttonsChanged == true) {
    Serial.print("Button:");
    Serial.println(buttonStates);
  }
  
  delay(50);  
}
