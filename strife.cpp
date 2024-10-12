#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;


int round(string name1, string name2, int grit1, int grit2,
int gel1s, int gel2s, int gel1n, int gel2n, int focus1, int focus2, int composure1, 
int composure2, int pressure1, int pressure2) {
  //Print out entries

  float gel2 = gel2n/(float)gel2s;
  float gel1 = gel1n/(float)gel1s;

  cout << name2 << "\nGrit: " << grit2 << "\nPressure/Composure: " << pressure2 << "/" << composure2 << "\nFocus: " << focus2 << "%\nHPGel: " << gel2*100 << "%\n\n";

  cout << name1 << "\nGrit: " << grit1 << "\nPressure/Composure: " << pressure1 << "/" << composure1 << "\nFocus: " << focus1 << "%\nHPGel: " << gel1*100 << "%\n\n";

  //Decide what move enemy will take
  //Print out Commands
  cout << "(0)AGGRIEVE: Raises Composure by 5. \n(1)AGGRESS: Raises Composure by 10, but increases damage taken by 15%.\n(2)ABUSE: Raises Pressure by 5.\n(3)ACCUSE: Raises Pressure by 10, but decreases damage dealt by 15%.\n(4)ASSAIL: Increases damage dealt by 15%.\n(5)ASSAULT: Increases damage dealt by 30%, but reduces Composure by 5.\n(6)ABJURE: Reduces damage taken by 15%.\n(7)ABSTAIN: Reduces damage taken by 30%, but reduces Pressure by 5.\n\n";
  int command;
  int enemycommand = (rand() % 8);
  cout << name2 << " will do: " << enemycommand << endl;

  //Ask for what move player will do
  cout << "Select Command Number: ", 
  scanf("%d", &command);
  cout << "Command Selected: " << command << endl << endl;

  float modifier1 = 1.0f;
  float modifier2 = 1.0f;

  //Change Composure and Modifiers first
  //player actions
  if (command == 0) {
    composure1 = composure1 + 5;
  } else if (command == 1) {
    composure1 = composure1 + 10;
    modifier2 += 0.15;
  } else if (command == 2) {
    pressure1 = pressure1 + 5;
  } else if (command == 3) {
    pressure1 = pressure1 + 10;
    modifier1 += -0.15;
  } else if (command == 5) {
    composure1 = composure1 - 5;
    modifier1 += 0.30;
  } else if (command == 6) {
    modifier2 += -0.15;
  } else if (command == 7) {
    pressure1 = pressure1 - 5;
    modifier2 += -0.30;
  } else {
    modifier1 += 0.15;
  }
  //enemy actions
  if (enemycommand == 0) {
    composure2 = composure2 + 5;
  } else if (enemycommand == 1) {
    composure2 = composure2 + 10;
    modifier1 += 0.15;
  } else if (enemycommand == 2) {
    pressure2 = pressure2 + 5;
  } else if (enemycommand == 3) {
    pressure2 = pressure2 + 10;
    modifier2 += -0.15;
  } else if (enemycommand == 4) {
    modifier2 += 0.15;
  } else if (enemycommand == 5) {
    composure2 = composure2 - 5;
    modifier2 += 0.30;
  } else if (enemycommand == 6) {
    modifier1 += -0.15;
  } else {
    pressure2 = pressure2 - 5;
    modifier1 += -0.30;
  }

  //Player deals damage
  //cout << "Hp Before :" << gel2n;
  float damage1 = grit1 * modifier1 * (2-(focus2/(float)100));
  gel2n += -(int)damage1;
    if (gel2n <= 1) {
    cout << "You win!\n";
    return 0;
  }
  //cout << "damage Dealt :" << damage1 << "hpnow " << gel2n;
  
  //Enemy deals Damage  
  float damage2 = grit2 * modifier2 * (2-(focus1/(float)100));
  gel1n += -(int)damage2;
  if (gel1n <= 1) {
    cout << "You lose!\n";
    return 0;
  }

  //Modify Focus
  focus2 += -(pressure1 - composure2);
  focus1 += -(pressure2 - composure1);
  //Check composure, set to 0 if negative
  if (focus1 <= 1) {composure1 = 0;}
  if (focus2 <= 1) {composure2 = 0;}

  //Go to next round

  return round(name1, name2, grit1, grit2, gel1s, gel2s, gel1n, gel2n, focus1, focus2, composure1, composure2, pressure1, pressure2);
} 

int main() {
  srand(time(0));

  //ask for input on moves
  string name1 = "hehe";
  string name2 = "hohoo";
  int grit1 = 100;
  int grit2 = 200;
  int gel1s = 400;
  int gel2s = 300;
  int gel1n = 400;
  int gel2n = 200;
  int focus1 = 100;
  int focus2 = 100;
  int composure1 = 50;
  int composure2 = 200;
  int pressure1 = 30;
  int pressure2 = 40;

  cout << setprecision(0) << fixed;

  round(name1, name2, grit1, grit2, gel1s, gel2s, gel1n, gel2n, focus1, focus2, composure1, composure2, pressure1, pressure2);

  return 0;
}