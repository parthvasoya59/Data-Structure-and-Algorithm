#include<iostream>
using namespace std;
class search
{
    int a[20],x,i,n,f,mid,key,q,p;
     public:
       void getdata();
       void lsearch(int m[20],int n);
       void ssearch(int m[20],int n);
       int bsearch(int m[20],int l,int r,int b);
       int fsearch(int m[20],int n);
       void display();
};
void search::getdata()
{   cout<<"\nEnter the no.s of rollno : ";
     cin>>n;
      for(i=0;i<n;i++)
      cin>>a[i];
}
void search::lsearch(int m[20],int n)
{   f=1;
      cout<<"\nEnter  the element to be searched : ";
      cin>>x;
      for(i=0;i<n;i++)
      {
           if(x==m[i])
           {   cout<<"\nRoll no. found at location : "<<i+1;    f=0;
               break;
            }
       }
       if(f==1)
            {  cout<<"\n  Rollno not found";    }
}
void search::ssearch(int m[20],int n)
{     m[n]=-1;  i=0;
      cout<<"\nEnter  the element to be searched : ";
      cin>>x;
    while((x!=m[i])&&(m[i]!=-1))
             i++;
            if(i<n)
            {      cout<<"\nRollno is found at location : "<<i+1;   }
            else
            {   cout<<"\n Roll no not found";                                       }

}
int search::bsearch(int m[20],int l,int r,int b)
{
        if(l<=r)
        {
          mid=(l+r)/2;
               if(b==m[mid])
                 return mid;
               else if(b>m[mid])
                return bsearch(m,(mid+1),r,b);
                 else if(b<m[mid])
                return bsearch(m,l,(mid-1),b);
           }
           return -1;
}
int search::fsearch(int m[20],int n)
{    int k,f[20]={0,1,1,2,3,5,8,13,21,44,65},flag=1;
        cout<<"\nEnter  the element to be searched : ";
      cin>>key;
      k=0;
         while(flag)
        {       if(f[k]>=n&&f[k-1]<n)
                {     break;   }
                  k++;
          }
         mid=n-f[k-2]+1;
      p=f[k-2];
      q=f[k-3];
      while(flag)
      {
         if(key<m[mid])
          {    if(q==0)
                    return -1;
               else
                 {   mid=mid-q;
                    p=f[k-3];
                    q=f[k-4];
                    }
             }
             if(key==m[mid])
            {     return mid;     }

             if(key>m[mid])
             {    if(p==1)
                   return -1;
                  else
                  {     mid=mid+q;
                          p=f[k-4];
                          q=f[k-5];
                   }
             }
           }
}
int main()
{
    search s;
    int c,d,v[20],w,i,j,choice,temp;
    cout<<"Parth Vasoya \n 18DCS134 \n";
    char ch;
    cout<<"\n How Many students :";
    cin>>d;
    cout<<endl<<"Enter the students Rollno."<<endl;

    for(i=0;i<d;i++)
        cin>>v[i];

    do{
        cout<<"\n1. Linear search";
        cout<<"\n2. Sentinel search";
        cout<<"\n3. Binary search";
        cout<<"\n4. Fibonacci search";
        cout<<"\n Enter your choice : ";
        cin>>choice;
        switch(choice)
            {
                case 1:
                    s.lsearch(v,d);
                    break;
                case 2:
                    s.ssearch(v,d);
                    break;
                case 3:
                    for(i=0;i<d;i++)
                    {
                        for(j=i+1;j<d;j++)
                        {
                            if(v[i]>v[j])
                            {
                                temp=v[i];
                                v[i]=v[j];
                                v[j]=temp;
                            }
                        }
                    }
                    cout<<"\nSorted array is... \n";
                    for(i=0;i<d;i++)
                        cout<<v[i]<<" ";
                    cout<<"\nEnter the roll no. to be searched : ";
                    cin>>c;
                    w=s.bsearch(v,0,(d-1),c);
                    if(w==-1)
                    {
                        cout<<"\n Roll no. not found ";
                    }
                    else
                    {
                        cout<<"\n Roll no. found at location : "<<w+1;
                    }
                    break;
                case 4:
                    for(i=0;i<d;i++)
                    {
                        for(j=i+1;j<d;j++)
                        {
                            if(v[i]>v[j])
                            {
                                temp=v[i];
                                v[i]=v[j];
                                v[j]=temp;
                            }
                        }
                    }
                    cout<<"\nSorted array is... \n";
                    for(i=0;i<d;i++)
                    cout<<v[i]<<" ";
                    w=s.fsearch(v,d);
                    if(w==-1)
                    {
                        cout<<"\n Roll no. not found ";
                    }
                    else
                    {
                        cout<<"\n Roll no. found at location : "<<w+1;
                    }
                    break;
                default:
                    cout<<"\n Invalid choice";
            }
            cout<<"\n Do you want to continue (y/n): ";
            cin>>ch;
          }while(ch=='y'||ch=='Y');
    return 0;
}
