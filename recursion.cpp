/* The process in which a function calls itself 
directly or indirectly is called recursion and the corresponding function is called as recursive function. */

#include <iostream>
using namespace std;

int factorial(int x){
    if ( x == 1 ){
        return 1;
    } else{
         return x * factorial(x-1);
    }
}

int main(){
    int n;
    cout << "Enter number to find factorial: " << endl;
    cin >> n;
    cout << factorial(n) << endl;
}
