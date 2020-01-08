/*
Link to problem:
https://dmoj.ca/problem/ccc07j5
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int minD, maxD;
int numExtra;

int main(){ 
    cin >> minD >> maxD >> numExtra;
    for(int i = 0; i < numExtra; i++){
        int extra;
        cin >> extra;
        motels.insert(extra);
    }


    vector<int> motelsV(motels.begin(), motels.end());
    vector<long> ways(motelsV.size(), 0);
    ways[0] = 1;

    for(int i = 0; i < ways.size(); i++){
        for(int j = i+1; j < ways.size(); j++){
            if(motelsV[j] - motelsV[i] > maxD) break;

            if(motelsV[j] - motelsV[i] >= minD){ 
                ways[j] += ways[i];
            }
        }
    }

    cout << ways[ways.size()-1] << endl;

    return 0;
}