#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string s;
    while(N--){
        cin >> s;
        int num;
        if(s == "push"){
            cin >> num;
            q.push(num);
        }
        else if(s == "size"){
            cout << q.size() << "\n";
        }
        else if(s == "empty"){
            cout << int(q.empty()) << "\n";
        }
        else{
            if(q.empty()){
                cout << "-1" << "\n";
                continue;
            }
            
            if(s == "front"){
                cout << q.front() << "\n";
            }
            else if(s == "back"){
                cout << q.back() << "\n";
            }
            else if(s == "pop"){
                cout << q.front() << "\n";
                q.pop();
            }
        }
    }
}