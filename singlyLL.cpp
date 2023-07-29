#include <iostream>
#include <map>
using namespace std;

// This file contains various linked list functions

class Node
{

public:
    int data;
    Node *next;
    Node *arb;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->arb = NULL; // Random pointer
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newnode = new Node(d);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    Node *prevnode = NULL;
    Node *currentNode = head;
    Node *nextNode = NULL;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevnode;
        prevnode = currentNode;
        currentNode = nextNode;
    }
    head = prevnode;
    return head;
}

void recurReverse(Node *&head, Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    recurReverse(head, curr, forward); // recusive call
    curr->next = prev;                 // processing
}

Node *recurReverse2(Node *&head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *chotahead = recurReverse2(head->next); // recursive call

    head->next->next = head;
    head->next = NULL;
    return chotahead;
}

Node *reverseK(Node *&head, int k, int length) // reverses the linked list into k groups
{
    // Base case
    if (head == NULL || head->next == NULL || k == 1 || length < k)
        return head;
    // Step 1 : Reverse first k nodes
    Node *nxt = NULL;
    Node *curr = head;
    Node *prev = NULL;

    int count = 1;
    while (curr != NULL && count <= k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    // Step 2 : Reverse next k nodes using recursion
    if (nxt != NULL)
    {
        head->next = reverseK(nxt, k, (length - k));
    }
    // Step 3 : Return head of the reversed linked list
    head = prev;
    return head;
}

int findMiddle(Node *&head)
{
    /*
    int length = getLength(head);
    int mid = (length / 2) + 1;
    Node *temp = head;
    for (int i = 1; i < mid; i++)
    {
        temp = temp->next;
    }
    return temp->data;
    */

    // optimized:
    if (head == NULL || head->next == NULL)
    {
        return head->data;
    }
    // if (head->next->next == NULL)
    // {
    //     return head->next->data;
    // }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{

    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head, Node *&tail)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            cout << "present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

Node *getStartingNode(Node *head) // gets the starting node of a loop
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node *head)
{

    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

Node *sortList(Node *head) // sorts list containing only 0,1 & 2
{

    int zC = 0;
    int oC = 0;
    int tC = 0;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
            zC++;
        else if (temp->data == 1)
            oC++;
        else if (temp->data == 2)
            tC++;
        temp = temp->next;
    }

    temp = head;
    while (temp)
    {
        if (zC != 0)
        {
            temp->data = 0;
            zC--;
        }
        else if (oC != 0)
        {
            temp->data = 1;
            oC--;
        }

        else if (tC != 0)
        {
            temp->data = 2;
            tC--;
        }
        temp = temp->next;
    }
    return head;
}

Node *MergeTwoSortedLists(Node *first, Node *second)
{
    Node *sortedList = new Node(-1);
    Node *listhead = sortedList;
    Node *head = sortedList;
    Node *alias = sortedList;
    while (first != NULL && second != NULL)
    {
        if (first->data <= second->data)
        {
            sortedList->next = first;
            first = first->next;
            sortedList = sortedList->next;
        }
        else
        {
            sortedList->next = second;
            second = second->next;
            sortedList = sortedList->next;
        }
    }

    while (first != NULL)
    {
        sortedList->next = first;
        first = first->next;
        sortedList = sortedList->next;
    }

    while (second != NULL)
    {
        sortedList->next = second;
        second = second->next;
        sortedList = sortedList->next;
    }

    sortedList->next = NULL;
    head = head->next;
    alias->next = NULL;
    delete alias;

    return head;
}

Node *addTwoLists(Node *first, Node *second)
{
    first = reverse(first);
    second = reverse(second);
    Node *ans = new Node(-1);
    Node *head = ans;
    int carry = 0;
    while (first != NULL && second != NULL)
    {
        int sum = first->data + second->data + carry;
        Node *newnode = new Node(sum % 10);
        ans->next = newnode;
        ans = ans->next;
        carry = sum / 10;
        first = first->next;
        second = second->next;
    }
    while (first != NULL)
    {
        int sum = first->data + carry;
        Node *newnode = new Node(sum % 10);
        ans->next = newnode;
        ans = ans->next;
        carry = sum / 10;
        first = first->next;
    }
    while (second != NULL)
    {
        int sum = second->data + carry;
        Node *newnode = new Node(sum % 10);
        ans->next = newnode;
        ans = ans->next;
        carry = sum / 10;
        second = second->next;
    }
    if (carry > 0)
    {
        Node *newnode = new Node(carry);
        ans->next = newnode;
    }
    Node *deldummy = head;
    head = head->next;
    deldummy->next = NULL;
    delete deldummy;
    head = reverse(head);
    return head;
} // Time complexity= O(m+n), Space complexity= O(max(m,n))

