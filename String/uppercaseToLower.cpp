#include <iostream>
using namespace std;

int main()
{
    char colors[] = "WeLcOmE";
    int i;
    for (i = 0; colors[i] != '\0'; i++){
        if (colors[i] >= 65 && colors[i] <= 90){
            colors[i] += 32;
        }
        else if (colors[i] >= 97 && colors[i] <= 122)
        {
            colors[i] -= 32;
        }
    }
    cout << colors << endl;
    return 0;
}