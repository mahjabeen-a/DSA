#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void subsetSum(int eles[], int subset[], int eles_size, int subset_size, int curr_sum, int index, int target_sum){
    if (target_sum == curr_sum){
        display(subset, subset_size);
        //sorting -> if till a particular element we get some sum which becomes greater than targetsum, 
        //then no use in addding elements which are greater than the current element.
        // hence we recurse only if sum is less
        if(index + 1 < eles_size && curr_sum - eles[index] + eles[index + 1] <= target_sum){
            subsetSum(eles, subset, eles_size, subset_size - 1, curr_sum - eles[index], index + 1, target_sum);
        }
        return;
    }
    else{
        if(index < eles_size && curr_sum + eles[index] <= target_sum){
            for (int i = index; i < eles_size; i++){
                subset[subset_size] = eles[i];
                if(curr_sum + eles[i] <= target_sum){
                    subsetSum(eles, subset, eles_size, subset_size + 1, curr_sum + eles[i], i + 1, target_sum);
                }
            }
        }
        
    }
}

int comp(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void generateSubsets(int eles[], int eles_size, int target_sum){
    int* subset = (int*)malloc(eles_size * sizeof(int));
    int total = 0;
    
    
    qsort(eles, eles_size, sizeof(int), &comp);
 
    for(int i = 0; i < eles_size; i++ ){
        total += eles[i];
    }
 
    if(eles[0] <= target_sum && total >= target_sum){
        subsetSum(eles, subset, eles_size, 0, 0, 0, target_sum);
    }
    free(subset);
}

int main(){
   int set[] = { 1,2,3 };
   int size = sizeof(set) / sizeof(set[0]);
   printf("The set is ");
   display(set , size);
   generateSubsets(set, size, 3);
   
   return 0;
}
