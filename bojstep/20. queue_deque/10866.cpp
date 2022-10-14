#include <iostream>
#include <deque>

using namespace std;
deque<int> D;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        string s;
        cin >> s;
        if(s == "push_front"){
            cin >> num;
            D.push_front(num);
        }
        else if(s == "push_back"){
            cin >> num;
            D.push_back(num);
        }
        else if(s == "pop_front"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.front() << "\n";
            D.pop_front();
        }
        else if(s == "pop_back"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.back() << "\n";
            D.pop_back();
        }
        else if(s == "size"){
            cout << D.size() << "\n";
        }
        else if(s == "empty"){
            cout << int(D.empty()) << "\n";
        }
        else if(s == "front"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.front() << "\n";

        }
        else if(s == "back"){
            if(D.empty()){
                cout << "-1\n";
                continue;
            }
            cout << D.back() << "\n";

        }
    }
}