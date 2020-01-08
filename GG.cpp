/*
Link to problem:
https://dmoj.ca/problem/vmss7wc16c2p2
*/

#include <iostream>
#include <string>
#define MAXCHAR 100000

using namespace std;

int numBefore[MAXCHAR];
string gString;

int main(){
    cin >> gString;

    for(int i = 0; i < gString.length(); i++){
        int last;
        if(i == 0) last = 0;
        else last = numBefore[i-1];
        if(gString[i] == 'G')
            last += 1;
        numBefore[i] = last;
    }

    int numQuery;
    cin >> numQuery;
    for(int i = 0; i < numQuery; i++){
        int start, end;
        cin >> start >> end;
        int range;
        if(start == 0) range = numBefore[end];
        else range = numBefore[end] - numBefore[start-1];
        cout << range << endl;
    }

    return 0;
}