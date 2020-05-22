/* Function overloading is a feature in C++ where two or 
more functions can have the same name but different parameters.*/

#include <iostream>
using namespace std;

void printNumber(int x){
    cout << "This will print an Integer " << x << endl;
}

void printNumber(float x){
    cout << "This will print an Float " << x << endl;
}

int main(){
    int a = 10;
    float b = 21.5362;

    printNumber(a);
    printNumber(b);
}