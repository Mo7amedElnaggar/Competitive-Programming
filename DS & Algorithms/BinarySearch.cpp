#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;
typedef long long ll ;
vector <int> vec ;

ll BinarySearch(int l , int r , int k){ // Recursive
	if(l > r) return -1 ;
	int mid = (l + r) / 2;
	if(vec[mid] > k)
		return BinarySearch(l , mid - 1 , k) ;
	else if(vec[mid] < k)
		return BinarySearch(mid + 1 , r , k) ;

	return mid ;
}

ll BinarySearch2(int l , int r , int k){
	while(l < r){
		int mid = (l + r) / 2 ;
		if(vec[mid] > k) r = mid -1 ;
		else l = mid + 1 ;
	}
	if(l == r && vec[l] == k) return l ;
	return -1 ;
}
