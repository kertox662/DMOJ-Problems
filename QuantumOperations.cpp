/*
Link to problem:
https://dmoj.ca/problem/ccc05s3
*/

#include <iostream>
#include <climits>
#include <array>
#define MAX_SIZE 1024
#define INF LONG_MAX

using namespace std;

int tensor[MAX_SIZE][MAX_SIZE];
int numMatrix;
pair<int,int> curSize;

int main(){
    cin >> numMatrix;
    int hI,wI;
    cin >> hI >> wI;
    curSize = {hI,wI};
    for(int i = 0; i < hI; i++){
        for(int j = 0; j < wI; j++){
            cin >> tensor[i][j];
        }
    }

    for(int m = 1; m < numMatrix; m++){
        int w, h;
        cin >> h >> w; 
        int next[h][w];
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> next[i][j];
            }
        }

        int product[MAX_SIZE][MAX_SIZE];

        for(int i = 0; i < curSize.first; i++){
            for(int j = 0; j < curSize.second; j++){
                int factor = tensor[i][j];
                for(int y = 0; y < h; y++){
                    for(int x = 0; x < w; x++){
                        product[i * h + y][j * w + x] = factor*next[y][x];
                    }
                }
            }
        }

        curSize = {curSize.first*h, curSize.second*w};
        for(int i = 0; i < curSize.first; i++){
            for(int j = 0; j < curSize.second; j++){
                tensor[i][j] = product[i][j];
            }
        }
    }

    cout << curSize.first << ',' << curSize.second << endl;
    pair<long,long> extremas{INF,-INF};
    for(int i = 0; i < curSize.first; i++){
        for(int j = 0; j < curSize.second; j++){
            int val;
            val = tensor[i][j];
            if(val < extremas.first) extremas.first = val;
            if(val > extremas.second) extremas.second = val;
        }
    }
    cout << extremas.second << endl;
    cout << extremas.first << endl;
    pair<long,long> extremeCol{INF, -INF}, extremeRow{INF,-INF};
    
    for(int i = 0; i < curSize.first; i++){
        int rowSum = 0;
        for(int j = 0; j < curSize.second; j++){
            rowSum += tensor[i][j];
        }
        if(rowSum < extremeRow.first) extremeRow.first = rowSum;
        if(rowSum > extremeRow.second) extremeRow.second = rowSum;
    }

    cout << extremeRow.second << endl;
    cout << extremeRow.first << endl;

    for(int j = 0; j < curSize.second; j++){
        int colSum = 0;
        for(int i = 0; i < curSize.first; i++){
            colSum += tensor[i][j];
        }
        if(colSum < extremeCol.first) extremeCol.first = colSum;
        if(colSum > extremeCol.second) extremeCol.second = colSum;
    }

    cout << extremeCol.second << endl;
    cout << extremeCol.first << endl;

    return 0;
}
