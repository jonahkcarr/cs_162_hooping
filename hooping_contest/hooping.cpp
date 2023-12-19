/***************************************************************
** Program: hooping.cpp
** Author: Jonah CArr
** Date: 10/15/2023
** Description: Simulates the NBA 3-Point Shooting Contest
** Input: Player Response as an Integer
** Output: Shooting Results, Points Scored, and Fun Competition
***************************************************************/

#include <iostream> // always include for c++
#include <cstdlib> // used for psuedo random number generation


using namespace std;


void welcomeAndChoose(int &m, int playerTurn) { //pass in a reference which will return it to main function scope
    if (playerTurn == 1) {
        cout << endl << "Welcome to The Basketball Shooting Contest!" << endl << endl;
    }
    cout << "Player " << playerTurn << ":" << endl;
    cout << "Where do you want to put your money rack? (enter 1-5): ";

    string getNumStr;
    cin >> getNumStr;

    while(getNumStr != "1" && getNumStr != "2" && getNumStr != "3" && getNumStr != "4" && getNumStr != "5") { // check if string entered is correct input and continue until correct input
        cout << "Error, incorrect input, please type an integer 1, 2, 3, 4, or 5: "; // throw problem at user
        cin >> getNumStr; //get user input again
        cout << endl;
    }

    int getNumInt = stoi(getNumStr); //turn string to integer value


    m = getNumInt; // take input and put into referenced location
}


void missMake(int playerArr[]) { //adds misses and makes to array
    for(int i = 0; i < 27; i++) {
        playerArr[i] = rand()%2; // returns 1's and 0's
    }
}


void moneyRackAdjust(int moneyRackPosition, int playerArr[]) { //changes value for money rack

    if(moneyRackPosition == 1) { 
        for(int i = 0; i < 4; i++) { // only changes first 4, last one will be changed elsewhere because it is always worth 2pts
            playerArr[i] *= 2; // if shot value is 0, multiplying will not change outcome of shot. it will stay as a miss (0 in the code)
        }
    } else if(moneyRackPosition == 2) {
        for(int i = 5; i < 9; i++) {
            playerArr[i] *= 2;
        }
    } else if(moneyRackPosition == 3) {
        for(int i = 11; i < 15; i++) {
            playerArr[i] *= 2;
        }
    } else if(moneyRackPosition == 4) {
        for(int i = 16; i < 20; i++) {
            playerArr[i] *= 2;
        }
    } else if(moneyRackPosition == 5) {
        for(int i = 22; i < 26; i++) {
            playerArr[i] *= 2;
        }
    } else {} // else want nothing to happen
}


void AdjustScore(int playerArr[], int moneyRackPosition) { //makes 5th shot and starry shot worth more

    playerArr[4] *= 2; // this and following rows multiply the 5th shot of each row
    playerArr[9] *= 2;
    playerArr[15] *= 2;
    playerArr[20] *= 2;
    playerArr[26] *= 2;
    playerArr[10] *= 3; // 3 for starry racks
    playerArr[21] *= 3;

    moneyRackAdjust(moneyRackPosition, playerArr); // calls for money rack ball shots to be multiplied by two
}


void conversionTo(int playerArr[], char conversionArr[]) { // for every number saved in the array, it will convert it to a letter X, O, M, or W

    for(int i = 0; i < 27; i++) {

        if(playerArr[i] == 0) { //since all values in the array have already been changed to 0, 1, 2, or 3, just need to assign the letters
            conversionArr[i] = 'X';
        } else if(playerArr[i] == 1) {
            conversionArr[i] = 'O';
        } else if(playerArr[i] == 2) {
            conversionArr[i] = 'M';
        } else if(playerArr[i] == 3) {
            conversionArr[i] = 'W';
        } 

    }
}


int addScores(int playerArr[], int playerTurn, int &player1Score, int &player2Score) {
    int playerScore = 0;
    for(int i = 0; i < 27; i++) {
        playerScore += playerArr[i];
    }
    if(playerTurn == 1) {
        player1Score = playerScore;
    } else if(playerTurn == 2) {
        player2Score = playerScore;
    }
    return playerScore;
}

