#include <iostream>
#include <algorithm>

using namespace std;

int table[500000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> table[i];
    }

    sort(table, table + N);

    int M;
    cin >> M;
    for(int k = 0; k < M; k++){
        int num;
        cin >> num;
        cout << upper_bound(table, table + N, num) - lower_bound(table, table + N, num);
        if(k < M-1){
            cout << " ";
        }
    }   
}