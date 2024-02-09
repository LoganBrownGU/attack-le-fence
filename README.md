# attack-le-fence
Implementation of the classic card game "Attack Le Fence" in C++

## Rules
- Every player is dealt 3 cards.
- Choose 1 to form the shield, 2 to form the health.
- When a player loses all health, they are eliminated.
- On each turn, a player can either attack, swap a shield, or stash a card. 

### Stashing
- Stashing a card uses up the player's turn.
- Only 1 card can be stashed at any time. 

### Attacking
- A player can attack another with 1 or 2 cards.
- Attacking with 2 cards requires a stashed card. 
- If the value of the cards used to attack is greater than that of the attacked player's shield, then the attacked player loses that much health, minus the value of their shield.
- If a player is attacked with a value equal to the value of their shield, then the shield is doubled (using the cards that were played).
- If a player takes damage, they lose their stashed card, if they have one.
- If a player is left with 1 health after being attacked, they do double damage until they are eliminated. 

### Swapping shields
- Swapping a shield uses the player's turn.
- Any player's shield can be swapped, including the player's own.
- The player must take a card from the pile to swap; they cannot use a stashed card.
- If the value of the swapped card is equal to the shield, then the shield is doubled. 

### Dealing with health
- When a player loses health, their new health value generally needs to be reconstructed using other cards.
- The order in which this should be done is as follows:
  1. Check if the new health value is equal to one of the players current health cards.
  2. Check if either of the attacking cards could be used. 
  3. Check if any of the cards in the used pile can be used.
  4. Check if any of the cards currently in play can be used. 
  5. Check if any of the cards in the unused pile can be used.