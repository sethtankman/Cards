/* Addison Shuppy
Assignment 2, CS3505
*/
#ifndef MATCHUP_H //might not be right. used to say CAR_H
#define MATCHUP_H // PROTECTS AGAINST DUPLICATE INCLUDES

class Deck;

class Matchup {

public:
  Deck* self;
  Deck* opponent;
  int wins, losses;

  Matchup(Deck* _self, Deck* _opponent, int _wins, int _losses);
};

#endif
