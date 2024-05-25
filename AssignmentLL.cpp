#include<bits/stdc++.h>
using namespace std;

class Node{
public:

    int val;
    Node* next;

    Node(int data){
        val = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int val){
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void insertAtTail(Node* &head, int val){
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

void deleteAtK(Node* &head, int k){
    Node* temp = head;
    for(int i = 1; i <= k-1; i++){
        temp = temp->next;
    }
    Node* prev = temp->next;
    temp->next = temp->next->next;
    free(prev);
}

void InsertAtK(Node* &head, int val, int k){
    if (k == 0){
        insertAtHead(head, val);
        return;
    }
    Node* new_node = new Node(val);
    Node* temp = head;
    for(int i = 1; i <= k-1; i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
int findSize(Node* &head){
    Node* temp = head;
    int n = 0;
    while(temp){
        temp = temp->next;
        n++;
    }
    return n;
}
bool checkEmpty(Node* &head){
    Node* temp = head;
    int n = 0;
    while(temp){
        temp = temp->next;
        n++;
        if(n > 1) return true;
    }
    return false;
}
Node* rotateRight(Node* &head, int k){
    if(head == NULL || head->next == NULL) return head;
    Node* tail = head;
    Node* temp = head;

    int n = 0;
    while(temp != NULL){
        if(temp->next == NULL) tail = temp;
        temp = temp->next;
        n++;
    }
    k = k % n;

    if(k == 0) return head;
    int pos = n - k - 1;
    temp = head;
    for(int i = 1; i <= pos; i++){
        temp = temp->next;
    }
    tail->next = head;
    head = temp->next;
    temp->next = NULL;
    return head;
}
Node* ReverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;

    }
    Node* new_head = prev;
    return new_head;
}
Node* mergeTwoLists(Node* l1, Node* l2) {
    Node* c = new Node(0);
    Node* tail = c;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } 
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) {
        tail->next = l1;
    } 
    else {
        tail->next = l2;
    }
    return c->next;
}
Node* middleNode(Node* head) {
    Node* slow = head; 
    Node* fast = head; 

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;        
        fast = fast->next->next;  
    }

    return slow; 
}
int findElement(Node* head, int val) {
    int i = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == val) {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}
void splitList(Node* head, int index, Node* &a, Node* &b) {
    if (head == NULL || index <= 0) {
        a = head;
        b = NULL;
        return;
    }

    Node* c = new Node(0);
    Node* tailA = c;
    Node* temp = head;
    int count = 0;

    while (temp != NULL && count < index) {
        tailA->next = new Node(temp->val);
        tailA = tailA->next;
        temp = temp->next;
        count++;
    }

    a = c->next;
    b = temp;
}

int main(){
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    InsertAtK(head,0,2);
    return 0;
}