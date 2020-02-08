/*
Link to problem:
https://dmoj.ca/problem/ccc18j5
*/

#include <iostream>
#include <set>
#include <unordered_set>
#include <array>
#include <vector>
#include <queue>
#define MAX_PAGE 10001

using namespace std;

unordered_set<int> visited;
// queue<pair<int,int>> pageQ;
pair<int,int> pageQ[MAX_PAGE] = {{0,0}}; 
array<vector<int>, MAX_PAGE> book;

int N, shortest = MAX_PAGE + 1;

void traverse(){
    pair<int,int> cur;

    int nextInd = 0;
    int nextAdd = 1;

    pageQ[0] = {1,1};
    visited.insert(1);

    while(pageQ[nextInd].first != 0){
        cur = pageQ[nextInd];
        nextInd++;
        int page = cur.first, l = cur.second;

        if(book[page].empty()){
            if(l < shortest) shortest = l;
        } 
        else{
            for(int p : book[page]){
                if(visited.find(p) != visited.end()) continue;
                visited.insert(p);
                pageQ[nextAdd] = {p,l+1};
                nextAdd++;
            }
        }
    }
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        int nc, curc;
        vector<int> c;
        cin >> nc;
        for(int i = 0; i < nc; i++){
            cin >> curc;
            c.push_back(curc);
        } 
        book[i] = c;
    }

    traverse();
    if(visited.size() == N){
        cout << "Y" << endl;
    } else{
        cout << "N" << endl;
    }

    cout << shortest << endl;

    return 0;
}