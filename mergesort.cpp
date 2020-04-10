#include<iostream>
using namespace std;

void merge(int left[],int right[],int a[],int nl,int nr)
  {
    int i=0,j=0,k=0;

    while(i<nl && j<nr)
    {
      if(left[i]<=right[j])
      {
        a[k]=left[i];
        i++;
      }
      if(left[i]>right[j])
      {
        a[k]=right[j];
        j++;
      }
      k++;
    }
    while(i<nl)
    {
      a[k]=left[i];
      k++;
      i++;
    }
    while(j<nr)
    {
      a[k]=right[j];
      k++;
      j++;
    }

  }

void mergesort(int a[],int n)
{
    if(n<2)
      return ;

    int mid=n/2;
    int left[mid];
    int right[n-mid];

    for (int i=0; i<mid; i++) {
      left[i]=a[i];
    }
    for(int j=0;j<n-mid;j++){
      right[j]=a[mid-j];
    }
    int nl=sizeof(left)/sizeof(left[0]);
    int nr=sizeof(right)/sizeof(right[0]);
    mergesort(left,nl);
    mergesort(right,nr);
    merge(left,right,a,nl,nr);

}



int main()
{
    int a[8]={2,4,6,3,8,9,1,7};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<"n = "<<n<<endl;
    mergesort(a,n);
    cout<<"Sorted Array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<a[i];
    }

}
