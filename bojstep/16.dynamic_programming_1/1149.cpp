#include <iostream>
#include <algorithm>

using namespace std;

int n;
int color[1001][3];

int main(){

    cin >> n;

    int cost[3];

    color[0][0] = 0;
    color[0][1] = 0;
    color[0][2] = 0;


    for(int i = 1; i <= n; i++){
        cin >> cost[0] >> cost[1] >> cost[2];
        color[i][0] = min(color[i-1][1], color[i-1][2]) + cost[0];
        color[i][1] = min(color[i-1][0], color[i-1][2]) + cost[1];
        color[i][2] = min(color[i-1][1], color[i-1][0]) + cost[2];

    }

    cout << min(color[n][2], min(color[n][0], color[n][1]));
    
    return 0;
}