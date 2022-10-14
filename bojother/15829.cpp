#include <iostream>
using namespace std;

string s; 
int L;
long long r = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L;
    cin >> s;

    long long sigma = 0;

    for(char c : s) {
        sigma += ((c - 96) * r);
        r *= 31;
        r %= 1234567891;
        sigma %= 1234567891;
    }

    cout << sigma;
}