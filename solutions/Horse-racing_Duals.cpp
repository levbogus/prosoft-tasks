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
    int min=10000001;
    int n;
    cin >> n; cin.ignore(); 
    int horses[n];
    for (int i = 0; i < n; i++) {
        int pi;
        cin >> horses[i]; cin.ignore();
    }
    sort(horses,horses+n);
    for(int i=1; i<n; i++){
        if(horses[i]-horses[i-1]<min) min=horses[i]-horses[i-1];
    }
    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << min << endl;
}
