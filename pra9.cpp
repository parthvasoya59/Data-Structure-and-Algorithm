#include<bits/stdc++.h>

using namespace std;

class BST
{
    string city;
    int x,y;
    BST *left,*right;

public:
    BST()
    {
        city="";
        x=0;
        y=0;
        left=right=NULL;
    }

    BST(string city,int x,int y)
    {
        this->city=city;
        this->x=x;
        this->y=y;
        left=right=NULL;
    }

    BST* Insert(BST *root,string city,int x,int y)
    {
        if(!root)
        {
            return new BST(city,x,y);
        }

        if((city.at(0))>(root->city.at(0)))
        {
            root->right=Insert(root->right,city,x,y);
        }

        else
        {
            root->left=Insert(root->left,city,x,y);
        }

        return root;
    }

    void Inorder(BST *root)
    {
        if(!root)
        {
            return;
        }

        Inorder(root->left);
        cout<<"City: "<<root->city<<" x:"<<root->x<<" y:"<<root->y<<"\n";
        Inorder(root->right);
    }

    void InorderByLocation(BST *root,int location)
    {
        if(!root)
        {
            return;
        }

        InorderByLocation(root->left,location);
        if(location>=(root->x))
        {
        cout<<"City: "<<root->city<<" x:"<<root->x<<" y:"<<root->y<<"\n";
        }
        InorderByLocation(root->right,location);
    }
};

int main()
{
    BST b,*root=NULL;
    cout<<endl<<"Parth Vasoya \n  18DCS134"<<endl;
    root=b.Insert(root,"Nadiad",70,20);
    b.Insert(root,"Vadodara",0,20);
    b.Insert(root,"Anand",55,20);
    b.Insert(root,"Ahemdabad",140,20);
    b.Insert(root,"Bakor",105,20);

    b.Inorder(root);

    cout<<"\nCheck all records within a given distance of a specified point.";
    cout<<"\nEnter point(x-coordinate)";
    int location;
    cin>>location;
    cout<<endl;
    b.InorderByLocation(root,location);

    return 0;
}

