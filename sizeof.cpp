/*The sizeof is a keyword, but it is a compile-time operator 
that determines the size, in bytes, of a variable or data type.*/
#include <iostream>
using namespace std;

int main(){
    int n[5] = {1,2,3,4,5};
    cout << sizeof(n)/sizeof(n[0]) << endl;
}