/*
Link to problem:
https://dmoj.ca/problem/ccc10s4
*/

#include <iostream>
#include <algorithm>
#include <array>
#include <map>
#include <unordered_set>
#include <queue>
#include <vector>
#define MAX_EDGE 801
#define INF 10000

using namespace std;

int N, C, w;
int corners[8];

map<pair<int,int>, int> edgeW;
map<pair<int,int>, pair<int,int> > edges;

struct heapComp{
    bool operator()(const pair<int,pair<int,int> > &a, const pair<int,pair<int,int> > &b) const {
        return a.first < b.first;
    }
};

int getMST(int skip = 1000){
    array<unordered_set<int>, 102> trees;
    for(int i = 0; i <= 100; i++) trees[i].insert(i);
    priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > edgeQ;
    int treeW = 0;
    for(auto e : edges){
        if (e.second.second == skip) continue;
        pair<int, pair<int,int> > p = {edgeW[e.first], e.second};
        edgeQ.push(p);
    }

    while(!edgeQ.empty()){
        auto p = edgeQ.top();
        edgeQ.pop();
        int p1 = p.second.first, p2 = p.second.second;
        
        bool found = false;
        for(int i : trees[p1]){
            if(trees[i].find(p2) != trees[i].end()) found = true; 
        }
        if(!found){
            vector<int> us(102);
            auto it = set_union(trees[p1].begin(),trees[p1].end(),trees[p2].begin(),trees[p2].end(), us.begin());
            us.resize(it - us.begin());
            unordered_set<int> uss(us.begin(), us.end());
            for(int i : uss) trees[i] = uss;
            treeW += p.first;
        }
    }
    return treeW;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> C;
        for(int j = 0; j < C; j++){
            cin >> corners[j];
        }

        for(int j = 0; j < C; j++){
            cin >> w;
            int m1 = min(corners[j], corners[(j+1)%C]);
            int m2 = max(corners[j], corners[(j+1)%C]);
            pair<int,int> p = {m1,m2};
            edgeW[p] = w;
            if(edges[p].first == 0){
                edges[p].first = i+1;
            } else{
                edges[p].second = i+1;
            }
        }
    }

    int t1,t2;
    t1 = getMST();
    t2 = getMST(0);
    cout << min(t1,t2) << endl;

    return 0;
}