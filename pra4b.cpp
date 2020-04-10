#include <iostream>
using namespace std;
void towerOfHanoi(int n,char beg,char endd,char aux)
{
    if (n==1)
    {
        cout << "Move disk 1 from " << beg <<  " to " << endd <<endl;
        return;
    }
    towerOfHanoi(n-1,beg,aux,endd);
    cout << "Move disk " << n << " from " << beg << " to " << endd << endl;
    towerOfHanoi(n-1,aux,endd,beg);
}
int main()
{
    int n = 4;
    cout<<endl<<"Parth Vasoya \n  18DCS134"<<endl;
    towerOfHanoi(n,'A','C','B');
    return 0;
}

