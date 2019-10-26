//ask user for number of decks, create that number of decks.
#include <iostream>
#include <string>
#include <array>
#include "Deck.h"
#include "DeckList.h"

using namespace std;

int main() {
  cout << "Enter number of decks: ";
  int numDecks;
  cin >> numDecks;
  if(numDecks > 30 || numDecks < 1) {
    cout << "Number of decks must be between 1 and 30." << endl;
    return 1;
  }

  //Deck* deckList = new Deck[numDecks];
  DeckList deckList;

  for(int i = 0; i < numDecks; i++) {
    cout << "Enter a name for deck " << (i+1) << " of " << numDecks << ": ";
    string currDeckName;
    cin >> currDeckName;
    Deck currDeck(currDeckName);
    pair<string, Deck> p (currDeckName, currDeck);
    deckList.Insert(p);
  }

  deckList.MakeMatchups();

  deckList.ShowMenu(numDecks);

  return 0;
}

//The deck class
// class Deck {
//    Deck(){
//        std::cout << "Enter a deck name: ";
//        std::cin << str::string deckName;
//    }

//ask user for input that specifies what to do with that information
// - rank them
// - view rank without games of a certain deck.
// - enter games for all decks
// - find the best decks to remove.
