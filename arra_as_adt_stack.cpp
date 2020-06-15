#include <iostream>
using namespace std;

struct Array
{
    /* data */
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    cout << "Elements of the array are : " << endl;
    for (int i = 0; i < arr.length; i++)
        cout << arr.A[i] << endl;
}

void append(struct Array *arr, int x){
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x){
    if (index >= 0 && index <= arr->length){
        for (int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index){
    int x = 0;
    if (index >=0 && index < arr->length){
        x = arr->A[index];
        for (int i = index; i < arr->length -1; i++)
            arr->A[i] = arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
}

void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct Array *arr, int key){
    int i;
    for (i = 0; i < arr->length; i++){
        if (key == arr->A[i]){
            Swap(&arr->A[i], &arr->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    int l = 0;
    int r = arr.length-1;
    while ( l <= r){
        int mid = (l + r)/2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] < key)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int RBinarySearch(struct Array arr, int l,int h,int key){
    int mid = 0;
    if ( l <= h){
        mid = (l + h)/2;
        if (key == arr.A[mid])
            return mid;
        else if ( key > arr.A[mid])
            return RBinarySearch(arr, mid+1, h, key);
        else
            return RBinarySearch(arr, l, mid - 1, key);
    }
    return -1;
}

int Get(struct Array arr, int index){
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(struct Array *arr, int index, int value){
    if (index >= 0 && index < arr->length)
        arr->A[index] = value;
}

int Max(struct Array arr){
    int max = arr.A[0],i;
    for (i = 1; i < arr.length; i++){
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0],i;
    for (i = 1; i < arr.length; i++){
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int Sum(struct Array arr){
    int sum = 0,i;
    for (i = 0; i < arr.length; i++)
        sum += arr.A[i];
    return sum;
}
float Avg(struct Array arr){
    return (float)Sum(arr) / arr.length;
}

int main(){
    struct Array arr = {{1,2,3,4,5},10,5};
    cout << RBinarySearch(arr, 0, 4, 2) << endl;
    Display(arr);
    return 0;
}