/*
Link to problem:
https://dmoj.ca/problem/ecoo17r1p3
*/

#include <string>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main() {
    for(int test = 0; test < 10; test++){
        int numM;
        cin >> numM;
        int *mounts = new int[numM];
        
        for(int i = 0; i < numM; i++) cin >> mounts[i];

        int *view = new int[numM];
        for(int i = 0; i < numM; i++){
            int sum = 0;
            double leftMin = 20000, rightMin = -20000;
            for(int j = i-1; j >= 0; j--){
                int dx = i - j, dy = mounts[i] - mounts[j];
                double slope = (double)dy / dx;
                
                if (slope < leftMin){
                    sum++;
                    leftMin = slope;
                }
            }

            for(int j = i+1; j < numM; j++){
                int dx = i - j, dy = mounts[i] - mounts[j];
                double slope = (double)dy / dx;
                if (slope > rightMin){
                    sum++;
                    rightMin = slope;
                }
                
            }
            view[i] = sum;
        }
        // for(int i = 0; i < numM; i++) cout << mounts[i] << ' ';
        // cout << endl;
        // for(int i = 0; i < numM; i++) cout << view[i] << ' ';
        // cout << endl;
        cout << distance(view,max_element(view, view + numM)) + 1 << endl;//' ' << *max_element(view, view + numM) << endl;
        delete[] view;
        delete[] mounts;
    }
}