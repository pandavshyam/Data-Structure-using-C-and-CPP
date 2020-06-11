#include <iostream>
using namespace std;

int fun(int x){
    int y = 1;
    while (y <= x)
    {   
        cout << y << endl;
        y++;
    }
    
}

int main(){
    int n = 3;
    fun(n);
    return 0;
}