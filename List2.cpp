#include <iostream>

using namespace std;

struct elem
{
    int value;
    elem* next = nullptr;
    elem* prev = nullptr;
};

struct list
{
    elem* first = nullptr;
    elem* last = nullptr;
    int count = 0;
};



void add_to_list(list& whole, int data)
{
    elem* newel = new elem;
    newel->value = data;
    whole.count++;
    if (!whole.first)
    {
        whole.first = whole.last = newel;
    }
    else
    {
        newel->prev = whole.last;
        whole.last->next = newel;
        whole.last = newel;
    }
}
void fill_the_list(list& whole, char* num)
{
    for (int i = 0; i < strlen(num); i++) add_to_list(whole, num[i] - '0');
}

void clear(list& whole)
{
    elem* rem;
    while (whole.first)
    {
        rem = whole.first;
        whole.first = whole.first->next;
        delete rem;
    }
    whole.last = nullptr;
    whole.count = 0;
}

void show_list(const list& whole, bool reversed = false)
{
    elem* curr = reversed ? whole.last : whole.first;
    if (!curr) cout << "Список пуст\n";
    else while (curr)
    {
        elem* cmp = reversed ? whole.first : whole.last;
        cout << curr->value << ((curr == cmp) ? "\n" : "");
        curr = reversed ? curr->prev : curr->next;
    }
}

void addition(list& whole, char* num1, char* num2)
{
    fill_the_list(whole, num1);
    elem* curr = whole.last;
    int value;
    for (int i = strlen(num2) - 1; i >= 0; i--)
    {
        value = num2[i] - '0';
        curr->value = curr->value + value;
        if (curr->prev) curr->prev->value = curr->prev->value + (curr->value / 10);
        curr->value = curr->value % 10;
        curr = curr->prev;
    }
    if (whole.first->value == 0)
    {
        elem* del = whole.first;
        whole.first = whole.first->next;
        delete del;
    }
    cout << endl;
}



int main()
{
    list whole;
    add_to_list(whole, 0);
    char* a = new char[9000];
    char* b = new char[9000];
    cin >> a;
    cin >> b;
    if (strlen(a) > strlen(b)) addition(whole, a, b);
    else addition(whole, b, a);
    show_list(whole);


    return 0;
}
