#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;
typedef long long ll ;
vector <int> vec ;

// l , r --> the Range that you wanna search in 
// k --> is the key that you wanna search for in Range [l , r]
// List must be sorted.
ll BinarySearch1(int l , int r , int k){ // Recursive
	if(l > r) return -1 ;  // k is not in the list :(
	int mid = (l + r) / 2; // get Mid point 
	if(vec[mid] > k) // if true  , then you should go to the left branch
		return BinarySearch1(l , mid - 1 , k) ;
	else if(vec[mid] < k) // if true , then you should go to the right branch
		return BinarySearch1(mid + 1 , r , k) ; 

	return mid ;  // if you come to here , ok you must found 'K' in the list
}

// l , r --> the Range that you wanna search for
// k --> is the key that you wanna search for in Range [l , r]\
// List must be sorted don't forget :D
ll BinarySearch2(int l , int r , int k){ // iterative 
	while(l < r){ // if not , then k is not existd in the list
		int mid = (l + r) / 2 ;  // get mid point
		if(vec[mid] > k) r = mid -1 ; // go to left
		else l = mid + 1 ; //  go to the right
	}
	// this 'if' statment check again if i found k or not
	if(l == r && vec[l] == k) return l ;  
	return -1 ; // for sure you didnt found it :(
}

