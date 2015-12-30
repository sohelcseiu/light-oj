#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

int main () {
  int i,j,t,k,n,r;
  scanf("%d",&t);
  for(r=1;r<=t;r++)
  {
      scanf("%d%d",&n,&k);
  char a[n],c='A';
  printf("Case %d:\n",r);
  for(i=0;i<n;i++)
  a[i]=c++;
  j=0;
  do {
      for(i=0;i<n;i++)
    cout << a[i];
    cout<<endl;
    ++j;
    if(j==k)
    break;
  } while ( next_permutation (a,a+n) );

  }
  return 0;
}
