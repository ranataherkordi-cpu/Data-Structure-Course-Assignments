#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i]; 
  }
  
  deque<int> q; 
  for(int i = 0; i < n; i++) {
    while(!q.empty() && arr[q.back()] < arr[i]) {
      q.pop_back();
    }
    q.push_back(i);
    
    if(q.front() == i - k) {
      q.pop_front();
    }
    
    if(i >= k - 1) {
      cout << arr[q.front()] << " "; 
    }
  }
  
  return 0;
}
