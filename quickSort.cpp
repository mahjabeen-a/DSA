#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int small = low - 1;
    for (int large = low; large < high; large++){
        if (arr[large] < pivot) {
            small++;
            swap(arr[small], arr[large]);
        }
    }
    swap(arr[small + 1], arr[high]);
    return small + 1;
}

void quickSort(vector<int>& arr, int low, int high){
    if (low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
