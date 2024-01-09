#include <iostream>
#include <cctype>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;


void hangman() {
  const int GUESS_TRIES = 8;

  vector<string> words;
  words.push_back("GHSOT");
  words.push_back("SPARROW");
  words.push_back("VANDAL");

  random_shuffle(words.begin(), words.end());
  string hangmanAnswer = words[0];

  string playerTrack (hangmanAnswer.size(), '_');
  string used;
  bool keepTrying = true;
  int triesLeft = GUESS_TRIES;
  cout << "Try to guess the word" << endl;
  while (keepTrying)
  {
    cout << "Your progress: " << playerTrack << "\n\n";
    cout << "You have " << triesLeft << " left." << endl;
    char playerGuess;
    cin >> playerGuess;
    playerGuess = toupper(playerGuess);
    if (hangmanAnswer.find(playerGuess) != string::npos) {
      cout << "You got a hit!" << endl;
      for (int i = 0; i < hangmanAnswer.length(); i++) {
        if (hangmanAnswer[i] == playerGuess) {
          playerTrack[i] = playerGuess;
        }
      }
      if (hangmanAnswer == playerTrack) {
        cout << "You win!" << endl;
        keepTrying = false;
      }
      continue;
    }

    cout << "Wrong! " << endl;
    if (used.find(playerGuess) != string::npos) {
      cout << "You have already used " << playerGuess << "!" << endl;
    } else {
      used += playerGuess;
    }
    triesLeft--;
    if (triesLeft == 0) {
      cout << "You ran out of tries, better luck next time" << endl; 
      keepTrying = false;
    }
  }
  
}

int main() {
  srand(time(0));
  bool keepPlaying = true;


  cout << "Welcome to hangman! Good luck.";
  while (keepPlaying) {
    hangman();

    char answer;
    cout << "Keep playing?" << endl;
    cin >> answer;

    if (answer != 'y')
      keepPlaying = false;
  }
}
