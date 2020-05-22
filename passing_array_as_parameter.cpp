#include <iostream>
using namespace std;

void printArray(int test1[], int size_of_array){
    for (int i = 0; i < size_of_array; i++){
        cout << test1[i] << endl;
    }
}

int main(){
    int test[5] = {15,18,19,21,25};
    printArray(test,5);
}