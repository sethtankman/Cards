/* Addison Shuppy
Assignment 2, CS3505
*/
#ifndef DECK_H
#define DECK_H // PROTECTS AGAINST DUPLICATE INCLUDES

#include <string>
#include <vector>
#include "Matchup.h"
using namespace std;

class Deck {
  double Winrate;

public:
  string name;
  double wins, losses;
  std::vector<Matchup> matchups;

  Deck();
  Deck(string _name);
  void ModifyScore(int numWins, int numLosses);
  string Scores();
  double GetWinrate();
  void RemoveGameHistory();
  void AddMatch(Deck* _opponent, int numWins, int numLosses, bool isReverseCall);
};

#endif
