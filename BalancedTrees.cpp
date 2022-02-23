
#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;

struct NODE{
    int val; 
    NODE* left ;
    NODE* right;
    int ht ;
    NODE(){
        this -> left = NULL;
        this -> right = NULL;
    }
    NODE(int val){
        this -> val = val; 
        this -> left = NULL;
        this -> right = NULL;
        this -> ht = 1;
    }
};

typedef NODE* TREE;

NODE* insert(NODE* root, int val){
    if(root == NULL){
        NODE* node = new NODE(val);
        root = node;
    }
    else{
        if(root -> val > val){
            root -> left = insert(root -> left, val);
        }
        else {
            root-> right = insert(root -> right, val);
        }
        root -> ht = max(root -> left == NULL ? 0 : root -> left -> ht, root -> right == NULL ? 0 : root -> right -> ht) + 1;
        int left = root -> left == NULL ? 0 : root -> left -> ht;
        int right = root -> right == NULL ? 0 : root -> right -> ht;
        cout << left << " " << right << endl;
        /*if(root -> ht == 2 ){
            if(root -> left -> ht == 1){// mat can bang trai trai
                NODE* ans = root ->left;
                root -> left = ans -> right ;
                ans -> right = root;
                return ans;
            }
            if (root -> left -> ht == -1){// mat can bang trai phai
                NODE* ans = root -> left;
                NODE* ans1 = ans -> right;
                ans -> right = ans1 -> left; 
                ans1 -> left = ans ;
                root -> left = ans1;

                root -> left = ans1 -> right; 
                ans1 -> right = root;
                return ans1;
            }
        }*/
        /*
        if(root -> ht == -2){
            if(root -> right -> ht == 1){ // mat can bang phai trai

            }

            if(root -> left -> ht == -1){//mat can bang phai phai
                NODE* ans = root->right;
                root -> right = ans -> left;
                ans -> left = root;
                return ans; 
            }
        }*/
    }

    return root;
}

void NLR(NODE* root){
    if(root != NULL){
        cout << root -> val  << endl;
        NLR(root -> left);
        NLR(root -> right);
    }
}

int main(){
    int n ; 
    cin >> n ; 
    NODE* root = NULL;
    for(int i = 1 ; i <= n ; ++i){
        int val;
        cin >> val; 
        root = insert(root, val);
    }
 //   NLR(root);
}