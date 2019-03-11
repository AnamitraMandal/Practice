#include <stdio.h>
#include <stdlib.h>
void cofac(int A[],int i, int j, int tmp[], int n)
{
  int p,q,l,k;
  p=0;
  q=0;
  for(k=0;k<n;k++)
  {
    for(l=0;l<n;l++)
    {
      if(k!=i && l!=j)
      {
        tmp[p*(n-1)+q]=A[n*k+l];
        q++;
        if(q==n-1)
        {
          q=0;
          p++;
        }
      }
    }
  }
}
int det(int A[], int n)
{
  int D=0;

  if(n==1)
  {
    return A[0];
  }
  else
  {
    int *tmp=(int*)malloc(((n-1)*(n-1))*sizeof(int));
    int sn=1;
    int i;
    for(i=0;i<n;i++)
    {
      cofac(A,0,i,tmp,n);
      D += sn * A[i] * det(tmp, n - 1);
      sn=-sn;
    }
    return D;
  }
}
void adj(int A[],int ad[], int n)
{
  if(n==1)
   ad[0]=1;
  else
  {
    int sn=1;
    int i,j;
    int* temp=(int*)malloc(((n-1)*(n-1))*sizeof(int));
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        cofac(A,i,j,temp,n);
        if((i+j)%2==0)
         sn=1;
        else
          sn=-1;
        ad[j*n+i]=sn*(det(temp,n-1));
      }
    }
  }
}
void inv(int A[],float invs[],int n)
{
  int d=det(A,n);
  int  i,j;
  int* ad=(int*)malloc((n*n)*sizeof(int));
  adj(A,ad,n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      invs[i*n+j]=ad[i*n+j]/(float)d;
    }
  }
}
int main()
{

  int k;
  int i;
 // printf("Enter the order of the Matrix : ");
 // scanf("%d", &k);
 k=2;

  int* A=(int*)malloc((k*k)*sizeof(int));
  A[0]=1;
  A[1]=2;
  A[3]=4;
  A[2]=3;
  float* invs=(float*)malloc((k*k)*sizeof(float));
  printf("Enter the elements of %dX%d Matrix : \n", k, k);
 /* for (i = 0;i < k*k; i++)
    {
      scanf("%d", &A[i]);
    }*/
  inv(A,invs,k);
  for(i=0;i<k;i++)
  {
      for(int j=0;j<k;j++)
      printf("%d ",A[i*k+j]);
  }
  printf("%d",det(A,k));
  for (i = 0;i < k*k; i++)
    {
      printf("%f  ", invs[i]);
    }
return 0;
}
