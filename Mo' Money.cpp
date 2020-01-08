/*
Link to problem:
https://dmoj.ca/problem/si17c1p8
*/

#include <iostream>
#define MAXCOINS 15

using namespace std;

int coins[MAXCOINS];
int nCoin, target;
int numWays;

void getWays(int index = 0, int total = 0){
    if(index > nCoin){
        if(total == target){
            numWays++;
        }
    }
    else{
        getWays(index+1, total); //Don't add current coin
        getWays(index+1, total + coins[index]); //Add Current Coin
    }
}

int main(){
    cin >> nCoin >> target;
    for(int i = 0; i < nCoin; i++){
        cin >> coins[i];
    }

    getWays();
    cout << numWays/2 << endl;
}