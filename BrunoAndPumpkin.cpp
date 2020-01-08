/*
Link to problem:
https://dmoj.ca/problem/gfsspc1p5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000

using namespace std;

int numGrown, want;
vector<int> leftP, rightP;

int main(){
    leftP.push_back(0);
    rightP.push_back(0);

    cin >> numGrown;
    cin >> want;

    for(int i = 0; i < numGrown; i++){
        int pumpkin;
        cin >> pumpkin;
        if(pumpkin < 0){
            leftP.push_back(-pumpkin);
        } else{
            rightP.push_back(pumpkin);
        }
    }

    sort(leftP.begin(), leftP.end());
    sort(rightP.begin(), rightP.end());

    int minDist = INF;

    for(int r = max(want - (int)leftP.size() + 1, 0); r < rightP.size(); r++){

        unsigned int startRight = 2*rightP[r] + leftP[want-r];
        unsigned int startLeft  = rightP[r] + 2*leftP[want-r];

        if(startRight < minDist)
            minDist = startRight;
        if(startLeft < minDist)
            minDist = startLeft;
    }

    cout << minDist << endl;

    return 0;
}