#include <iostream>
#include <stack>

using namespace std;

stack<int> memory;

int main(){
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        string prefix;
        cin >> prefix;
        int num;
        if(prefix == "push"){
            cin >> num;
            memory.push(num);
        }
        else if(prefix == "pop"){
            if(memory.empty()){
                cout << "-1\n";
                continue;
            }
            cout << memory.top() << "\n";
            memory.pop();
        }
        else if(prefix == "size"){
            cout << memory.size() << "\n";
        }
        else if(prefix == "empty"){
            cout << int(memory.empty()) << "\n";
        }
        else if(prefix == "top"){
            if(memory.empty()){
                cout << "-1\n";
                continue;
            }
            cout << memory.top() << "\n";
        }
    }
}