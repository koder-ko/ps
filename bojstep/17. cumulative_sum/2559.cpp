#include <iostream>

using namespace std;

int memory[200000] = {};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    long sum_cur = 0;
    long max_cur = -1000000000;
    int cur;
    for(int i = 1; i <= N; i++){
        cin >> cur;
        memory[i] = cur;
        sum_cur += cur;
        if(i >= K){
            sum_cur -= memory[i - K];
            max_cur = max(max_cur, sum_cur);
        }
    }

    cout << max_cur;
}