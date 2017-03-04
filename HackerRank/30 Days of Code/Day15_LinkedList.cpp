#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

class Node {
public :
    int data ;
    Node * next ;
    Node(int data){
        this -> data = data ;
        next = NULL ;
    }
};

class Solution {
public :
    Node * insert(Node * head , int data){
        Node * p = new Node(data) ;
        if(head == NULL) return p ;

        Node * start = head ;
        while(start -> next != NULL) start = start -> next ;
        start -> next = p ;
        return head ;
    }
    void display(Node * head){
        Node * start = head ;
        while(start){
            cout << start -> data << " " ;
            start = start -> next ;
        }
    }
};

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head = mylist.insert(head,data);
    }
    mylist.display(head);


    return 0 ;
}
