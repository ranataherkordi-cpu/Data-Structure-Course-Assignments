#include <iostream>
using namespace std;

int counter = 0;
void Hanoi(int n , char A , char B , char C){
    if (n == 1)
    {
        counter++;
        cout << counter << " " << A << " " << B << " " << endl;
        return;
    }
    Hanoi(n - 1, A, C, B);
    counter++;
    cout << counter << " " << A << " " << B << " " << endl;
    Hanoi(n - 1, C, B, A);
}

int main(){
    int n;
    cin >> n;
    Hanoi(n ,'A','B','C');
}
