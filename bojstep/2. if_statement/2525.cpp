#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A,B,C;
    cin >> A >> B >> C;

    if(B + C>=60){
        A += int((B + C)/60);
        B = (B + C) % 60;
    }
    else{
        B += C;
    }

    if(A >= 24){
        A %= 24;
    }

    cout << A << " " << B;
}