#include <stdio.h>


int nondecreasing(int * array, int length)
{
    int i;
    int lastend = 0;
    int sum = 0;
    int inorout = 0;
    for (i = 0; i < length - 1; ++i) {
        if (array[i] > array[i+1]) {
            if (inorout == 1) {
                // printf("%d to %d\n", lastend, i);
                sum += (i - lastend) * (i - lastend + 1) / 2;
                inorout = 0;
            }
        }
        else {
            if (inorout == 0) {
                lastend = i;
                inorout = 1;
            }
            if (i + 1 == length -1) {
                // printf("%d to %d\n", lastend, i+1);
                sum += (i+1 - lastend) * (i+1 - lastend + 1) / 2;
            }
        }
    }
    return sum;
    
    
    
}


int nonincreasing(int * array, int length)
{
    int i;
    //    for (i = 0; i < length; ++i) {
    //        printf("%d", array[i]);
    //    }
    //    printf("\n");
    
    int lastend = 0;
    int sum = 0;
    int inorout = 0;
    
    //in is 1, out is 0
    for (i = 0; i < length - 1; ++i) {
        if (array[i] < array[i+1]) {
            if (inorout == 1) {
                // printf("%d to %d\n", lastend, i);
                sum += (i - lastend) * (i - lastend + 1) / 2;
                inorout = 0;
            }
        }
        else {
            if (inorout == 0) {
                lastend = i;
                inorout = 1;
            }
            if (i + 1 == length -1) {
                // printf("%d to %d\n", lastend, i+1);
                sum += (i+1 - lastend) * (i+1 - lastend + 1) / 2;
            }
        }
    }
    return sum;
}


int main()
{
    
    int n,k;
    scanf("%d %d", &n, &k);
    
    int array[n];
    
    int i;
    
    for (i = 0; i < n; ++i) {
        scanf("%d", &array[i]);
        
    }
    
    int array2[k];
    int j;
    int l = 0;
    
    for (i = 0; i <= n-k; ++i) {
        for (j = i; j <= i + k - 1; ++j) {
            array2[l++] = array[j];
        }
        printf("%d\n", nondecreasing(array2, k) - nonincreasing(array2, k));
        l = 0;
    }
}
