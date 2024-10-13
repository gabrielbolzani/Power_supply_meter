#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

bool debug = true;

typedef struct variaveis {
  float voltage;
  float current;
  float power;
  String work_mode;
} variaveis;

variaveis actual;
variaveis last;

void init_sistem() {
  lcd.setBacklight(HIGH);
  lcd.setCursor(1, 0);
  lcd.print("Fonte Ajustavel V1");
  delay(800);
  lcd.setCursor(2, 2);
  lcd.print("0-30V |0-4A| 60W");
  delay(10000);
  lcd.clear();
  lcd.setCursor(2, 1);
  lcd.print("Bolzani Solucoes");
  delay(800);
  lcd.clear();
  actual.work_mode = "Tensao Constante";
}


void update_last_values () {
  last.voltage = actual.voltage;
  last.current = actual.current;
  last.work_mode = actual.work_mode;
}


bool change_values_verify () {
  if ((abs(last.voltage - actual.voltage) > 0.03) || (abs(last.current - actual.current) > 0.03) || (last.work_mode != actual.work_mode)) {
    return true;
  } else {
    return false;
  }
}

void inicialize_values () {
  actual.voltage = 99.99;
  actual.current = 88.88;
  actual.work_mode = "Tensao Constante";
  last.voltage = 77.77;
  last.current = 66.66;
  last.work_mode = "Tensao Constante";
}


void update_values() {
  for (int i = 0; i < 500; i++) {
    actual.voltage += ((analogRead(A0) * (5.0 / 1024.0)) * 6.330526);
  }
  actual.voltage = (actual.voltage / 500.0);


  for (int i = 0; i < 500; i++) {
    actual.current += ((((analogRead(A1) * (5.0 / 1024.0)) - 2.4838 ) / 0.066));
  }
  actual.current = (actual.current / 500.0);

  if(actual.current<0){
    actual.current=0.00000000000001;
  }
  //Serial.println(actual.current, 5);

  actual.power = abs(actual.current * actual.voltage);
}


void setup()
{
  lcd.init();
  init_sistem();
  inicialize_values();
  if (debug) {
    Serial.begin(115200);
    Serial.println("Sistema inicializado");
  }
}


void loop()
{
  update_values();
  if (change_values_verify()) {
    lcd.clear();

    lcd.setCursor(2, 1);
    lcd.print("Tensao:  " + String(actual.voltage, 2) + " V");
    lcd.setCursor(2, 2);
    lcd.print("Corrente: " + String(actual.current, 2) + " A");
    lcd.setCursor(2, 3);
    lcd.print("Potencia: " + String(actual.power, 2) + " W");
    delay(200);
  }
  update_last_values();
}
