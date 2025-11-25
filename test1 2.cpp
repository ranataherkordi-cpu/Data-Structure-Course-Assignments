#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<int> soldiers(n);
  for(int i = 0; i < n; i++) {
    soldiers[i] = i+1; 
  }
  
  int k = 2;
  
  while(soldiers.size() > 1) {
    cout << soldiers[k-1] << " ";
    soldiers.erase(soldiers.begin() + k-1);
    
    for(int i = 0; i < k-1; i++) {
      soldiers.push_back(soldiers[0]);
      soldiers.erase(soldiers.begin());
    }
  }
  
  cout << soldiers[0] << endl;
  return 0;
}
