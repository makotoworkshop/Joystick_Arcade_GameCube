#include <Nintendo.h>

// Variables
#define Bouton_A  A1
#define Bouton_B  9
#define Bouton_X  A2
#define Bouton_Y  3
#define Bouton_START  A3
#define Bouton_L  7
#define Bouton_R  8
#define Bouton_Z  2
#define Direction_UP  6
#define Direction_DOWN  5
#define Direction_LEFT  A0
#define Direction_RIGHT  4

// Broche de communication vers la console GameCube
CGamecubeConsole gc_console(10);

// Structure de données de la manette
Gamecube_Data_t gc_data = defaultGamecubeData;


void setup() {
//  Serial.begin(115200);
  // Configuration des boutons en entrée avec résistance pull-up
  pinMode(Bouton_A, INPUT_PULLUP);
  pinMode(Bouton_B, INPUT_PULLUP);
  pinMode(Bouton_X, INPUT_PULLUP);
  pinMode(Bouton_Y, INPUT_PULLUP);
  pinMode(Bouton_START, INPUT_PULLUP);
  pinMode(Bouton_L, INPUT_PULLUP);
  pinMode(Bouton_R, INPUT_PULLUP);
  pinMode(Bouton_Z, INPUT_PULLUP);
  pinMode(Direction_UP, INPUT_PULLUP);
  pinMode(Direction_DOWN, INPUT_PULLUP);
  pinMode(Direction_LEFT, INPUT_PULLUP);
  pinMode(Direction_RIGHT, INPUT_PULLUP);
  delay(100);
}

void loop() {
  // Lecture des boutons
  gc_data.report.a      = !digitalRead(Bouton_A);
  gc_data.report.b      = !digitalRead(Bouton_B);
  gc_data.report.x      = !digitalRead(Bouton_X);
  gc_data.report.y      = !digitalRead(Bouton_Y);
  gc_data.report.start  = !digitalRead(Bouton_START);
  gc_data.report.z      = !digitalRead(Bouton_Z);
  gc_data.report.l      = !digitalRead(Bouton_L);
  gc_data.report.r      = !digitalRead(Bouton_R);

  gc_data.report.dup    = !digitalRead(Direction_UP);
  gc_data.report.ddown  = !digitalRead(Direction_DOWN);
  gc_data.report.dleft  = !digitalRead(Direction_LEFT);
  gc_data.report.dright = !digitalRead(Direction_RIGHT);

  // Stick analogique centré
  gc_data.report.xAxis = 128;
  gc_data.report.yAxis = 128;

  // Stick C centré
  gc_data.report.cxAxis = 128;
  gc_data.report.cyAxis = 128;

  // Gâchettes analogiques à 0
  gc_data.report.left = 0;
  gc_data.report.right = 0;

  // Envoi du rapport à la console de jeux
  gc_console.write(gc_data);

//  Serial.print("bouton Y = ");
//  Serial.println(gc_data.report.y);
  
}
