#include <iostream>
#include <string>
#include <array>
#include <regex>
#include "Deck.h"
#include "DeckList.h"
#include "Matchup.h"

using namespace std;

void EnterAll();
void Winrate();

/* Standard constructor for DeckList */
DeckList::DeckList() {
}

/* Initializes all the matchups for each deck */
void DeckList::MakeMatchups() {
  map<string, Deck>::iterator it = list.begin();
  while(it != list.end()) {
    map<string, Deck>::iterator it2 = list.begin();
    while(it2 != list.end()) {
      if(it == it2) {
        it2++;
        continue;
      }
      Matchup match(&(it->second), &(it2->second), 0, 0);
      it->second.matchups.push_back(match);
      it2++;
    }
    it++;
  }
}

/* Inserts the pair into the deck */
void DeckList::Insert(pair<string, Deck> p) {
  list.insert(p);
}

/* Shows all the scores
void DeckList::ShowMenu(int _numDecks) {
  for(auto pair : list) {
    cout << pair.first << ": " << list[pair.first].Scores() << endl;
  }
  bool inMenu = true;
  while(inMenu) {
    cout << endl << "Enter a command (type 'help' to see options): ";
    string command;
    cin >> command;
    if(command == "exit") {
      cout << endl << "Eurika!" << endl;
      inMenu = false;
    } else if(command == "EnterAll") {
      EnterAll();
    } else if(command == "Winrate") {
      Winrate();
    } else if(command == "help") {
      cout << "Commands: exit, EnterAll, Scores, RemoveDeck, or Winrate" << endl;
    } else if(command == "Scores") {
      ShowMenu(_numDecks);
      inMenu = false;
    } else if(command == "RemoveDeck") {
      string deckName;
      cout << "Enter a deck to remove: ";
      cin >> deckName;
      if(list.find(deckName) != list.end()) {
        RemoveDeck(list[deckName]);
      } else {
        cout << "Invalid name." << endl;
      }
    }
  }

}

void DeckList::Winrate() {
  map<string, Deck>::iterator it = list.begin();
  while(it != list.end()) {
    cout << it->first << " Winrate: " << it->second.GetWinrate() << endl;
    it++;
  }
}

void DeckList::EnterAll() {
  cout << "For the following, plese enter the score in the following format: W-L" << endl;
  regex wl("[0-9]+-[0-9]+");
  map<string, Deck>::iterator it = list.begin();
  array<string, 15> names; //15 is a hard-coded max as arrays won't let you use list.size().
  for(unsigned int i=0; it != list.end(); i++) {
    names[i] = it->first;
    it++;
  }

  for(unsigned int i=0; i<list.size(); i++) {
    for(unsigned int j=i+1; j<list.size(); j++) {
      string input;
      std::cout << names[i] << " vs " << names[j] << ": " << endl;
      std::cin >> input;

      if(regex_match(input, wl)) {// matches the regex,
      //add the number of wins and losses to each deck
        int divider = input.find('-');
        //enter a match to each deck
        Deck* opponent = &list[names[j]];
        list[names[i]].AddMatch(opponent, stoi(input.substr(0, divider).c_str()), stoi(input.substr(divider+1, input.size()).c_str()), false);
        //list[names[i]].ModifyScore(atof(input.substr(0, divider).c_str()), atof(input.substr(divider+1, input.size()).c_str()));
        //list[names[j]].ModifyScore(atof(input.substr(divider+1, input.size()).c_str()), atof(input.substr(0, divider).c_str()));
      } else{
        std::cout << "Enter a number, followed by a hyphen, followed by another number." << endl;
        return;
      }
    }
  }
}

void DeckList::RemoveDeck(Deck toRemove) {
    toRemove.RemoveGameHistory();
    list.erase(toRemove.name);
}
