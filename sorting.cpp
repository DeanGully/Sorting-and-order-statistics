#include <iostream>
#include <vector>
using namespace std;
//Quick sort implementation
int getMedian(vector<int>& arr){
    int size = arr.size();
    if(size%2==0) return (arr[(size/2)]+arr[(size+1)/2])/2;//FIX THIS LATER
    else return arr[size/2];
}
int partitioning(vector<int>& arr, int startval, int endval) {
    int i = startval - 1; //starts index 0
    int pivot = arr[endval]; //pivot is last element
    for (int j = startval; j < endval; j++) {
        if (arr[j] <= pivot) {
            i++;
             swap(arr[i], arr[j]);
        }
    }
     swap(arr[i + 1], arr[endval]);
    return i + 1; //return i + 1 because pivot is now at i + 1
}
void quicksort( vector<int>& arr, int index1, int index2) {
    if (index1 < index2) {
        int rawr = partitioning(arr, index1, index2); 
        quicksort(arr, index1, rawr - 1); //this is left subarray
        quicksort(arr, rawr + 1, index2); //this is right subarray
    }
}
int main() {
    vector<int> arr;
    int n = 4; //size of array
    for (int i = 0; i < n; i++) {
        arr.push_back(rand() % 100); //random numbers between 0 and 99
    }
    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout <<  endl;
    quicksort(arr, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\nMedian is: " << getMedian(arr);
    return 0;
}
