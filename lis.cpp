/// Gnourt 
/// 8:38 pm
/// 15/10/2023

#include <bits/stdc++.h>
using namespace std;

#define FOR(a,b) for(int i = a ; i <= b ;i ++)
#define _FOR(a,b) for(int i = a ; i >= b ;i --)
#define INF 1e7

typedef long long ll;

int binSearch(int x , int ds[] , int left , int right)
{
    // neu x >= ds[i] thi return i
    // neu x < ds[i] thi return i-1
    if ( right <= left)
        if ( ds[left] <= x )
            return left ;
        else    
            return left - 1 ;

    int mid = (left + right) / 2;

    if (ds[mid] == x)
        return mid;

    if ( x > ds[mid] )
        return binSearch( x , ds , mid+1 , right );
    else return binSearch( x , ds , left , mid - 1 );
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int line[n+100];
    for (int i = 0 ; i < n ; i ++)
        cin >> line[i];
    
    int result[n+100] , track[n+100];
    FOR (0 , n-1){
        result[i] = 1;
        track[i] = INF;
    }

/////
    track[1] = line[0];
    int kq = 1;
    FOR( 1 , n - 1){
        int ram = binSearch( line[i] , track , 1 , kq );
       
        if ( track[ram]  == line[i] ){
            result[i] = ram;
            continue;
        }

        result[i] = ram + 1;
        track[ result[i] ] = line[i]; 
        kq = max(kq , result[i]);
        
    }
    
    cout << kq; 

    return 0; 
}