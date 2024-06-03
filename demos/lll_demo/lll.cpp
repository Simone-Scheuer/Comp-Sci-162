#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct Node {
    int value;
    Node * next;
};


Node * create_node(int value)
{
    Node * new_node = new Node;
    new_node -> value = value;
    new_node -> next = nullptr;
    return new_node;
}


void append_node(Node ** head, int value)
{
    Node * new_node = create_node(value);
    if (*head == nullptr)
    {
        *head = new_node;
    } 
    else
    {
        Node * last_node = *head;
        while (last_node -> next != nullptr)
        {
            last_node = last_node -> next;
        }

        last_node -> next = new_node;

    }
}


void print_list(Node* head)
{
    while (head != nullptr) 
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node * head = nullptr;

    append_node(&head, 10);
    append_node(&head, 20);
    append_node(&head, 30);
    append_node(&head, 40);
    append_node(&head, 50);

    print_list(head);

    return 0;
}


