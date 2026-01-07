#include <stdio.h>

int ls(int a[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (a[i] == k) {
            return i; 
        }
    }
    return -1;  
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};  
    int k = 3;  
    int n = sizeof(a) / sizeof(a[0]);  

    int r = ls(a, n, k);  
    if (r == -1) {
        printf("%d Key not found\n", k);  
    } else {
        printf("%d key found at position %d\n", k, r);  
    }

    return 0;
}
