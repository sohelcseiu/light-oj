#include<stdio.h>
int main()
{
    int t,a,b=0,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&a);
        b=a/2;
        a=a-b;
        printf("%d %d\n",b,a);
    }
    return 0;
}
