/*
 * DisJointSet1.h
 *
 *  Created on: Jun 21, 2016
 *      Author: mohamed
 */

#ifndef DISJOINTSET1_H_
#define DISJOINTSET1_H_

#include <bits/stdc++.h>

using namespace std ;

struct Node {
    int data ;
    int rank ;
    Node * parent ;
};

class DisJointSet {
private :
    map <int , Node *> mp ;
    int numSets ;
public :
    DisJointSet(int n){
        numSets = n ;
        for(int i =  1 ; i <= n ; i++)
            Make_Set(i) ;
    }
    void Make_Set(int data){
        Node * p = new Node ;
        p -> data = data ;
        p -> rank = 0 ;
        p -> parent = p ;
        mp[data] = p ;
    }
    Node * Find_Set(Node * p){
        Node *par = p -> parent ;
        if(par == p)
            return p ;
        return p -> parent = Find_Set(par) ;
    }
    bool isSameSet(int i , int j){
        return ((Find_Set(mp[i])->data) == (Find_Set(mp[j])->data)) ;
    }
    int numDisjointSets(){
        return numSets ;
    }
    void Union(int i , int j){
        Node * p1 = Find_Set(mp[i]) ;
        Node * p2 = Find_Set(mp[j]) ;
        if(p1->data == p2->data) // already in the Same Set ;
            return ;
        numSets-- ;
        if(p1 -> rank >= p2 -> rank){
            p1 -> rank = (p1 -> rank == p2 -> rank) ? 1 + p1 -> rank : p1 -> rank ;
            p2 -> parent = p1 ;
        }
        else p1 -> parent = p2 ;
    }
};



#endif /* DISJOINTSET1_H_ */
