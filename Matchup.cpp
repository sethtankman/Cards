#include "Matchup.h"
#include "Deck.h"

Matchup::Matchup(Deck* _self, Deck* _opponent, int _wins, int _losses) {
  self = _self;
  opponent = _opponent;
  wins = _wins;
  losses = _losses;
}