int addRack1(int playerArr[]) { // this and addRack() functions return points per rack
    int x = 0;
    for(int i = 0; i < 5; i++) {
        x += playerArr[i]; //adds each point for each of the 5 shots in this rack to be displayed after rack is printed
    }
    return x;
}

int addRack2(int playerArr[]) {
    int x = 0;
    for(int i = 5; i < 10; i++) {
        x += playerArr[i];
    }
    return x;
}

int addRack3(int playerArr[]) {
    int x = 0;
    for(int i = 11; i < 16; i++) {
        x += playerArr[i];
    }
    return x;
}

int addRack4(int playerArr[]) {
    int x = 0;
    for(int i = 16; i < 21; i++) {
        x += playerArr[i];
    }
    return x;
}

int addRack5(int playerArr[]) {
    int x = 0;
    for(int i = 22; i < 27; i++) {
        x += playerArr[i];
    }
    return x;
}


void printResults(char conversionArr[], int playerArr[], int playerTurn, int &player1Score, int &player2Score) {

    cout << endl << "Shooting Results:" << endl << endl; // double endl for more space

    cout << "Rack 1: ";
    for(int i = 0; i < 5; i++) {
        cout << conversionArr[i] << " "; // prints S
    }
    cout << " | " << addRack1(playerArr) << "pts" << endl;

    cout << "Rack 2: ";
    for(int i = 5; i < 10; i++) {
        cout << conversionArr[i] << " ";
    }
    cout << " | " << addRack2(playerArr) << "pts" << endl;
    
    cout << "Starry: " << conversionArr[10];
    cout << "          | " << playerArr[10] << "pts" << endl;
    
    cout << "Rack 3: ";
    for(int i = 11; i < 16; i++) {
        cout << conversionArr[i] << " ";
    }
    cout << " | " << addRack3(playerArr) << "pts" << endl;

    cout << "Rack 4: ";
    for(int i = 16; i < 21; i++) {
        cout << conversionArr[i] << " ";
    }
    cout << " | " << addRack4(playerArr) << "pts" << endl;

    cout << "Starry: " << conversionArr[21];
    cout << "          | " << playerArr[21] << "pts" << endl;
    
    cout << "Rack 5: ";
    for(int i = 22; i < 27; i++) {
        cout << conversionArr[i] << " ";
    }
    cout << " | " << addRack5(playerArr) << "pts" << endl << endl;

    cout << "Total: " << addScores(playerArr, playerTurn, player1Score, player2Score) << "pts" << endl << endl;
}

void compareScores(int player1Score, int player2Score) {
    if(player1Score > player2Score) {
        cout << "Player 1 Wins!" << endl << endl;
    } else if (player2Score > player1Score) {
        cout << "Player 2 Wins!" << endl << endl;
    } else if (player1Score == player2Score) {
        cout << "You Tie!" << endl << endl;
    }
}


int playAgain() {
    cout << "Do you want to play again? (enter 1-yes, 0-no): ";
    string x;
    cin >> x;

    while(x != "1" && x != "0") { //handles errors thrown by incorrect user input
        cout << "Error, incorrect input, please type 1 or 0: ";
        cin >> x;
        cout << endl;
    }

    int y = stoi(x); // converts string number to integer number
    return y;
}


int main() {
    do {
        srand(time(NULL));
        int playerTurn = 1;
        int player1Score = 0;
        int player2Score = 0;
        int moneyRackPosition;
        int playerArr[27];
        char conversionArr[27]; //used to convert the made vs missed shots to the letters that are displayed on the screen
        while(playerTurn <= 2) {
            welcomeAndChoose(moneyRackPosition, playerTurn);
            missMake(playerArr);
            AdjustScore(playerArr, moneyRackPosition);
            conversionTo( playerArr, conversionArr);
            printResults(conversionArr, playerArr, playerTurn, player1Score, player2Score);
            playerTurn++;
        }
        compareScores(player1Score, player2Score);

    } while (playAgain());
    return 0;
}




