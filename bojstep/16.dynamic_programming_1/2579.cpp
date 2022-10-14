#include <iostream>
#include <algorithm>

using namespace std;

int stair[301][2];

int score[301];

int main(){
    ios::sync_with_stdio(false);

    int d;
    cin >> d;

    int cur;

    stair[0][0] = 0;
    stair[0][1] = 0;

    for(int i = 1; i <= d; i++){
        cin >> cur;
        score[i] = cur; 
    }

    for(int j = 1 ; j <= d; j++){
        if(j == 1){
            stair[j][0] = stair[j-1][0] + score[j];
            stair[j+1][0] = stair[j-1][0] + score[j+1];
        }
        else{
            stair[j][1] = stair[j-1][0] + score[j];
            stair[j+1][0] = max(stair[j-1][0] + score[j+1], stair[j-1][1] + score[j+1]);
        }
        
    }

    cout << max(stair[d][0], stair[d][1]);
}