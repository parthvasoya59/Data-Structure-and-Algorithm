#include<iostream>
using namespace std;
int main()
{
    int a[30],i,j,key,n;
    cout<<endl<<"Parth Vasoya \n  18DCS134"<<endl;
    cout<<"How many elements you want for sorting :: ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i =0;i<n;i++)
        cin>>a[i];
    for(int i =1;i<n;i++)
    {
        int key = a[i];
        int j=i-1;
        while((j>=0)&&(a[j]>key))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
    cout<<"Sorted Array : ";
    for(int i =0;i<n;i++)
        cout<<" "<<a[i];
}
