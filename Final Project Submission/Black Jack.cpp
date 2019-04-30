// Blackjack

// This program allows the user to play the computer in blackjack until the player
// exits or loses all of their chips. The program also includes a rules menu to
// explain the game to players who so wish to learn. The cards are randomly generated
// 1-52 before being filtered down to their names values 2-11. Each number 1-52 generated
// is stored in an array, whose contents are read through each time a new number is
// generated so that if a duplicate number is generated it will get a new number, to
// ensure that no duplicate cards are dealt. The user bets at the beginning of each
// round, and their chip total is stored as a running total and displayed at the end of each round.

// NB: Because of the limited scope of this program, aces are always counted as 11s, and
// the user is not afforded the ability to double down or split hands.

// Created By: Brad Kerkhof
// Last Edit: April 29, 2019

#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;

// welcomes user to program and prompt ENTEr to continue
void welcomeStatement()
{
  cout << "\n\nWelcome to Brad's Blackjack Parlor!" << endl;
  cout << "You will be playing Blackjack against the dealer. (Press ENTER to continue)";
  cin.ignore (50, '\n'); // DEAL WITH LOOP
}

// returns menu selection from main menu
int getMainMenuChoice()
{
  int mainMenuChoice;


  cout << "\nBrad's Blackjack Parlor Menu: (Please ENTER an integer choice 1-3...)";
  cout << "\n____________________________";
  cout << "\n1.) Play Game";
  cout << "\n2.) Read Rules";
  cout << "\n3.) Exit";
  cout << "\nENTER your choice: ";
  cin >> mainMenuChoice;

  /* acounting for bad user input of same data type*/
  if (mainMenuChoice != 1 && mainMenuChoice != 2 && mainMenuChoice != 3)
    {
      cout << "\nError! Please ENTER an integer 1-3 only as your menu choice.";
      cout << "\n(Redirecting to Main Menu... Press ENTER to continue)";

      mainMenuChoice = 0;     /* setting mainMenuChoice = 0 for any value of
                              user input other than 1, 2, or 3 */
      cin.ignore(10, '\n');
    }

  return mainMenuChoice;
}

// returns menu selection from rules menu
int getRulesMenuChoice()
{
  int choice;
  cout << "\nBlackjack Rules: (Please ENTER an integer choice from the menu below...)"
       << "\n_______________"
       << "\n1.) Introduction to Blackjack"
       << "\n2.) Goal of the Game and Card Values"
       << "\n3.) Betting"
       << "\n4.) Dealing"
       << "\n5.) Playing"
       << "\n6.) Other Rules"
       << "\n7.) Show All Rules"
       << "\n8.) Return to Main Menu" << endl;

  cout << "\nENTER your choice: ";
  cin >> choice;

  if (choice>8||choice<1)       /* Accounting for bad input of correct type*/
  {
    cout << "Error! Please ENTER integer values 1-8 only.";
  }
  return choice;
}

