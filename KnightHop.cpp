/*
Link to problem:
https://dmoj.ca/problem/ccc10j5
*/

#include <iostream>
#include <queue>
#include <tuple>
#include <set>

using namespace std;

queue<tuple<int,int,int> > moveQueue; //Queue for Breadth First Search
set<tuple<int,int,int> > visited; //Stored visited squares so BFS doesn't repeat unneccessarily

int main(){
    int startx, starty, endx, endy;
    cin >> startx >> starty >> endx >> endy;
    startx--; //Puts coordinates between 0 and 7, technically not needed
    starty--;
    endx--;
    endy--;
    pair<int,int> endPos = {endx,endy};
    moveQueue.push({startx,starty,0}); //Start position in Queue (last in is how many moves it has taken to reach there)
    
    while(endPos != pair<int,int>{ std::get<0>(moveQueue.front()), std::get<1>(moveQueue.front()) } ){ //Sees if front of queue is the end pos
        tuple<int,int,int> curPos = moveQueue.front();
        visited.insert(curPos); //Put current position in set (won't have duplicates)
        int i = std::get<0>(curPos), j = std::get<1>(curPos), n = std::get<2>(curPos);
        for(int a = -2; a <= 2; a++){ //Makes the a 2x2 grid around the knight, this is the bounds for its moves
            for(int b = -2; b <= 2; b++){
                if(a == 0 || b == 0) continue; //If either the different in x or y (a or b) is 0, then we can skip since the knight move at least one in both directions
                if(abs(abs(a) - abs(b)) == 1){ //Sees if abs difference is 1 or -1, make difference table to see
                    int x = i+a, y = j + b; //New coordinates
                    if(x < 0 || y < 0 || x >= 8 || y >=8)continue; //Validates them to be in the grid
                    if(visited.find({x,y,n+1}) != visited.end()); //Sees if they've been visited already
                    moveQueue.push({x,y,n+1}); //If it is a new squares, marks for it to be visited
                }
            }
        }
        moveQueue.pop();
    }
    cout << std::get<2>(moveQueue.front()) << endl; //Once loop exits, we know that the front element is the end square. Its third value will have the amount of moves it took.
}