#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int w; // width of the building.
    int h; // height of the building.
    cin >> w >> h; cin.ignore();
    int n; // maximum number of turns before game over.
    cin >> n; cin.ignore();
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    char yb,xb;
    int maxX=w-1;
    int minX=0;
    int maxY=h-1;
    int minY=0;
    // game loop
    while (1) {
        string bomb_dir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bomb_dir; cin.ignore();

        yb = bomb_dir[0];
        xb = bomb_dir[1];       
        if(yb=='U') {
            maxY=y0;
            y0-=(maxY-minY)/2+(maxY-minY)%2;           
        }
        else if(yb=='D') {
            minY=y0;
            y0+=(maxY-minY)/2+(maxY-minY)%2;
        }

        if(xb=='R'||yb=='R') {
            minX=x0;
            x0+=(maxX-minX)/2+(maxX-minX)%2;
        }
        else if(xb=='L'||yb=='L') {
            maxX=x0;
            x0-=(maxX-minX)/2+(maxX-minX)%2;
        }
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;


        // the location of the next window Batman should jump to.
        cout << x0 <<' '<< y0 << endl;
    }
}
