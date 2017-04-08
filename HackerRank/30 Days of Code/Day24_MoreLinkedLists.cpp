#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;

class Node {
public:
     int data;
     Node *next;
     Node(int d){
         data=d;
         next=NULL;
     }
};
class Solution{
    public:
   Node* removeDuplicates(Node *head){
      if(head == NULL || head -> next == NULL) return head ;
      vector<int> vec ;
      Node * p = head ;
      vec.push_back(head -> data) ;
      while(p -> next != NULL) {
         p = p -> next ;
         vec.push_back(p -> data) ;
      }
      sort(vec.begin() , vec.end()) ;
      Node * newHead = NULL ;
      for(int i = 0 ; i < (int)vec.size() - 1 ; i++){
         if(vec[i] == vec[i + 1]) continue ;
         newHead = insert(newHead , vec[i]) ;
      }
      newHead = insert(newHead , vec[(int)vec.size() - 1]) ;

      return newHead ;
   }

   Node* insert(Node *head,int data)
   {
      Node* p=new Node(data);
      if(head==NULL){
         head=p;

      }
      else if(head->next==NULL){
         head->next=p;

      }
      else{
         Node *start=head;
         while(start->next!=NULL){
             start=start->next;
         }
         start->next=p;

      }

       return head;
   }
   void display(Node *head)
   {
       Node *start=head;
       while(start){
           cout<<start->data<<" ";
           start=start->next;
       }
    }
};

int main() {

   Node* head=NULL;
   Solution mylist;
   int T,data;
   cin>>T;
   while(T-->0){
       cin>>data;
       head=mylist.insert(head,data);
   }
   head=mylist.removeDuplicates(head);

   mylist.display(head);

}

