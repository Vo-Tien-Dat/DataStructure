#include<iostream>
#include<string.h>
#include<string>

using namespace std;

struct NODE{
    int data;
    NODE* left;
    NODE* right;
    NODE(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};


typedef NODE* TREE;

void AddNode(TREE& tree, int data){
    if(tree == NULL){
        NODE* node = new NODE(data);
        tree = node;
    }
    else{
        if(tree -> data > data)     AddNode(tree -> left, data);
        if(tree -> data < data)     AddNode(tree -> right, data);
    }
}


int main(){

}