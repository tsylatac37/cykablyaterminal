// Online C compiler to run C program online
#include <stdio.h>
int maxsubseq(int a[], int n)
{
    int i,j,k,max=0,sum;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            sum=0;
            for(k=i;k<=j;k++)
            {
                sum+=a[k];
            }
            if(sum>max)
            {
                max=sum;
            }
        }
    }
    return max;
}
int main() {
    int a[]={-2,11,-4,13};
    int n=sizeof(a)/sizeof(a[0]);
    int r=maxsubseq(a,n);
    printf("Maximum subsequence sum %d ",r);
    return 0;
}
