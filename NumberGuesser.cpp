#include <iostream>

using namespace std;

void playerGuess() {
  srand(time(0));
    int rNumber = rand();
    rNumber = rNumber % 100 + 1;


    enum heat {TOO_COLD = 50,  COLD = 30, WARM = 20, HOT = 10};

    cout << "Adivina el numero que elegi entre 1 y 100" << endl;
    int playerGuess;
    bool keepGuessing = true;
    while (keepGuessing) {
      cin >> playerGuess;
      int difference = abs(rNumber - playerGuess);
      string pista;
      if (difference == 0) {
        cout << "Le atinaste! El numero era " << rNumber << " ¡Bien hecho!";
        
        break;
      } 
      if (difference < HOT) pista = "Muy caliente, ";
      if (difference > HOT) pista = "Caliente, ";
      if (difference > WARM) pista =  "Tibio, ";
      if (difference > COLD) pista = "Frio,";
      if (difference > TOO_COLD) pista =  "Muy frio, ";
      cout << pista;
      if (rNumber - playerGuess < 0) {
        cout << "te pasaste, ";
      } else cout << "te falta, ";
      cout << "vuelve a intentar: ";

    }
}

void computerGuess() {
  srand(time(0));
  cout << "Ok intentaré adivinar el número" << endl; 
  bool keepGuessing = true;
  int currentMax = 100;
  int currentMin = 0;
  while (keepGuessing) {
    int rNumber = rand();
    rNumber = rNumber % currentMax + 1;
    if (rNumber <= currentMin || rNumber >= currentMax) {
      continue;
    } 
    int avg = (currentMin + rNumber) / 2;
    if ((currentMin + rNumber) % 2) avg += 1;
    cout << "El numero es " << avg << "?" << endl;
    string answer;
    cin >> answer;
    if (answer == "arriba") {
      currentMin = avg;
    } else if (answer == "abajo") {
      currentMax = avg;
    } else if (answer == "correcto") {
      cout << "Bien! GGs" << endl;
      keepGuessing = false; 
    }

  }
}

int main() {
  bool keepPlaying = true;

  while (keepPlaying) {
    string gameMode;
    cout << "Elige quien adivina el numero, tu o yo (tu/yo): ";
    cin >> gameMode;
    if (gameMode == "tu") {
      computerGuess();
    } else if (gameMode == "yo") {
      playerGuess();
    } else { 
      cout << "Ese no es un modo de juego valido (tu/yo)";
    }

    cout << "Volver a jugar? (y/n) ";
    char yN = 'n';
    cin >>  yN;
    keepPlaying = yN == 'y';
  }

}