#include <iostream>
using namespace std;

int fun(int x){
    static int p = 0;
    if ( x > 0){
        p++;
        return fun( x - 1) + p;
    }
    return 0;
}

int main(){
    int n = 5;
    cout << fun(n) << endl;;
}