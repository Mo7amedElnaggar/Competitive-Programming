

using namespace std ;
typedef long long ll ;

void Merge(int Arr[] , int l , int mid , int r){
    int i , j , k ;
    int n1 = mid - l + 1 ;
    int n2 = r - mid ;
    int L[n1] , R[n2] ;
    for(i = 0 ; i < n1 ; i++)
        L[i] = Arr[l + i] ;
    for(i = 0 ; i < n2 ; i++)
        R[i] = Arr[mid + i + 1] ;

    i = 0 , j = 0 , k = l ;
    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            Arr[k] = L[i] , i++ ;
        else Arr[k] = R[j] , j++ ;
        k++ ;
    }
    while(i < n1)
        Arr[k] = L[i] , i++ , k++ ;
    while(j < n2)
        Arr[k] = R[j] , j++ , k++ ;
}

void MergeSort(int Arr[] , int l , int r) {
    if(l < r){
        int mid = (l + r) / 2 ;
        MergeSort(Arr , l , mid) ;
        MergeSort(Arr , mid + 1 , r) ;
        Merge(Arr , l , mid , r) ;
    }
}
