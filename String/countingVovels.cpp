#include <iostream>
using namespace std;

int main()
{
    char test[] = "How are you";
    int i, vcount = 0, ccount = 0;
    for (i = 0; test[i] != '\0'; i++){
        if (test[i] == 'a' || test[i] == 'e' || test[i] == 'i' || test[i] == 'o' || test[i] == 'u' || test[i] == 'A' || test[i] == 'E' || test[i] == 'I' || test[i] == 'O' || test[i] == 'U'){
            vcount++;
        }
        else if ((test[i] >= 65 && test[i] <= 90) || (test[i] >= 97 && test[i] <= 122))
        {
            ccount++;
        }
    }
    cout << vcount << " " << ccount << endl;
    return 0;
}