// displays rules
void rules(int a)
{
  if (a==1||a==7)                /*nIntroduction to Blackjack*/
  {
    cout << "\nIntroduction to Blackjack:" << endl
    << "\tSecond to poker, Blackjack (also called Twenty-One) is the most popular "
    << "\nAmerican gambling card game. Though there exists more than a few different"
    << "\nversions of the rules, and though it is commonly played with numerous players"
    << "\nand one permanent dealer using 6 ordinary 52-card shuffled together ('Casino,"
    << "\nStyle'), in this program you will be playing against only the automated dealer,"
    << "\nwho will deal randomly from only one ordinary 52-card deck" << endl;
  }

  if (a==2||a==7)                /*Goals of the Game*/
  {
    cout << "\nGoal of the Game and Card Values:" << endl
    << "\tThe goal of the each round of the game is to get the sum of your hand as"
    << "\nclose to 21 as possible without going over, with face card beingg worth 10 and"
    << "\nnumber cards being worth their pip value. Aces, however, can be worth either 1"
    << "\nor 11, with the choice left to the player." << endl;
  }

  if (a==3||a==7)                /*Betting Rules*/
    cout << "\nBetting:" << endl
    << "\tBefore the deal begins, each player places a bet (in chips) in front of"
    << "\nhim/her, with the minimum and maximum bets established by the dealer. In this"
    << "\nIn this program, you will begin with 100 chips, and the minimum bet is 1 chip"
    << "\nand maximum 25 chips. If you have 25 or fewer chips at the start of a round,"
    << "\nyour maximum bet is the number of chips you have, with this bet being known"
    << "\nas 'All In.' If you enter a bet less than 1, you will bet 1 chip by default."
    << "\nSimilarly, if you enter a bet that exceeds the maximum, you deault bet will"
    << "\nbe the max of 25. If you enter a non-integer bet, you will default to betting"
    << "\nthe minimum." << endl;

  if (a==4||a==7)
  {
    cout << "\nDealing:" << endl
    << "\tOnce the cards are shuffled, the game is begun by the dealer giving both"
    << "\nhimself and the player(s) one card each, face-up. The dealer then deals the"
    << "\nplayer(s) a second face-up card before dealing himself one card face down, so"
    << "\nthat the player has two face up cards,and the dealer one face-up, one face-down." << endl;
  }

  if (a==5||a==7)
  {
    cout << "\nPlaying:" << endl
         << "\tOnce bets have been placed and cards dealed, play begings with"
         << "\nthe dealer asking the player whether they would like to 'hit' or 'stay.'"
         << "\nIf the player decides to stay, their total is simply that of their current"
         << "\nhand. Otherwise if the player hits, they are given another face up card,"
         << "\nat which point they can hit again or stay with the new total hand. If, in"
         << "\nhitting, the player's total ever exceeds 21, the player 'busts' and loses"
         << "\nby default. Otherwise, once the player stays, their turn is ended, and they"
         << "\nthey wait for the dealer to play in order to determine a winner." << endl;

    cout << "\tWhen the dealer has served the player(s), his face-down card is"
         << "\nturned up. If the total is 17 or more, he must stand. If the total is"
         << "\n16 or under, he must take a card and must continue to take cards until"
         << "\nthe total is 17 or more, at which point the dealer must stand. If the"
         << "\ndealer has an ace, and counting it as 11 would bring his total to 17 or"
         << "\nmore (but not over 21), he must count the ace as 11 and stand. The dealer's"
         << "\nare in this way pre-ordained on all plays, whereas the player always the"
         << "\noption of taking one or more additional cards. Once the dealer's turn is"
         << "\nfinished, his hand is compared the player's to determine a winner." << endl;
  }

  if (a==6||a==7)
  {
    cout << "\nOther Rules:" << endl
         << "\tIf a player is delt some face card AND an ace, this is called"
         << "\nBlackjack, and the player wins automatically. If the dealer has Blackjack"
         << "\nand the player does not, the dealer wins by defult, even if the player"
         << "\nhas 21." << endl;

    cout << "\n\tIf a player's first two cards are of the same denomination,";
    cout << "\nfor example two jacks or two sixes, the player can choose to 'split' his"
         << "\nhand and play future dealt cards on either one. A bet equal to the original"
         << "\nbet is placed on each card, and the player continues a chance to win or"
         << "\nlose on each." << endl;

    cout << "\n\tAnother option open to the player is doubling his bet when the"
         << "\noriginal two cards dealt total 9, 10, or 11. When the player's turn"
         << "\ncomes, he places a bet equal to the original bet, and the dealer"
         << "\ngives him just one card, which is placed face down and is not turned"
         << "\nup until the bets are settled at the end of the hand. With two fives,"
         << "\nthe player may split a pair, double down, or just play the hand in the"
         << "\nregular way. Note that the dealer does not have the option of splitting"
         << "\nor doubling down." << endl;
  }

  cout << "\nPLEASE NOTE: due to the somewhat limited scope of this program,"
       << "\nthis game will NOT be played with the Split or Double Down options offered"
       << "\nto the user, and aces will always be counted as 11s." << endl;
}

// geneates and returns first card out of 52
int getPlayerCard_1()
{
  int playerCard_1 = rand()%52 +1;
  return playerCard_1;
}

// generates and returns next card out of 51 remaining possibilities
int getDealerCard_1(int playerCard_1)
{
  int dealerCard_1 = rand()%52 +1;
  int exclude = playerCard_1;

  while (dealerCard_1 == exclude)
    dealerCard_1 = rand()%52 +1;

  return dealerCard_1;
}

