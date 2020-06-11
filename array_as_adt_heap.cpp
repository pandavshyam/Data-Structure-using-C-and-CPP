#include <iostream>
using namespace std;

struct Array
{
    /* data */
    int *A;
    int size;
    int length;
};
void Display(struct Array arr){
    cout << "Elements are: " << endl;
    for (int i=0; i < arr.length; i++)
        cout << arr.A[i] << endl;;
}

int main(){
    struct Array arr;
    int n,i;
    cout << "Enter the size of array : " << endl;
    cin >> arr.size;
    arr.length = 0;
    cout << "Enter the number of numbers: " << endl;
    cin >> n;
    arr.A = new int[arr.size];
    cout << "Enter all elements: " << endl;
    for (int i=0; i < n; i++)
        cin >> arr.A[i];
    arr.length = n;
    Display(arr);
    delete[] arr.A;
    cout << arr.A;
    
    return 0;
}