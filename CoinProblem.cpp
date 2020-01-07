#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#define MAXCOIN 2000
#define MAXCOST 10001
#define MAXSTORE 100000
#define INF 20000

using namespace std;

short int coins[MAXCOIN];
short int results[MAXSTORE], amounts[MAXCOST];
pair<short int, short int> stores[MAXSTORE];
short int numCoin;
int numStores;

int main(){
    cin >> numCoin >> numStores;
    for(int i = 0; i < numCoin; i++){
        cin >> coins[i];
    }

    unordered_set<short int> availableCoins;
    int maxCost = 0;
    int maxCoin = 0;
    for(int i = 0; i < numStores; i++){
        short int cost, nCoin;
        cin >> cost >> nCoin;
        stores[i] = {cost, nCoin};
        if(nCoin > maxCoin)
            maxCoin = nCoin;
        if(cost > maxCost)
            maxCost = cost;
        availableCoins.insert(nCoin);
    }

    // for(int i : availableCoins)
    //     cout << i << endl;
    // cout << "=====" << endl;
    fill_n(amounts, MAXCOST, -1);
    amounts[0] = 0;
    for(short nCoin = 0; nCoin < maxCoin; nCoin++){
        for(int a = 0; a <= maxCost; a++){
            int sum = a + coins[nCoin];
            if(amounts[a] == -1 || sum > maxCost) 
                continue;
            if(amounts[sum] == -1 || amounts[a] + 1 < amounts[sum]){
                // cout << "sum" << sum << endl;
                amounts[sum] = amounts[a] + 1;
            }
        }
        for(int i = 0; i < numStores; i++){
            if(nCoin+1 == stores[i].second){
                results[i] = amounts[stores[i].first];
            }
        }
    }

    for(int i = 0; i < numStores; i++)
        cout << results[i] << endl;

}