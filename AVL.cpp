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


void ADD_NODE(TREE& tree, int data){
    if(tree == NULL){
        NODE* node = new NODE(data);
        tree = node;
    }
    else{
        if(tree -> data == data){
            cout << "bi trung node";
            return ; 
        }
        if(tree -> data > data)     ADD_NODE(tree -> left, data);
        if(tree -> data < data)     ADD_NODE(tree -> right, data);
    }
}


int height(TREE tree){
    if(tree == NULL)    return 0;
    int left = height(tree->left) + 1;
    int right = height(tree->right) + 1;
    return max(left,right); 
}

int BalanceFactor(TREE tree){
    return height(tree -> left) - height(tree -> right);
}

TREE QuayTrai(TREE tree){
    TREE ans = tree -> right ; 
    tree -> right = ans -> left;
    ans -> left = tree;
    return ans;
}

TREE QuayPhai(TREE tree){
     TREE ans = tree -> left; 
     tree -> left = ans -> right;
     ans -> right = tree;
     return ans; 
}

TREE QuayTraiPhai(TREE tree){// mat can bang trai phai
    TREE ans = tree -> left; 
    TREE ans1 = ans -> right; 
    ans -> right = ans1 -> left; 
    ans1 -> left = ans;
    tree -> left = ans1;

    tree -> left = ans1 -> right; 
    ans1 -> right = tree;
    return ans1;
}

TREE QuayPhaiTrai(TREE tree){ // mat can bang phai trai
    TREE ans = tree -> right ; 
    TREE ans1 = ans -> left;    
    ans -> left = ans1 -> right;
    ans1 -> right = ans;

    tree -> right = ans1 -> left; 
    ans1 -> left = tree;
    return ans1;
}

void check(TREE tree){
    if(tree != NULL){
        cout << BalanceFactor(tree) << endl;
        check(tree->left);
        check(tree-> right);
    }
}


void NLR(TREE tree){
    if(tree != NULL){
        cout << tree -> data << " ";
        NLR(tree -> left);
        NLR(tree -> right);
    }
}


string CheckBalancedTractor(TREE tree){
    int number_parent = BalanceFactor(tree);
    if(number_parent == 2){
        int number_child = BalanceFactor(tree -> left);
        if(number_child == 1)   return "LL";
        else    return "LR";
    }
    if(number_parent == -2){
        int number_child = BalanceFactor(tree -> right);
        if(number_child == -1)  return "RR";
        else    return "RL";
    }
    return "NONE";   
}

void AutomaticBalancedFactor(TREE& tree){
    if(tree != NULL){
        AutomaticBalancedFactor(tree -> left);
        AutomaticBalancedFactor(tree -> right);
        string result_check_banlancedtracfor = CheckBalancedTractor(tree);
        if(result_check_banlancedtracfor == "LL")   tree = QuayPhai(tree);
        if(result_check_banlancedtracfor == "RR")   tree = QuayTrai(tree);
        if(result_check_banlancedtracfor == "LR")   tree = QuayTraiPhai(tree);
        if(result_check_banlancedtracfor == "RL")   tree = QuayPhaiTrai(tree);
        cout << result_check_banlancedtracfor << " " << tree -> data << endl;
    }
}

int main(){
    int n ; 
    cin >> n ; 
    TREE tree = NULL;
    for(int i = 1 ; i <= n ; ++i){
        int data ; 
        cin >> data; 
        ADD_NODE(tree,data);
        AutomaticBalancedFactor(tree);
    }
    NLR(tree);
}
