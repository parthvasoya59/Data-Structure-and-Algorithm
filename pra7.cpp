#include <iostream>
using namespace std;

class Circular
{
private:
    int queue[5];
    int front = -1, rear = -1;

public:
    void insert(int x)
    {
        if (front == -1 && rear == -1)
        {
            queue[0] = x;
            front++;
            rear++;
        }
        else if (front == rear + 1)
        {
            cout << "\nQueue overflow";
        }
        else
        {
            rear++;
            if (rear > 4)
                rear = 0;
            queue[rear] = x;
        }
    }
    void deleteQ()
    {
        cout << "\nDeleted Element => " << queue[front];
        front++;
        if (front > 4)
            front = 0;
        cout << endl;
    }
};

int main()
{
    Circular c;
    cout << endl
         << "Parth Vasoya \n  18DCS134" << endl;
    int choice, val;
    char y = 'n';
    do
    {
        cout << "1.Insert\n2.Delete\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value you want to  insert :";
            cin >> val;
            c.insert(val);
            break;
        case 2:
            c.deleteQ();
            break;
        }
        cout << "Continue or not [y/n]";
        cin >> y;
    } while (y == 'y');
}
