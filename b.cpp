#include <iostream>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *next;

    // Constructor to initialize
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

// Head Pointer
Node *head = NULL;

// Function to find the middle node of the list.
Node *MiddelNode()
{
    Node *slow = head;
    Node *fast = head;

    // Check if the list is empty
    if (head == NULL)
    {
        cout << "List is Empty";
        return NULL;
    }
    else
    {
        // Traverse the list with slow and fast pointers
        // When fast pointer reaches the end, slow pointer will be at the middle
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Return the middle node
        return slow;
    }
}

// Function to add new node at the end of the list
void insertEnd(int x)
{
    // Create a new node with given data
    Node *newNode = new Node(x);

    // Check if the list is empty
    if (head == NULL)
    {
        // If empty, make the new node as head
        head = newNode;
    }
    else
    {
        // Traverse to the end of the list
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
    }
}

void insertBegin(int x)
{
    Node *newNode = new Node(x);
     // Check if the list is empty
    if (head == NULL)
    {
        // If empty, make the new node as head
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

int main()
{
    // Insert some elements into the list
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);

    // Find and print the middle node
    Node *mid = MiddelNode();
    if (mid != NULL)
    {
        cout << mid->data << endl;
    }

    return 0;
}
