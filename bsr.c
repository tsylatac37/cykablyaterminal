//Binary Search using recursive functions
#include <stdio.h>
int bs(int a[], int t, int l, int h) {
    int m = (l + h) / 2;

    if (l > h) {
        return -1;
    } 
    else if (t == a[m]) {
        return m;
    } 
    else if (t < a[m]) {
        return bs(a, t, l, m - 1);
    } 
    else {
        return bs(a, t, m + 1, h);
    }
}

int main() {
    int a[] = {2, 3, 4, 5, 6};
    int t = 3;
    int n = sizeof(a) / sizeof(a[0]);
    int r = bs(a, t, 0, n - 1);

    if (r == -1) {
        printf("Key %d not found\n", t);
    } else {
        printf("Key %d found at position %d\n", t, r);
    }

    return 0;
}
