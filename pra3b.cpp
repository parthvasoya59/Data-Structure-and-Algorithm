#include<iostream>
 using namespace std;
 void Merge(int *a,int low,int ub,int mid)
 {
     int i,j,k,b[ub-low+1];
     i=low;
     k=0;
     j=mid+1;

     while(i<=mid && j<=ub)
     {
         if(a[i]<a[j])
         {
             b[k]=a[i];
             k++;
             i++;
         }
         else
         {
             b[k]=a[j];
             k++;
             j++;
         }
     }

     while(i<=mid)
     {
         b[k]=a[i];
         k++;
         i++;
     }

     while(j<=ub)
     {
         b[k]=a[j];
         k++;
         j++;
     }

     for(i=low;i<=ub;i++)
     {
         a[i]=b[i-low];
     }

 }

 void MergeSort(int *a,int low,int ub)
 {
     int mid;

     if(low<ub)
     {
         mid=(low+ub)/2;
         MergeSort(a,low,mid);
         MergeSort(a,mid+1,ub);
         Merge(a,low,ub,mid);
     }

 }

int main()
{
     cout<<"Parth Vasoya \n 18DCS134 \n";
     int i,n;
     cout<<"\nEnter the number of data elements to be sorted :";
     cin>>n;

     int a[n];

     for(i=0;i<n;i++)
     {
        cout<<"Enter the element "<<i+1<<": ";
        cin>>a[i];
     }

     MergeSort(a, 0, n-1);
	 cout<<"\nSorted Data : ";
	 for (i = 0; i< n; i++)
         cout<<" "<<a[i];

	return 0;

 }
