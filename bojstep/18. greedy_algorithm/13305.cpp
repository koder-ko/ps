#include <iostream>

using namespace std;

int dist[100000];
int city[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N-1; i++){
        cin >> dist[i];
    }

    int min_cost = 1000000000;
    long ans = 0;
    for(int i = 0; i < N; i++){
        cin >> city[i];
        if(i == N-1){
            break;
        }

        if(min_cost >= city[i]){
            min_cost = city[i];
            ans += (long long)(city[i]) * (long long)(dist[i]);
        }
        else{
            ans += (long long)(min_cost) * (long long)(dist[i]);
        }
    }
    cout << ans;
}