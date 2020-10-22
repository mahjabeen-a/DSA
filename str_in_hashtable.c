#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define SIZE 50

long long calculate_hash(char* s) {
    const int prime = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0, prime_pow = 1;
    for (int i = 0; i < strlen(s); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * prime_pow) % m; //considering lower case letters
        prime_pow = (prime_pow * prime) % m;
    }
    return hash_value;
}

long long int* make_hashtable(char* words[N], int n){
    long long int* hashtable = (long long int*)malloc(n * (sizeof(long long int)));
    for (int i = 0; i < n; i++){
        hashtable[i] = calculate_hash(words[i]);
    }
    return hashtable;
}
int main() {
    char *words[N];
    char str[SIZE];
    int i, n, slen = 0; 
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++) {
        printf("Enter a string: ");
        fgets(str, SIZE, stdin);
        slen = strlen(str);
        if (str[slen-1] == '\n') {
            str[slen-1] = '\0';
        }
      
        words[i] = malloc(slen + 1);
        strcpy(words[i], str);
    }  
    long long int* htable = make_hashtable(words, n);
    
    printf("\nHash key, Hash value (strings):\n");
    for (i = 0; i < n; i++) {
        printf("%lld, %s\n", htable[i], words[i]);
        //free(words[i]); 
    }
    
    //free(htable);
    return 0;
}
