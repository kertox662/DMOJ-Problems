#include <iostream>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int nWins = 0, favTeam, played;
set<pair<int,int> > toDo;
map<int,int> score;

void getScores(map<int,int> score, set<pair<int,int> > toDo){
    if(toDo.size() == 0){
        int m = 0;
        for(int i = 1; i <= 4; i++){
            if(i == favTeam) continue;
            m = max(m, score[i]);
        }
        if (score[favTeam] > m ) nWins++;
    } else{
        map<int,int> aWins(score.begin(), score.end()), 
                     bWins(score.begin(), score.end()),
                     tie(score.begin(), score.end());

        pair<int,int> game = *toDo.begin();
        toDo.erase(toDo.begin());

        int A = game.first, B = game.second;
        aWins[A]+=3;
        bWins[B]+=3;
        tie[A]++;
        tie[B]++; 

        getScores(aWins, toDo);
        getScores(bWins, toDo);
        getScores(tie, toDo);
    }

    
}

int main(){
    for(int i = 1; i < 4; i++){
        for(int j = i+1; j <= 4; j++){
            toDo.insert({i,j});
        }
    }
    cin >> favTeam >> played;
    for(int i = 0; i < played; i++){
        int A, B, sA, sB;
        cin >> A >> B >> sA >> sB;
        toDo.erase(toDo.find({A,B}));
        if(sA > sB) score[A]+=3;
        else if(sB > sA) score[B]+=3;
        else{
            score[A]++;
            score[B]++;
        }
    }

    // for(auto p : toDo) cout << p.first << ' ' << p.second <<endl;

    getScores(score, toDo);
    cout << nWins << endl;

    return 0;
}