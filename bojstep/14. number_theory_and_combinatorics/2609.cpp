#include <iostream>

using namespace std;


int n, k;


int euclid(int a, int b){
    if(a % b == 0){
        return b;
    }
    return euclid(b, a % b);
}

int main(){
    cin >> n >> k;
    int e = euclid(max(n, k), min(n, k));
    cout << e << "\n" << n * k / e;
}