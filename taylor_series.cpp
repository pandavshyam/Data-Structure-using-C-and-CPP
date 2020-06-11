#include <iostream>
using namespace std;

float e(int x, int n){
    static float p=1, f=1;
    float r;

    if (n == 0)
        return 1;
    r = e(x,n-1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

float factorial(int n){
    float x=1;
    for (int i=1; i <=n; i++){
        x *= i;
    }
    return x;
}

float power2(int n, int m){
    float sum = 1;
    for (int i=0; i < m; i++)
        sum *= n;
    return sum;
}

float e1(int x, int n){
    float sum = 0.00;
    for (int i = 0; i < n; i++){
        sum += power2(x,i) / factorial(i);
    }
    return sum;
}

int main(){
    cout << e1(4,15) << endl;
}