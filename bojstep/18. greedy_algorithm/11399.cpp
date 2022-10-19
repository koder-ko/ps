#include <iostream>
#include <algorithm>

using namespace std;

int time_table[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> time_table[i]; 
    }

    sort(time_table, time_table+N);

    int sum = 0, ans = 0;
    for(int k = 0; k < N; k++){
        sum += time_table[k];
        ans += sum;
    }

    cout << ans;
}