Node *copyList(Node *head) // creates a clone of a linked list with also random pointers in it
{
    // Step 1: clone the list
    Node *clonehead = NULL;
    Node *clonetail = NULL;
    Node *temp = head;

    while (temp != NULL)
    {
        insertAtTail(clonehead, clonetail, temp->data);
        temp = temp->next;
    }

    // step 2: clone nodes add in between original list
    Node *originalnode = head;
    Node *clonenode = clonehead;

    while (originalnode != NULL && clonenode != NULL)
    {
        Node *next = originalnode->next;
        originalnode->next = clonenode;
        originalnode = next;

        next = clonenode->next;
        clonenode->next = originalnode;
        clonenode = next;
    }

    // step 3: copy random pointers
    temp = head;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            temp->next->arb = temp->arb ? temp->arb->next : temp->arb;
        }
        temp = temp->next->next;
    }

    // step 4: revert changes done in step 2

    originalnode = head;
    clonenode = clonehead;
    while (originalnode != NULL && clonenode != NULL)
    {
        originalnode->next = clonenode->next;
        originalnode = originalnode->next;

        if (originalnode != NULL)
        {
            clonenode->next = originalnode->next;
        }
        clonenode = clonenode->next;
    }

    // step 5: returning the ans
    return clonehead;
}

// MergeSort Function O(n*logn)
Node *mergelist(Node *l1, Node *l2)
{
    Node *ptr = new Node(0);
    Node *curr = ptr;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }

        curr = curr->next;
    }

    // for unqual length linked list

    if (l1 != NULL)
    {
        curr->next = l1;
        l1 = l1->next;
    }

    if (l2 != NULL)
    {
        curr->next = l2;
        l2 = l2->next;
    }

    return ptr->next;
}

Node *sortList(Node *head)
{
    // If List Contain a Single or 0 Node
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = NULL;
    Node *slow = head;
    Node *fast = head;

    // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;       // slow increment by 1
        fast = fast->next->next; // fast incremented by 2
    }
    temp->next = NULL; // end of first left half

    Node *l1 = sortList(head); // left half recursive call
    Node *l2 = sortList(slow); // right half recursive call

    return mergelist(l1, l2); // mergelist Function call
}

int main()
{

    //     //created a new node
    //     Node* node1 = new Node(10);
    //     //cout << node1 -> data << endl;
    //    // cout << node1 -> next << endl;

    //     //head pointed to node1
    //     Node* head = node1;
    //     Node* tail = node1;
    //     //print(head);

    //     insertAtTail(tail, 12);

    //     //print(head);

    //     insertAtTail(tail, 15);
    //     //print(head);

    //     insertAtPosition(tail,head, 4, 22);
    //     //print(head);

    //     //cout << "head " << head -> data << endl;
    //     //cout << "tail " << tail -> data << endl;

    //     //deleteNode(4, head);

    //     tail -> next = head ->next;

    //     cout << "head " << head -> data << endl;
    //     cout << "tail " << tail -> data << endl;
    //     //print(head);

    //     if(floydDetectLoop(head) != NULL) {
    //         cout << "Cycle is present " << endl;
    //     }
    //     else
    //     {
    //         cout << "no cycle" << endl;
    //     }

    //     Node* loop = getStartingNode(head);

    //     cout << "loop starts at " << loop -> data  << endl;

    //     removeLoop(head);
    //     print(head);

    //     /*
    //     print(head);

    //     if(isCircularList(head)) {
    //         cout << " Linked List is Circular in nature" << endl;
    //     }
    //     else{
    //         cout << "Linked List is not Circular " << endl;
    //     }
    //     */

    Node *n = new Node(10);
    Node *head = n;
    Node *tail = n;
    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    print(head);
    cout << endl
         << "At head: " << head->data << ", at tail: " << tail->data << endl;
    deleteNode(5, head, tail);
    print(head);
    cout << endl
         << "At head: " << head->data << ", at tail: " << tail->data << endl;

    return 0;
}