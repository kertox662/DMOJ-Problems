/*
Link to problem:
https://dmoj.ca/problem/3dconnect4
*/

#include <iostream>

using namespace std;

int main(){
    char pieces[6][6][6];
    char c;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                cin.get(c);
                while(c == '\n')
                    cin.get(c);
                pieces[i][j][k] = c;
            }
        }
    }

    int n = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int s = 0; s < 3; s++){
                bool x = true,y = true, z = true;
                for(int l = 0; l < 4; l++){
                    if(pieces[i][j][s+l] == 'Y') x = false;
                    if(pieces[i][s+l][j] == 'Y') y = false;
                    if(pieces[s+l][i][j] == 'Y') z = false;
                }
                if(x) n++;
                if(y) n++;
                if(z) n++;
            }
        }
    }
    if(n == 0) 
        cout << "lost" << endl;
    else
        cout << n << endl;
    
    return 0;
}