// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long arra[maxn];

long long func(int ll, int r, int l)
{
  //  cout << ll << " " << r << " " << l << endl;
    int output = 0;
    if (l == 2)
        return arra[ll] + arra[ll + 1];
    long long max1 = arra[ll], max2 = arra[ll + l/2];
    for (int i = ll; i < ll + l / 2; i++)
    {
        if (arra[i] > max1)
            max1 = arra[i];
    }
    for (int i = ll + l / 2; i < r; i++)
    {
        if (arra[i] > max2)
            max2 = arra[i];
    }
    return max((max1 + func(ll + l / 2, r, l / 2)), (max2 + func(ll, ll + l / 2, l / 2)));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < pow(2, n); i++)
        cin >> arra[i];
    cout << func(0, pow(2, n),  pow(2, n)) << endl;
}