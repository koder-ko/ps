#include <iostream>
#include <queue>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, target;
        cin >> N >> target;

        queue<pair<int,int>> q;
        priority_queue<int> value_q;

        int val;
        for(int i = 0; i < N; i++){
            cin >> val;
            q.push(make_pair(i, val));
            value_q.push(val);
        }

        int ans = 0;
        while(!q.empty()){
            int location = q.front().first;
            int value = q.front().second;

            if(value == value_q.top()){
                q.pop();
                value_q.pop();
                ans++;
                if(location == target){
                    cout << ans << "\n";
                    break;
                }
                continue;
            }

            q.push(q.front());
            q.pop();
        }
    }
}