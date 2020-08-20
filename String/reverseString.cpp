#include <iostream>
using namespace std;

int main()
{
    char color[] = "shyam";
    char color1[6];
    int i,j;
    for (i = 0; color[i] != '\0'; i++){}
    i = i - 1;
    for (j = 0; i >= 0; i--, j++ ){
        color1[j] = color[i];
    }
    cout << color1 << endl;
    return 0;
}