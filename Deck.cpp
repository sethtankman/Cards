#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"

using namespace std;

/* Default Deck constructor */
Deck::Deck() {
  name = "";
  wins = 0;
  losses = 0;
};

/* The deck constructor */
Deck::Deck(string _name){
    name = _name;
    wins = 0.0;
    losses = 0.0;
    Winrate = 0.0;
}

/* Returns a string to represent the  */
string Deck::Scores() {
  string display;
  display = to_string((int)wins) + "-" + to_string((int)losses);
  return display;
}

/* Modifies the score of the deck */
void Deck::ModifyScore(int numWins, int numLosses) {
  wins += numWins;
  losses += numLosses;
  Winrate = double(wins/(wins+losses));
}

/* A getter for the winrate of this deck */
double Deck::GetWinrate() {
  return Winrate;
}

/* Add Match to matchups, Update Score accordingly */
void Deck::AddMatch(Deck* _opponent, int numWins, int numLosses, bool isReverseCall) {
  Matchup match(this, _opponent, numWins, numLosses);
  matchups.push_back(match);
  ModifyScore(numWins, numLosses);
  if(isReverseCall == false) {
    _opponent->AddMatch(this, numLosses, numWins, true);
  }
}

void Deck::RemoveGameHistory() {
  for(int i = 0; i<matchups.size(); i++) {
    cout << matchups[i].losses << " Wins: " << matchups[i].wins;
    matchups[i].opponent -> ModifyScore(-(matchups[i].losses), -(matchups[i].wins));
  }
}

//ask user for input that specifies what to do with that information
// - rank them
// - view rank without games of a certain deck.
// - find the best decks to remove.
