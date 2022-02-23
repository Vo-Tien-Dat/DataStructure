#include<iostream>

using namespace std;
struct NODE{
    int data; 
    NODE* next; 
    NODE(){
        this -> data = 0;
        this -> next = NULL;
    }
    NODE(int data){
        this -> data = data; 
        this -> next = NULL;
    }
};

struct Node{
    int val;
    Node* left;
    Node* right; 
    Node(int val){
        this -> val = val ; 
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

typedef Node* Tree;


void Add_Node_Tree(Tree& tree, int val){
    Node* node = new Node(val);

    if(tree == nullptr){
        Node* node = new Node(data);
        tree = node;
    }
    else{
        if(tree -> val > val)       Add_Node_Tree(tree -> left, val);
        if(tree -> val < val)       Add_Node_Tree(tree -> right, val);
    }
}


struct LINKEDLIST{
    NODE* head; 
    NODE* tail;
    LINKEDLIST(){
        this -> head = NULL;
        this -> tail = NULL;
    }
};

void ADD_NODE(LINKEDLIST& ll, int data){
    NODE* node = new NODE(data);
    if(ll.head == NULL){
        ll.head = ll.tail = node;
    } 
    else{
        ll.tail -> next = node;
        ll.tail = node;
    }
}

// delete node



void PRINT_LINKED_LIST(LINKEDLIST ll ){
    for( NODE* node = ll.head ; node != NULL ; node = node -> next ){
        cout << node -> data << " ";
    }
}
int main(){
    int n ; 
    LINKEDLIST ll;
    cin >> n ; 
    for(int i = 1 ; i <= n ; ++i){
        int data ; 
        cin >> data;
        ADD_NODE(ll, data);
    }
    PRINT_LINKED_LIST(ll);
}
