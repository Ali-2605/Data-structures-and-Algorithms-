#include <iostream>
#include <cstdio>

class Node 
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;

public:
    LinkedList() : first(nullptr) {}

    LinkedList(int A[], int n) 
    {
        Node *last, *t;
        first = new Node;
        first->data = A[0];
        first->next = nullptr;
        last = first;

        for (int i = 1; i < n; i++) 
        {
            t = new Node;
            t->data = A[i];
            t->next = nullptr;
            last->next = t;
            last = t;
        }
    }

    ~LinkedList() 
    {
        Node *p = first;
        while (first) 
        {
            first = first->next;
            delete(p);
            p = first;
        }
    }

    void display() const 
    {
        Node *p = first;
        while (p) 
        {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("\n");
    }

    void displayRecursive(Node *p) const
    {
        if (p != nullptr) 
        {
            printf("%d ", p->data);
            displayRecursive(p->next);
        }
        else 
        {
            printf("\n");
        }
    }

    int length() const 
    {
        int len = 0;
        Node *p = first;
        while (p) 
        {
            len++;
            p = p->next;
        }
        return len;
    }

    int lengthRecursive(Node *p) const 
    {
        if (p == nullptr) return 0;
        return 1 + lengthRecursive(p->next);
    }

    int sum() const 
    {
        int sum = 0;
        Node *p = first;
        while (p) 
        {
            sum += p->data;
            p = p->next;
        }
        return sum;
    }

    int max() const 
    {
        int maxVal = first->data;
        Node *p = first;
        while (p) 
        {
            if (p->data > maxVal) 
            {
                maxVal = p->data;
            }
            p = p->next;
        }
        return maxVal;
    }

    bool search(int key) 
    {
        Node *p = first;
        Node *q = nullptr;
        while (p) 
        {
            if (p->data == key) 
            {
                if (q) 
                {
                    q->next = p->next;
                    p->next = first;
                    first = p;
                }
                return true;
            }
            q = p;
            p = p->next;
        }
        return false;
    }

    void insert(int index, int num) 
    {
        if (index < 0 || index > length()) 
        {
            printf("Invalid position\n");
            return;
        }

        Node *p = first;
        Node *q = new Node;
        q->data = num;

        if (index == 0) 
        {
            q->next = first;
            first = q;
        }
        else 
        {
            for (int i = 0; i < index - 1; i++) 
            {
                p = p->next;
            }
            q->next = p->next;
            p->next = q;
        }
    }

    int Delete(int index) 
    {
        if (index < 1 || index > length()) 
        {
            printf("Invalid position\n");
            return -1;
        }

        Node *p = first;
        Node *q = nullptr;
        int x = -1;

        if (index == 1) 
        {
            first = first->next;
            x = p->data;
            delete p;
        } 
        else 
        {
            for (int i = 0; i < index - 1 && p; i++) 
            {
                q = p;
                p = p->next;
            }
            if (p) 
            {
                q->next = p->next;
                x = p->data;
                delete p;
            }
        }
        return x;
    }

    void deleteDuplicates() 
    {
        Node *p = first;
        if (!p) return;

        while (p->next) 
        {
            if (p->data == p->next->data) 
            {
                Node *temp = p->next;
                p->next = p->next->next;
                delete temp;
            } 
            else 
            {
                p = p->next;
            }
        }
    }

    void reverse() 
    {
        Node *p = first;
        Node *q = nullptr, *r = nullptr;
        while (p) 
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        first = q;
    }
};

int main() 
{
    int A[] = {3, 5, 8, 8, 10};  // Example array to initialize the linked list
    LinkedList list(A, 5);

    // Display the list
    printf("List: ");
    list.display();

    // Display the length of the list
    printf("Length: %d\n", list.length());

    // Display the sum of all elements in the list
    printf("Sum of elements: %d\n", list.sum());

    // Display the maximum element in the list
    printf("Max element: %d\n", list.max());

    // Search for an element and move to the front if found
    int searchKey = 5;
    bool found = list.search(searchKey);
    printf("Search for %d: %s\n", searchKey, (found ? "Found" : "Not found"));

    // Display the list again to see if the search altered it
    printf("List after search: ");
    list.display();

    // Insert a new element at a specific index
    list.insert(2, 15);
    printf("List after inserting 15 at index 2: ");
    list.display();

    // Delete an element by index
    int deletedValue = list.Delete(3); 
    printf("Deleted value at index 3: %d\n", deletedValue);
    printf("List after deletion: ");
    list.display();

    // Delete duplicate elements
    list.deleteDuplicates();
    printf("List after deleting duplicates: ");
    list.display();

    // Reverse the linked list by links
    list.reverse();
    printf("List after reversing: ");
    list.display();

    return 0;
}