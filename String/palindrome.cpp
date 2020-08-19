#include <iostream>
using namespace std;

string Reverse(char color[]){
    int i, j;
    char copy[6];
    for (i = 0; color[i] != '\0'; i++){}
    i = i - 1;
    for (j = 0; i >=0; j++, i--){
        copy[j] = color[i];
    }
    return copy;
}

int Equal(char color[], char reversed[]){
    int i,j;
    for ( i = 0, j = 0; color[i] != '\0' && reversed[i] != '\0'; i++, j++){
        if (color[i] != reversed[i])
            return 0;
    }
    return 1;
}

int main(){
    char color[] = "maam";
    char reversed[6] = Reverse(color);
    cout << Equal(color, reversed) << endl;
    return 0;
}