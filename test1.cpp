#include <bits/stdc++.h>

using namespace std;
int main()
{   
    int n, k;
    cin >> n >> k;
  
    int safePos = 0;
    
    for(int i=1; i<=n; i++) {
        safePos = (safePos + k) % i; 
    }
    
    cout << safePos + 1 << endl;
    
    return 0;
}


