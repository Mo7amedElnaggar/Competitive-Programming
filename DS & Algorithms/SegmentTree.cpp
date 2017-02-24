#include <iostream>
//#include <bits/stdc++.h>

// Segment Tree : Solve Problems (Min , Max , Sum)
using namespace std ;

int A[1001] , NewA[4 * 1001] , Lazy[4 * 1001] ;
/*
 *  A : Ordinary Array That User Enter Value into
 *  NewA : Segment Tree Array That Will Be Built
 */

int getLeft(int i){ return (i * 2) ; } // get LeftChild in The Tree
int getRight(int i){return (i * 2) + 1 ;} // get Right child in the Tree

void BuiltTree(int l , int r , int p = 1){
    if(l == r) NewA[p] = A[l] ;
    else {
        int mid = l + (r - l) / 2 ; // (l + r) / 2
        BuiltTree(l , mid , getLeft(p)) ; // go to LeftChild
        BuiltTree(mid + 1 , r , getRight(p)) ; // go to RightChild
        NewA[p] = NewA[getLeft(p)] + NewA[getRight(p)]; // Backtracking
        /*
         *
         *  Put Sum of LeftChild and RightChild into Parent (P)
         *  if A : [ 2 3 4 5 ]
         *
         *           14
         *          /  \
         *         /    \
         *        5      9
         *       / \    / \
         *      2   3  4   5
         */
    }
}
// Update Range in Tree
void UpdateTree(int l , int r , int i , int j , int val , int p = 1){ // Update Range(i , j)
    // Out of Range
    if(i > r || l > j) return ;
    if(l == r){
        NewA[p] += val ; // Update With Val
        return ; // There is No More Childs to Visit
    }
    int mid = l + (r - l) / 2 ; // get Mid Position
    UpdateTree(l , mid , i , j , val , getLeft(p)) ; // goto LeftChild
    UpdateTree(mid + 1 , r , i , j , val , getRight(p)) ; // goto RightChild
    NewA[p] = NewA[getLeft(p)] + NewA[getRight(p)] ; // Backtracking
    /*
     * Update Value of Parent After Updating Left and Right Child
     */
}

// Reply With Answer to User like this
// Ques : get Sum From Position 1 to Position 3
// Ans  : ....
int RangeSumQuery(int l , int r , int i , int j , int p = 1){ // get Sum for Range(i , j)
    // Out of Range
    if(i > r || l > j) return 0 ; // Value to indicator that is not in My Sum Range
    if(l >= i && j >= r) return NewA[p] ; // This is Exactly My Range
    // Else i Will Browse Left and Right Child
    int mid = l + (r - l) / 2 ; // get Mid ;
    int FirstPart = RangeSumQuery(l , mid , i , j , getLeft(p)) ; // goto Left Child
    int SecondPart = RangeSumQuery(mid + 1 , r , i , j , getRight(p)) ;  // goto Right

    return FirstPart + SecondPart ; // Return Sum Val of All My Range
}

// More Optimization for Updating Function is Called Lazy Propagation
/* Lazy Propagation Function Here*/

void UpdateTreeLazyPropagation(int l , int r , int i , int j , int val , int p = 1){
    if(l > r) return ; // Out of Range

    if(Lazy[p]){
        NewA[p] += Lazy[p] ;
        if(l != r){ // Child are Not Update With New Val
            Lazy[getLeft(p)] += Lazy[p] ; // Update Left
            Lazy[getRight(p)] += Lazy[p]; // Update Right
        }
        Lazy[p] = 0 ; // This Range Was already Updated -->
    }
    // Out Of My Range ; // No OverLap
    if(i > r || l > j) return ;

    // Total OverLap
    if(l >= i && j >= r){
        NewA[p] += val ;
        if(l != r){ // have 2 Child
            Lazy[getLeft(p)] += val ;
            Lazy[getRight(p)] += val ;
        }
        return ;
    }

    // Partial Overlap
    int mid = l + (r - l) / 2 ;
    UpdateTreeLazyPropagation(l , mid , i , j , val , getLeft(p)) ; // goto Left
    UpdateTreeLazyPropagation(mid + 1 , r , i , j , val , getRight(p)) ; // goto Right

    // BackTracking Update Parent After making Changes in Left and Right Child
    NewA[p] = NewA[getLeft(p)] + NewA[getRight(p)] ;
}

int RangeSumQueryLazyPropagation(int l , int r , int i , int j , int p = 1){
    if(l > r) return 0 ;

    if(Lazy[p]){
        NewA[p] += Lazy[p] ;
        if(l != r){
            Lazy[getLeft(p)] += Lazy[p] ;
            Lazy[getRight(p)] += Lazy[p] ;
        }
        Lazy[p] = 0 ;
    }

    // No OverLap
    if(l > j || i > r) return 0 ; // Indicator "This is Not My Range"

    // Total OverLap
    if(l >= i && j >= r)
        return NewA[p] ;

    // Partial OverLap
    int mid = l + (r - l) / 2 ; // get Mid Position
    // goto LeftChild
    int First = RangeSumQueryLazyPropagation(l , mid , i , r , getLeft(p)) ;
    // goto RightChild
    int Second = RangeSumQueryLazyPropagation(mid + 1 , r , i , j , getRight(p)) ;

    return First + Second ; // Return My Range
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ;

    int n ;
    cin >> n ;
    for(int i = 1 ; i <= n ; i++)
        cin >> A[i] ;

    BuiltTree(1 , n) ;
    /* Using Classical Segment Tree*/
        cout << "Sum from " << 2 << " to " << 4 << " : " ;
        cout << RangeSumQuery(1 , n  , 2 , 4) << endl;
    /* Using LazyPropagation */
        cout << "Sum from " << 2 << " to " << 4 << " : " ;
        cout << RangeSumQueryLazyPropagation(1 , n  , 2 , 4) << endl;
        UpdateTreeLazyPropagation(1 , n , 2 , 4 , 1) ;
        cout << "Sum from " << 2 << " to " << 4 << " : " ;
        cout << RangeSumQueryLazyPropagation(1 , n , 2 , 4) << endl;

    return 0 ;
}
