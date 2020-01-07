#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int w, h, x = 0, y = 0, dx, dy;
    cin >> w >> h;
    cin >> dx >> dy;
    while(dx != 0 || dy != 0){
        x += dx;
        y += dy;
        x = min(w,x);
        x = max(0,x);
        y = min(h,y);
        y = max(0,y);
        cout << x << ' ' << y << endl;
        cin >> dx >> dy;
    }
}