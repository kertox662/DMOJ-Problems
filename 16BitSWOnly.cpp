/*
Link to problem:
https://dmoj.ca/problem/16bitswonly
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int numLines;
    cin >> numLines;
    string *answers = new string[numLines];
    for(int i = 0; i < numLines; i++){
        long f1, f2, p;
        cin >> f1 >> f2 >> p;
        if (f1*f2 == p) answers[i] = "POSSIBLE DOUBLE SIGMA";
        else answers[i] = "16 BIT S/W ONLY";
    }

    for(int i = 0; i < numLines; i++) cout << answers[i] << endl;
    
    return 0;
}