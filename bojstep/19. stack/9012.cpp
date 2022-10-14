#include <iostream>
#include <stack>

using namespace std;

stack<char> PS;

bool is_VPS(int r, int l){
    if(r > l){
        while( !PS.empty() ) PS.pop();
        return false;
    }
    else if(PS.empty()){
        if(r == l){
            return true;
        }
        return false;
    }

    if(PS.top() == '('){
        PS.pop();
        return is_VPS(r + 1, l);
    }
    else{
        PS.pop();
        return is_VPS(r, l+1);
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        for(char c : s){
            PS.push(c);
        }
        if(is_VPS(0, 0)){
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";
    }
}