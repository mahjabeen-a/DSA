#include <stdio.h>
#define N 20

void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

void heapify(int i, int n, int a[]){
    int maxi = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if ((left < n) && (right < n)) {
        maxi = (a[left] > a[right]) ? left : right;
        maxi = (a[maxi] > a[i]) ? maxi : i;
    }
    if (maxi != i){
        swap(&a[i], &a[maxi]);
        heapify(maxi, n, a);
    }
}

void heapsort(int a[], int n){
    for (int i = n/2 - 1; i >= 0; i--){
        heapify(i, n, a);
    }
    for (int i = n - 1; i > 0; i--){
        swap(&a[0], &a[i]);
        heapify(0, i, a);
    }
}

int main(){
    int n, arr[N], choice;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter 1 for integers, 2 for alphabets (char): ");
    scanf("%d", &choice);
    printf("Enter the elements:\n");
    switch (choice){
        case 1:{
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);
            heapsort(arr, n);
            printf("The array after performing heapsort is:\n");
            for (int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
        }
        break;
        case 2:{
            char ch; //sorting alphabets based on ASCII value
            for (int i = 0; i < n; i++){
                getchar();
                scanf("%c", &ch);
                arr[i] = ch;
            }
            heapsort(arr, n);
            printf("The array after performing heapsort is:\n");
            for (int i = 0; i < n; i++){
                printf("%c ", (char) arr[i]);
            }
        }
        break;
        default: printf("Invalid choice\n");
    }
    printf("\n");
    return 0;
}
