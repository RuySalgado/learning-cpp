#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string jumble(string word) {
  string jumbled = "";
  while (word.length() > 0) {
    int pos = rand() % word.length();
    jumbled += word[pos];
    word.erase(pos, 1);
  }
  return jumbled;
}

int main() {
  srand(time(0));

  enum fields { WORD, HINT };
  const int NUM_WORDS = 5;
  const string WORDS[NUM_WORDS][2] = {
    {"bomb", "It goes boom"},
    {"lighthouse", "guides boats at sea"},
    {"paracausality", "space magic"},
    {"keyboard", "you type with this"},
    {"chair", "you sit on it"}
  };

  bool keepPlaying = true;

  while (keepPlaying) {
    cout << "Try guessing the jumbled up word" << endl;
    int wordIndex = rand() % NUM_WORDS;
    string word = WORDS[wordIndex][WORD];
    cout << "[" << jumble(word) << "]" << endl;

    bool keepTrying = true;
    while (keepTrying) {
      string answer;
      cout << "Answer: "; 
      cin >> answer;
      if (answer == word) {
        cout << "CORRECT!" << endl;
        keepTrying = false;
        break;
      }
      if (answer == ".quit") {
        keepTrying = false;
      }
      if (answer == ".hint") {
        cout << WORDS[wordIndex][HINT] << endl;
        continue;
      }
      cout << "Incorrect" << endl;
    }

    string shouldContinue;
    cout << "Keep playing? ";
    cin >> shouldContinue;
    if (shouldContinue != "y") 
      keepPlaying = false;

  }
}