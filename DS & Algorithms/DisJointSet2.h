/*
 * DisJointSet2.h
 *
 *  Created on: Jun 21, 2016
 *      Author: mohamed
 */

#ifndef DISJOINTSET2_H_
#define DISJOINTSET2_H_

#include <bits/stdc++.h>

using namespace std ;

class DSU { // CP3 Book
private :
    vector <int> p , rank ;
    int numSets ;
public :
    DSU(int n){
        numSets = n ;
        p.assign(n + 1 , 0) ;
        rank.assign(n + 1 , 0) ;
        for(int i = 0 ; i <= n ; i++) p[i] = i ;
    }
    int FindSet(int i){
        if(p[i] == i)
            return i ;
        return p[i] = FindSet(p[i]) ;
    }
    bool isSameSet(int i , int j){
        return (FindSet(i) == FindSet(j)) ;
    }
    int numDisjointSets(){
        return numSets ;
    }
    void UnionSet(int i , int j){
        int x = FindSet(i) ;
        int y = FindSet(j) ;
        if(x == y) // already in The Same Set
            return ;

        numSets-- ;
        if(rank[x] > rank[y])
            p[y] = x ;
        else {
            p[x] = y ;
            if(rank[y] == rank[x]) rank[y]++ ;
        }
    }
};



#endif /* DISJOINTSET2_H_ */
