#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, mDif = 1000000001, prev, next;
    bool havePrev = false;

    cin >> n;

    for(int i = 0; i < n; i++){
        if(!havePrev) {
            cin >> prev;
            havePrev = true;
            continue;
        }

        cin >> next;
        mDif = min(mDif, next - prev);
        if(mDif == 0) break;
        prev = next;
    }
    if(mDif == 0) cout << 0 << endl;
    else cout << mDif + 1 << endl;
    return 0;
}