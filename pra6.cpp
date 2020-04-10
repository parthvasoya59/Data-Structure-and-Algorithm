#include <iostream>
#include <string>

using namespace std;

struct node
{
    string name;
    int prn;
    node *next;
};

class member
{
public:
    node *header1, *header2;
    member()
    {
        header1 = NULL;
        header2 = NULL;
    }

    node *create();
    int count(node *x);
    void add(node *head);
    void del(node *head);
    void display(node *head);
    void rdisplay(node *cn);
    void concatinate();
};
int member::count(node *x)
{
    node *cn = x;
    int count = 0;
    while (cn != NULL)
    {
        count++;
        cn = cn->next;
    }
    return count;
}

node *member::create()
{
    char ch;

    node *head;
    node *nn = new node;
    head = nn;
    cout << "Enter Name of president : ";
    cin >> nn->name;
    cout << "Enter PRN of president : ";
    cin >> nn->prn;
    cout << endl;

    do
    {
        nn->next = new node;
        nn = nn->next;
        cout << "Enter Name of Member : ";
        cin >> nn->name;
        cout << "Enter PRN of Member : ";
        cin >> nn->prn;
        cout << endl;

        cout << "Do you want to enter another member? (Y or y if yes) : ";
        cin >> ch;
        cout << endl;

    } while (ch == 'Y' || ch == 'y');

    nn->next = new node;

    nn = nn->next;

    cout << "Enter Name of secretary : ";
    cin >> nn->name;
    cout << "Enter PRN of secretary : ";
    cin >> nn->prn;
    cout << endl;

    nn->next = NULL;
    cout << "List is created! It has " << count(head) << " members!" << endl
         << endl;

    return head;
}

void member::display(node *head)
{

    node *nn;
    nn = head;

    cout << "President : " << nn->name << endl;
    cout << "PRN : " << nn->prn << endl
         << endl;
    nn = nn->next;

    for (int i = 0; nn->next != NULL; i++)
    {
        cout << "Member : " << nn->name << endl;
        cout << "PRN : " << nn->prn << endl
             << endl;
        nn = nn->next;
    }

    cout << "Secretary : " << nn->name << endl;
    cout << "PRN : " << nn->prn << endl
         << endl;

    cout << "List has " << count(head) << " members!" << endl
         << endl;
}

void member::rdisplay(node *cn)
{
    if (cn == NULL)
        return;

    rdisplay(cn->next);
    cout << cn->name << endl;
    cout << cn->prn << endl;
    cout << endl;
}

void member::add(node *head)
{
    int p;
    cout << "Enter the position where you want to add : ";
    cin >> p;

    node *nn, *temp;
    nn = head;

    node *an = new node;
    if (p == 1)
    {
        cout << "Enter Name of Member : ";
        cin >> an->name;
        cout << "Enter PRN of Member : ";
        cin >> an->prn;
        cout << endl;
        an->next = head;
        head = an;
        cout << "Member is added! List has " << count(head) << " members now!\n\n";
    }
    else if (p == count(head) + 1)
    {
        for (int i = 0; nn->next != NULL; i++)
        {
            nn = nn->next;
        }

        cout << "Enter Name of Member : ";
        cin >> an->name;
        cout << "Enter PRN of Member : ";
        cin >> an->prn;
        cout << endl;
        nn->next = an;
        an->next = NULL;

        cout << "Member is added! List has " << count(head) << " members now!\n\n";
        ;
    }
    else if (1 < p && p <= count(head))
    {
        for (int i = 1; i < p; i++)
        {
            temp = nn;
            nn = nn->next;
        }

        cout << "Enter Name of Member : ";
        cin >> an->name;
        cout << "Enter PRN of Member : ";
        cin >> an->prn;
        cout << endl;
        an->next = nn;
        temp->next = an;

        cout << "Member is added! List has " << count(head) << " members now!\n\n";
    }
    else
        cout << "Invalid Position!\n\n";
}

void member::del(node *head)
{
    int key;
    cout << "Enter the PRN of the student which is to be deleted : ";
    cin >> key;
    cout << endl;

    node *nn, *temp;
    nn = head;

    if (nn->prn == key)
    {
        head = nn->next;
        delete (nn);
        cout << "Member deleted! List has " << count(head) << " members now!\n\n";
    }
    else
    {
        while (nn->prn != key)
        {
            temp = nn;
            nn = nn->next;
        }

        if (nn->prn == key && nn->next == NULL)
        {
            temp->next = NULL;
            delete (nn);
            cout << "Member deleted! List has " << count(head) << " members now!\n\n";
        }
        else if (nn->prn == key)
        {
            temp->next = nn->next;
            delete (nn);
            cout << "Member deleted! List has " << count(head) << " members now!\n\n";
        }
        else
            cout << "Member not found!\n\n";
    }
}

void member::concatinate()
{
    node *cn = header1;
    while (cn->next != NULL)
        cn = cn->next;

    cn->next = header2;

    cout << "Lists of Division A and Division B are concatinated! Club has total " << count(header1) << " members now!\n\n";
}

int main()
{
    int choice;
    member m;
    cout<<endl<<"Parth Vasoya \n  18DCS134"<<endl;
    cout << "---------WELCOME TO PINNACLE CLUB------------" << endl<< endl;
    cout << "Create A division list: " << endl<< endl;
    m.header1 = m.create();
    cout << "Create B division list: " << endl
         << endl;
    m.header2 = m.create();

    while (true)
    {
        cout << endl
             << "Enter 1 to add a member in division A\nEnter 2 to add a member in division B\nEnter 3 to delete a member from division A\nEnter 4 to delete a member from division B\nEnter 5 to display division A list\nEnter 6 to display division B list\nEnter 7 to reverse display division A list\nEnter 8 to reverse display division B list\nEnter 9 to concatinate Division A and Division B\nEnter 10 to display concatinated list\nEssnter any other key to exit\nInput: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {

        case 1:
            m.add(m.header1);
            break;
        case 2:
            m.add(m.header2);
            break;
        case 3:
            m.del(m.header1);
            break;
        case 4:
            m.del(m.header2);
            break;
        case 5:
            m.display(m.header1);
            break;
        case 6:
            m.display(m.header2);
            break;
        case 7:
            m.rdisplay(m.header1);
            break;
        case 8:
            m.rdisplay(m.header2);
            break;
        case 9:
            m.concatinate();
            break;
        case 10:
            m.display(m.header1);
            break;
        default:
            return 0;
        }
    }
}
