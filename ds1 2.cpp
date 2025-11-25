#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

  int n;
  cin >> n;
  
  string parenString;
  cin >> parenString;

  stack<int> openParens;
  vector<int> matches(parenString.size());
  
  for (int i = 0; i < parenString.size(); i++) {
    if (parenString[i] == '(') {
      openParens.push(i);
    } else if (!openParens.empty()) {
      matches[openParens.top()] = i;
      matches[i] = openParens.top();
      openParens.pop();
    }
  }

  for (int pair : matches) {
    cout << pair + 1 << " ";
  }
  cout << endl;
  
  return 0;
}