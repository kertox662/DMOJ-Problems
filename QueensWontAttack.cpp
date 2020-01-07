/*
Link to problem:
https://dmoj.ca/problem/hkccc15j3
*/

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string line1;
    getline(cin, line1);
    int pos = line1.find(' ');
    int b_size = stoi(line1.substr(0,pos));
    int numQ = stoi(line1.substr(pos+1));

    int *board = new int[b_size * b_size];
    int *queens = new int[numQ*2];

    for(int i = 0; i < numQ * 2; i+=2){
        string queenIn;
        getline(cin, queenIn);
        int pos = queenIn.find(' ');
        queens[i] = stoi(queenIn.substr(0,pos));
        queens[i + 1] = stoi(queenIn.substr(pos+1));
    }

    int count = 0;
    for(int i = 0; i < b_size; i++){
        for(int j = 0; j < b_size; j++){
            bool bOk = true;
            for(int q = 0; q < numQ * 2 && bOk; q+=2){
                int dx = j - queens[q] + 1, dy = i - queens[q+1] + 1;
                if(dx == 0 || dy == 0 || abs(dx) == abs(dy)){
                    bOk=false;
                }
            }
            if(bOk){
                count++;
            }
        }
    }
    cout << count(board, board + b_size * b_size, 0) << endl;
    return 0;
}