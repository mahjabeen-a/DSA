#include<iostream>
#include<limits.h>
using namespace std; 

int minCoins(int V) { 
    if (V == 0)
        return 0; 
    static int denoms[3] = {3, 5, 10};
    int res = INT_MAX;
    int i;
    for (i = 0; i < 3; i++) { 
    	if (denoms[i] <= V) { 
    		int sub_res = minCoins(V - denoms[i]); 
    		if (sub_res == -1) 
    		    continue;
    		if (sub_res != INT_MAX && sub_res + 1 < res) 
    			res = sub_res + 1; 
    	} 
    } 
    if (i == 3 && res == INT_MAX)
        return -1;
        
    return res; 
} 

int main() {
	int V;
	cout << "Enter V\n";
	cin >> V;
	cout << "Minimum coins required is: "<< minCoins(V); 
	return 0; 
} 
