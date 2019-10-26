#include <iostream>
#include <array>
#include <map>
#include "Deck.h"
#include "Matchup.h"

using namespace std;


class DeckList {
  std::map<std::string, Deck> list;

public:
  DeckList();
  void MakeMatchups();
  void Insert(pair<string, Deck> p);
  void ShowMenu(int _numDecks);
  void Winrate();
  void EnterAll();
  void RemoveDeck(Deck toRemove);
};
