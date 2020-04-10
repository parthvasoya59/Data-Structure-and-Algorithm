#include <stdio.h>
#include <iostream>
#include <string.h>
#define size 5

using namespace std;

struct doubleStack
{
    int stack[size];
    int topA, topB;
};
void pushA(struct doubleStack &s, int d)
{
    s.stack[++(s.topA)] = d;
}

void pushB(struct doubleStack &s, int d)
{
    s.stack[--(s.topB)] = d;
}
int popA(struct doubleStack &s)
{
    int popped_element = s.stack[(s.topA)];
    (s.topA)--;
    return (popped_element);
}
int popB(struct doubleStack &s)
{
    int popped_element = s.stack[(s.topB)];
    (s.topB)++;
    return (popped_element);
}
int empty(struct doubleStack &s)
{
    if ((s.topA == -1) && (s.topB == 1))
        return 1;
    return 0;
}
int full(struct doubleStack &s)
{
    if ((s.topA + 1 == s.topB) || (s.topA >= size) || (s.topB <= 0))
        return 1;
    return 0;
}
void display(struct doubleStack &s)
{
    if (empty(s))
    {
        cout << "stack is empty";
    }
    else
    {
        cout << "\nStack B is :";
        for (int i = s.topB; i <= size - 1; ++i)
            cout << "  " << s.stack[i];
        cout << "\nStack A is :";
        for (int j = s.topA; j >= 0; --j)
            cout << "  " << s.stack[j];
    }
}
int main()
{
    struct doubleStack twoStack;
    int item;
    char choice;
    int q = 0;
    twoStack.topA = -1;
    twoStack.topB = size;
    cout << "Parth Vasoya \n 18DCS134\n";
    cout << " \n-----Double Stack-----";
    do
    {
        cout << " \nPush to Stack A tap 1";
        cout << " \nPush to Stack B tap 2";
        cout << " \nPop  to Stack A tap 3";
        cout << " \nPop  to Stack B tap 4";
        cout << " \nTo Quit tap 5";

        cout << " \nInput the Choice.";
        do
        {
            cin >> choice;
        }

        while (strchr("11 12345 ", choice) == NULL);
        switch (choice)
        {
        case '1':
            cout << "\n Input the Element to be pushed:";
            cin >> item;
            if (!full(twoStack))
            {
                pushA(twoStack, item);
                cout << "\n After Inserting into Stack A.";
            }
            else
                cout << "\n Stack is now full.";
            break;
        case '2':
            cout << "\n Input the Element to be pushed:";
            cin >> item;
            if (!full(twoStack))
            {
                pushB(twoStack, item);
                cout << "\n After Inserting into Stack B.";
            }
            else
                cout << "\n Stack is now full.";
            break;
        case '3':
            if (!empty(twoStack))
            {
                item = popA(twoStack);
                cout << "\n Data is popped: " << item;
                cout << "\n Rest Data in Stack is as follows:\n";
            }
            else
                cout << "\n Stack Underflow.";
            break;
        case '4':
            if (!empty(twoStack))
            {
                item = popB(twoStack);
                cout << "\n Data is popped: " << item;
                cout << "\n Rest Data in Stack is as follows:\n";
            }
            else
                cout << "\n Stack Underflow.";
            break;
        case '5':
            q = 1;
        }
        display(twoStack);
    } while (!q);
    return 0;
}
