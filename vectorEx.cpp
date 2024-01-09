#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

bool promptLoop(vector<string> *games) {

  string cmd;
  cout << ">";
  cin >> cmd;
  if (cmd == "add") {
    string game;
    cout << "Which game would you like to add?\n>";
    cin >> game;
    games->push_back(game);
    cout << "Added" << endl;
    return true;
  }
  if (cmd == "remove") {
    string game;
    cout << "Which game would you like to remove?\n>";
    cin >> game;
    vector<string>::const_iterator gameToDelete = find(games->begin(), games->end(), game);
    if (gameToDelete == games->end()) {
      cout << "Game not found"<< endl;
    } else {
      games->erase(gameToDelete);
       cout << "Erased" << endl;
    }
    return true;
  }
  if (cmd == "list") {
    vector<string>::const_iterator iter;
    for (iter = games->begin(); iter != games->end(); ++iter) {
      cout << *iter << endl;
    }
    return true;
  }
  if (cmd == "exit")
    return false;
  
}

int main() {
  vector<string> games;

  cout << "Welcome to your game library\n";
  cout << "What would you like to do?\n";
  cout << "[list] library, [add] game, [remove] game, [exit]" << endl ; 

  bool runAgain;
  do {
   runAgain = promptLoop(&games);
  } while (runAgain);
  

}