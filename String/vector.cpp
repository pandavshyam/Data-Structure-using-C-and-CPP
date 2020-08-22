#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> colors;

    colors.push_back("Red");
    colors.push_back("Blue");
    for (int i = 0; i < colors.size(); i++){
        cout << colors[i] << "\n";
    }
    return 0;
}