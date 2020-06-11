#include <iostream>
using namespace std;

int fibbonacci(int n){
    int t0 = 0, t1 = 1, sum;
    for (int i = 2; i <= n; i++){
        sum = t0 + t1;
        t0 = t1;
        t1 = sum;
    }
    return sum;
}

int fibbonacci1(int n){
    if ( n <= 1)
        return n;
    return fibbonacci1(n-2) + fibbonacci1(n-1);
}

int fibbonacci2(int n){
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main(){
    cout << fibbonacci2(10) << endl;
}