#include <iostream>

using namespace std;

int memory[100001] = {};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;

    cin >> N >> M;

    int sum = 0;
    int cur;
    for(int i = 1; i <= N; i++){
        cin >> cur;
        sum += cur;
        memory[i] = sum;
    }
    int a, b;
    for(int k = 0; k < M; k++){
        cin >> a >> b;
        cout << memory[b] - memory[a-1] << "\n";
    }
}