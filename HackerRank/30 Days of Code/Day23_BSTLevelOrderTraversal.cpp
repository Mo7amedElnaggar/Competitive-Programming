#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public :
    Node* insert(Node* root, int data) {
        if(root == NULL)
            return new Node(data) ;
        else {
            Node * cur ;
            if(data <= root -> data){
                cur = insert(root -> left , data) ;
                root -> left = cur ;
            }
            else {
                cur = insert(root->right, data);
                root->right = cur;
            }
        }
        return root ;
    }
    // Print Level Order Tree Traversal
    void levelOrder(Node * root){
        queue <Node *> q ;
        q.push(root) ; // initial Node (root)
        while(!q.empty()){
            Node * p = q.front() ; // get Current node
            q.pop() ; // remove it from Queue
            // print data of current node
            cout << p -> data << " " ;
            // push left node if Exists
            if(p -> left != NULL) q.push(p -> left) ;
            // push right node if Exists
            if(p -> right != NULL) q.push(p -> right) ;
        }
    }

};

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);



    return 0 ;
}
