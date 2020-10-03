#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int profit;
	int weight;
}item;

int compare_item(const item* x, const item* y){
	
	float r1 = (((float) x->profit) / x->weight);
	float r2 = (((float) y->profit) / y->weight);

	return ( (r1 < r2) - (r1 > r2) );
}
float frac_knapsack_profit(item* list, int n, int c){
    int weight_so_far = 0;
    float total_profit = 0;
    int i = 0;
    
    qsort(list, n, sizeof(item), (int(*)(const void *, const void *))compare_item);
    while (weight_so_far < c) {
        if (list[i].weight < (c - weight_so_far)) {
        	weight_so_far += list[i].weight;
          total_profit += list[i].profit;
          i++;
          }
		
        else {
          total_profit += ((c - weight_so_far) * ((float) list[i].profit / list[i].weight));
          weight_so_far = c;
        }
        }
	return total_profit;
}

int main() {
	int c, n, i;
	printf("Enter the capacity of the knapsack: ");
	scanf("%d", &c);
	
	printf("Enter the no. of items: ");
	scanf("%d", &n);
	
	item* list;
	list = (item *) malloc(n * sizeof(item));
	
	printf("Enter the item's profit and weight [space separated]: ");
	
	for (i = 0; i < n; i++) {
		scanf("%d %d", &list[i].profit, &list[i].weight);
	}
	
	float total_profit = frac_knapsack_profit(list, n, c);
	printf("The total profit (upto 3 decimal places) is %.3f\n", total_profit);
	
	free(list);
	return 0;
}
