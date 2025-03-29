#ifndef RECCHECK

//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

int maxDepth(Node * root)
{
    if(!root){
        return 0;
    }

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    
    if(l > r){
        return l + 1;
    }
    else{
        return r + 1;
    }
}

bool equalPaths(Node * root)
{
    // Add your code below

    if(!root){
        return true;
    }

    if(!root->left && !root->right){
        return true;
    }

    if(root->left && !root->right){
        return equalPaths(root->left);
    }
    if(root->right && !root->left){
        return equalPaths(root->right);
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return(leftDepth == rightDepth) && equalPaths(root->left) && equalPaths(root->right);

}

