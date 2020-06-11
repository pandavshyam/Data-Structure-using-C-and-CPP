#include <iostream>
using namespace std;

int power(int n, int m){
    if (m == 0)
        return 1;
    return power(n, m-1) * n;
}

int power1(int n, int m){
    if (m == 0)
        return 1;
    if (m % 2 == 0)
        return power1(n*n, m/2);
    else
        return power1(n*n, (m-1)/2)*n;
}

int power2(int n, int m){
    int sum = 1;
    for (int i=0; i < m; i++)
        sum *= n;
    return sum;
}

int main(){
    int n = 6, m = 2;
    cout << power2(n,m) << endl;
}