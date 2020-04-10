#include <iostream>
#define SIZE 7
using namespace std;

class Queue
{
    int a[SIZE];
    int rear;
    int front;

public:
    Queue()
    {
        rear = front = -1;
    }

    void enqueue(int x)
    {
        if (front == -1)
        {
            front++;
        }
        if (rear == SIZE - 1)
        {
            cout << "Queue is full";
        }
        else
        {
            a[++rear] = x;
        }
    }
    int dequeue()
    {
        cout << "\nReceived Caller ID List :" << a[+front];
        return a[++front];
    }

    void display()
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            cout << a[i] << endl;
        }
    }
};

int main()
{
    int x;
    Queue q;
    cout<<endl<<"Parth Vasoya \n  18DCS134"<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter Caller ID. :";
        cin >> x;
        q.enqueue(x);
    }

    for (int i = 0; i < SIZE; i++)
    {
        q.dequeue();
    }
}
