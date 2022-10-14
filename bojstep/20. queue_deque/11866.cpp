#include <iostream>
#include <queue>

using namespace std;


int main(){

    ios::sync_with_stdio(false);

    int N, K;

    cin >> N >> K;
    queue<int> memory;

    for(int i = 0; i < N; i++){
        memory.push(i + 1);
    }

    cout << "<";
    while(memory.size() > 0){
        for(int i = 1; i < K; i++){
            int c = memory.front();
            memory.pop();
            memory.push(c);
        }
        cout << memory.front();
        memory.pop();
        if(memory.size() >= 1){
            cout << ", ";
        }
    }
    cout << ">";

}