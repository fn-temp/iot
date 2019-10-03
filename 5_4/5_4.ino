#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define pot A0
LiquidCrystal_I2C lcd(0x27,16,2);
const int LCD_NB_ROWS = 2;
const int LCD_NB_COLUMNS = 16;
/* Caractères personnalisés */
byte DIV_0_OF_5[8] = {
  B00000, 
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
}; // 0 / 5

byte DIV_1_OF_5[8] = {
  B10000, 
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
}; // 1 / 5

byte DIV_2_OF_5[8] = {
  B11000, 
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
}; // 2 / 5 

byte DIV_3_OF_5[8] = {
  B11100, 
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
}; // 3 / 5

byte DIV_4_OF_5[8] = {
  B11110, 
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
}; // 4 / 5

byte DIV_5_OF_5[8] = {
  B11111, 
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
}; // 5 / 5
void setup_progressbar(){

  /* Enregistre les caractères personnalisés dans la mémoire de l'écran LCD */

  lcd.createChar(0, DIV_0_OF_5);
  lcd.createChar(1, DIV_1_OF_5);
  lcd.createChar(2, DIV_2_OF_5);
  lcd.createChar(3, DIV_3_OF_5);
  lcd.createChar(4, DIV_4_OF_5);
  lcd.createChar(5, DIV_5_OF_5);
}
void draw_progressbar(byte percent) {

  /* Affiche la nouvelle valeur sous forme numérique sur la première ligne */
 
  // N.B. Les deux espaces en fin de ligne permettent d'effacer les chiffres du pourcentage
  // précédent quand on passe d'une valeur à deux ou trois chiffres à une valeur à deux ou un chiffres.

  /* Déplace le curseur sur la seconde ligne */
  lcd.setCursor(0, 0);

  /* Map la plage (0 ~ 100) vers la plage (0 ~ LCD_NB_COLUMNS * 5) */
  byte nb_columns = map(percent, 0, 100, 0, LCD_NB_COLUMNS * 5);

  /* Dessine chaque caractère de la ligne */
  for (byte i = 0; i < LCD_NB_COLUMNS; ++i) {

    /* En fonction du nombre de colonnes restant à afficher */
    if (nb_columns == 0) { // Case vide
      lcd.write((byte) 0);

    } else if (nb_columns >= 5) { // Case pleine
      lcd.write(5);
      nb_columns -= 5;

    } else { // Derniére case non vide
      lcd.write(nb_columns);
      nb_columns = 0;
    }
  }
}


void setup() {
  // put your setup code here, to run once:
   lcd.begin();
  setup_progressbar();
  lcd.clear();
   
}
void loop(){
 
  /* Valeur en pourcentage de la barre de progression */
  int readPot = analogRead(pot);
  
  readPot = map(readPot,0,1023,0,100);
  /* Affiche la valeur */
  draw_progressbar(readPot);


  /* Petit temps d'attente */
  delay(100);
}
