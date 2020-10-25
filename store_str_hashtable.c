#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define SIZE 50
#define TABLESIZE 101

char *hashtable[TABLESIZE];

int calculate_hash(char* s) {
    const int prime = 31;
    const int m = TABLESIZE;
    int hash_value = 0, prime_pow = 1;
    for (int i = 0; i < strlen(s); i++) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * prime_pow) % m; //considering lower case letters
        prime_pow = (prime_pow * prime) % m;
    }
    return hash_value;
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
    int* storeindex = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        int hash = calculate_hash(words[i]);
        while(hashtable[hash] != NULL){
                hash = (hash + 1) % TABLESIZE;
        }
        if (hashtable[hash] == NULL){
            hashtable[hash] = malloc(strlen(words[i]) + 1);
            strcpy(hashtable[hash], words[i]);
            storeindex[i] = hash;
        }
    }
    
    printf("\nHash key, Hash value (strings):\n");
    for (i = 0; i < n; i++) {
        printf("%d, %s\n", storeindex[i], words[i]);
        //free(words[i]); 
    }
    return 0;
}
