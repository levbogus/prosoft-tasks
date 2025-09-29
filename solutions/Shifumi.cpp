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
    string o;
    getline(cin, o);

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    if(o=="Scissors")    cout << "Stone" << endl;
    else if(o=="Hand")    cout << "Scissors" << endl;
    else if(o=="Stone")    cout << "Hand" << endl;
    else    cout << "Error" << endl;

}