// generates and returns next card out of 50 remaining possibilities
int getPlayerCard_2 (int playerCard_1, int dealerCard_1)
{
  int exclude_1 = playerCard_1;
  int exclude_2 = dealerCard_1;

  int playerCard_2 = rand()%52 +1;

  while (playerCard_2 == exclude_1 || playerCard_2 == exclude_2)
    playerCard_2 = rand()%52 +1;

  return playerCard_2;
}

// generates and returns next card out of 49 remaining possibilities
int getDealerCard_2(int playerCard_1, int playerCard_2, int dealerCard_1)
{
  int exclude_1 = playerCard_1;
  int exclude_2 = dealerCard_1;
  int exclude_3 = playerCard_2;

  int dealerCard_2 = rand()%52 +1;

  while (dealerCard_2 == exclude_1 || dealerCard_2 == exclude_2 || dealerCard_2 == exclude_3)
    dealerCard_2 = rand()%52 +1;

  return dealerCard_2;
}

// gives string name of each card
string cardName (int n)
{
  string cardName;

  if (n>=1 && n<=4)
    cardName = "Ace";
  else if (n>=5 && n<=8)
    cardName = "2";
  else if (n>=9 && n<=12)
    cardName = "3";
  else if (n>=13 && n<=16)
    cardName = "4";
  else if (n>=17 && n<=20)
    cardName = "5";
  else if (n>=21 && n<=24)
    cardName = "6";
  else if (n>=25 && n<=28)
    cardName = "7";
  else if (n>=29 && n<=32)
    cardName = "8";
  else if (n>=33 && n<=36)
    cardName = "9";
  else if (n>=37 && n<=40)
    cardName = "10";
  else if (n>=41 && n<=44)
    cardName = "Jack";
  else if (n>=45 && n<=48)
    cardName = "Queen";
  else if (n>=49 && n<=52)
    cardName = "King";
  else
    cout << "Error in generating cards; please close the program and try again!";
  return cardName;
}

// returns int value 2-11 of each card
int cardValue(int n)
{
  int cardNumber;
  if (n>=1 && n<=4)
    cardNumber = 11;
  else if (n>=5 && n<=8)
    cardNumber = 2;
  else if (n>=9 && n<=12)
    cardNumber = 3;
  else if (n>=13 && n<=16)
    cardNumber = 4;
  else if (n>=17 && n<=20)
    cardNumber = 5;
  else if (n>=21 && n<=24)
    cardNumber = 6;
  else if (n>=25 && n<=28)
    cardNumber = 7;
  else if (n>=29 && n<=32)
    cardNumber = 8;
  else if (n>=33 && n<=36)
    cardNumber = 9;
  else if (n>=37 && n<=52)
    cardNumber = 10;
  else
    cout << "\nError in generating cards; please close the program and try again!";
  return cardNumber;
}

// totals hand and displays which cards were dealt to user
int dealPlayerHand(int value_1, int value_2, string name_1, string name_2)
{
  int handTotal = value_1+value_2;
  cout << "\nYou have been dealt a " << name_1 << " and a " << name_2;
  cout << "\nYour hand is " << handTotal;
  return handTotal;
}

// totals hand and displays the one face up card dealth to dealer
int dealDealerHand(int value_1, int value_2, string name_1, string name_2)
{
  int handTotal = value_1+value_2;
  cout << "\nThe dealer is showing a " << name_1;
  return handTotal;
}

// looks at dealt hand to determine whether the player or dealer has an immediate win by blackjack
bool isBlackjack(int hand)
{
  if (hand == 21)
    return true;
  else
    return false;
}

bool willHit()
{
  int hitStayChoice;
  cout << "\nHit or Stay?"
       << "\n___________"
       << "\nENTER '1' to Hit"
       << "\nENTER '2' to Stay"
       << "\n\nYour choice: ";
  cin >> hitStayChoice;
  if (hitStayChoice==1)
    return true;
  else if (hitStayChoice==2)
    return false;
  else
  {
    cout << "Error! Invalid Choice. Your turn is over";
    return false;
  }
}

// returns int 1-52 corresponding to next card dealt, exlcuding values of those in play, which are stored in array
int giveAnotherCard(int array[])
{
  int nextCard;
  nextCard = rand()%52 +1;
  for(int count=0; count<52; count++)
  {
    if (nextCard == array[count])
    {
      nextCard = rand()%52 +1;
      count = -1;
      continue;
    }
  }
    return nextCard;
}

