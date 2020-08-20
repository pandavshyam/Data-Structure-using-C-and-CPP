#include <iostream>
using namespace std;

int main()
{
    char test[] = "malayalam";
    int i, j;
    for (i = 0; test[i] != '\0'; i++){}
    i = i - 1;
    for (j = 0; i >= j; i--, j++){
        if (!(test[j] == test[i])){
            cout << "Not Palindrome" << endl;
            break;
        }
    }
    return 0;
}