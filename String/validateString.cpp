#include <iostream>
using namespace std;

int main()
{
    char *test = "shyam@123";
    int i;
    for (i = 0; test[i] != '\0'; i++){
        if (!(test[i] >= 65 && test[i] <= 90) && !(test[i] >= 97 && test[i] <= 122) && !(test[i] >= 48 && test[i] <= 57)){
            return 0;
        }
        else
        {
            return 1;
        }

    }
    delete test;
}