// returns true if player has won, false if dealer has won; player busts addressed separately
bool determineWinner(int a, int b)
{
  if (a > b) /*user has greater hand, no busts*/
  {
    cout << "\nYour hand is greater than the dealer's!";
    return true;
  }
  else if (a==b)
  {
    cout << "\nYou tied the dealer! You win!";
    return true;
  }

  else if (b > 21) /*dealer busted, user low, so user wins*/
  {
    cout << "\nThe dealer busted!";
    return true;
  }
  else            /*user has lower hand, dealer wins*/
  {
    cout << "\nYour hand is less than the dealer's!";
    return false;
  }
}

// main game fucntion
int main()
{
  bool didWin, blackJack, hitOrStay;
  string playerCard_1_Name, playerCard_2_Name, dealerCard_1_Name, dealerCard_2_Name, nextCardName;
  int betAmount, playerCard_1, playerCard_2, dealerCard_1, dealerCard_2, nextCard,
      playerCard_1_Value, playerCard_2_Value, dealerCard_1_Value, dealerCard_2_Value, nextCardValue;
  int mainMenuChoice=0;
  char playAgainChoice='Y';
  srand(time(0));

  welcomeStatement();

  do
  {
    mainMenuChoice = getMainMenuChoice();

    /* accounting for bad user input of wrong data type in main menu selection*/
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(50, '\n');
      cout << "\nERROR! Please enter only integer values. Press ENTER to continue...";
      cin.ignore(50, '\n');
      continue;
    }

    else if (mainMenuChoice==0)          /*Bad data reset*/
      continue;

    else if (mainMenuChoice==3)          /* exit */
      cout << "\n\nGoodbye!\n\n";

    else if (mainMenuChoice==2)          /* rules */
    {
      int rulesMenuChoice = getRulesMenuChoice();
      rules(rulesMenuChoice);
    }

    else if (mainMenuChoice==1)          /* MAIN GAME LOOP */
    {
      int chipTotal=100;
      cout << "\n\nThe game is about to begin. You will start with 100 chips. The minimum";
      cout << "\nbet is 1 chip, and the maximum is 25 chips. You will bet before each"
           << "\nhand is delt.";

      while (playAgainChoice=='Y'||playAgainChoice=='y')
      {
        int cardsInPlay[52];
        for (int n=0; n<52; n++)
          cardsInPlay[n]=0;
        int playerTotal=0, dealerTotal=0, cardCount=4;

        cout << "\n\nThe round is about to begin...";
        cout << "\nPlease ENTER your bet (as an integer) for this round: ";
        cin >> betAmount;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore(50, '\n');
          cout << "\nERROR! Please enter only integer values. Press ENTER to continue...";
          cin.ignore(50, '\n');
          continue;
        }
        else if(betAmount>25)
          betAmount=25;
        else if(betAmount<1)
            betAmount=1;
        else if(betAmount>chipTotal)
        {
          cout << "\nYou do not have that many chips! Betting All In...";
          betAmount=chipTotal;
        }
        cout << "\nYour bet for this round is " << betAmount << " chip(s).";
        cout << "\nPress ENTER to begin the deal...";
        cin.ignore(50, '\n');

// Deal, show hands, and check for blackJack
        // Values out of 52; loaded into array of dealt cards
        playerCard_1 = getPlayerCard_1();
        dealerCard_1 = getDealerCard_1(playerCard_1);
        playerCard_2 = getPlayerCard_2(playerCard_1, dealerCard_1);
        dealerCard_2 = getDealerCard_2(playerCard_1, dealerCard_1, playerCard_2);
        cardsInPlay[0]=playerCard_1;
        cardsInPlay[1]=playerCard_2;
        cardsInPlay[2]=dealerCard_1;
        cardsInPlay[3]=dealerCard_2;

        //Convert number out of 52 to number 2-11
        playerCard_1_Value = cardValue(playerCard_1);
        playerCard_2_Value = cardValue(playerCard_2);
        dealerCard_1_Value = cardValue(dealerCard_1);
        dealerCard_2_Value = cardValue(dealerCard_2);

        // Values as pip values, displayed as a string
        playerCard_1_Name = cardName(playerCard_1);
        playerCard_2_Name = cardName(playerCard_2);
        dealerCard_1_Name = cardName(dealerCard_1);
        dealerCard_2_Name = cardName(dealerCard_2);

        // Display Result of Deal
        playerTotal = dealPlayerHand(playerCard_1_Value, playerCard_2_Value, playerCard_1_Name, playerCard_2_Name);
        blackJack = isBlackjack(playerTotal);
        if (blackJack)
        {
          chipTotal+=betAmount;
          cout << "\nYou have blackjack! You win!";
          cout << "\nYour win " << betAmount << " chips! You now have " << chipTotal << " chips!";
          cout << "\nPress ENTER to continue...";
          cin.ignore(50, '\n');
          cout << "\nStarting next round...";
          continue;
        }

        // Display Dealer's One Face Up Card
        dealerTotal = dealDealerHand(dealerCard_1_Value, dealerCard_2_Value, dealerCard_1_Name, dealerCard_2_Name);
        blackJack = isBlackjack(dealerTotal);
        cout << "\nPress ENTER to continue...";
        cin.ignore(10, '\n');

        hitOrStay = willHit();
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "\nERROR! Please enter only integer values. Press ENTER to continue...";
            cin.ignore(50, '\n');
            continue;
          }

        while (hitOrStay)                    // loop until player stays or busts
        {
          cardCount++;
          nextCard = giveAnotherCard(cardsInPlay);
          cardsInPlay[cardCount]=nextCard;
          nextCardValue = cardValue(nextCard);
          playerTotal += nextCardValue;
          nextCardName = cardName(nextCard);
          cout << "\nYou have been dealt a " << nextCardName;
          cout << "\nYour hand is now " << playerTotal;

          if (playerTotal>21)
          {
            cout << "\nYou bust!";
            break;
          }
          else
          {
            cout << "\nYour hand is now " << playerTotal;
            hitOrStay = willHit();
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(50, '\n');
                cout << "\nERROR! Please enter only integer values. Press ENTER to continue...";
                cin.ignore(50, '\n');
                continue;
            }
          }
        }

        if(playerTotal>21)                   // end round by player bust
        {
          chipTotal-=betAmount;
          cout << "\nYou lost " << betAmount << " chips!" << endl
               << "You now have " << chipTotal << " chips!" << endl;
        }

        else                                // player does not bust, dealer must play
        {
          cout << "\nThe dealer's other card is a " << dealerCard_2_Name;
          cout << "\nThe dealer's hand is now " << dealerTotal;

          if (blackJack)                    // end by dealer blackJack
          {
            chipTotal-=betAmount;
            cout << "\nThe dealer has blackjack! You lose!";
            cout << "\nYou now have " << chipTotal << " chips!";
            cout << "\nStarting next round...";
            continue;
          }

          // Dealer Turn
          else
          {
            if (dealerTotal >= 17 && dealerTotal <=21)
              cout << "\nThe dealer must stay";
            while(dealerTotal<17)
            {
              cout << "\nThe dealer must hit. Giving the dealer another card...";

              nextCard=giveAnotherCard(cardsInPlay);
              cardCount++;
              cardsInPlay[cardCount]=nextCard;
              nextCardValue = cardValue(nextCard);
              dealerTotal += nextCardValue;
              nextCardName = cardName(nextCard);
              cout << "\nDealer has been dealt a " << nextCardName;
              cout << "\nDealer's hand is now " << dealerTotal;
              if (dealerTotal >= 17 && dealerTotal <=21)
                cout << "\nThe dealer must stay";
            }
          }

          didWin = determineWinner(playerTotal, dealerTotal);

          if (didWin)
          {
            chipTotal+=betAmount;
            cout << "\nYou won " << betAmount << " chips!" << endl
                 << "You now have " << chipTotal << " chips!" << endl;
          }
          else
          {
            chipTotal-=betAmount;
            cout << "\nYou lost " << betAmount << " chips!" << endl
                 << "You now have " << chipTotal << " chips!" << endl;
          }
        }
        if(chipTotal==0)
        {
          cout << "\nYou are bankrupt!";
          break;
        }
        else
        {
          cout << "\nKeep Playing?"
               << "\n(Y/N): ";
          cin >> playAgainChoice;
          if (cin.fail())
          {
            cin.clear();
            cin.ignore(50, '\n');
            cout << "\nERROR! Please enter only Y/y or N/n characters. Press ENTER to continue...";
            cin.ignore(50, '\n');
            continue;
          }
        }
    }
    cout << "\nThanks for Playing! Redirecting to Main Menu...\n";
  }
  }
  while (mainMenuChoice != 3);

  return 0;
}
