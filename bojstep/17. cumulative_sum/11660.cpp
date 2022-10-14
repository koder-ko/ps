#include <iostream>

using namespace std;

int dp[1025][1025] = {};
int table[1025][1025] = {};


int pos_val(int x, int y){
    if(x == 0 || y == 0){
        return 0;
    }
    if(dp[x][y] != 0){
        return dp[x][y];
    }
    dp[x][y] = pos_val(x-1, y) + pos_val(x, y-1) - pos_val(x-1, y-1) + table[x][y];
    return dp[x][y];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int k = 0; k < N; k++){
            cin >> table[i+1][k+1];
        }
    }

    for(int j = 0; j < M; j++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pos_val(x2,y2) - pos_val(x2, y1-1) - pos_val(x1-1, y2) + pos_val(x1-1, y1-1) << "\n";
    }
}