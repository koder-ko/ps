#include <iostream>
#include <vector>

using namespace std;

vector<int> numbers;
vector<int> signs;

int main()
{

    string s;

    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (c == '-')
        {
            signs.push_back(-1);
        }
        else if (c == '+')
        {
            signs.push_back(1);
        }
        else
        {
            int num = c - 48;
            while (true)
            {
                i++;
                char cur = s[i];
                if (cur == '-' || cur == '+' || i >= s.length())
                {
                    i--;
                    break;
                }
                num = num * 10 + cur - 48;
            }
            numbers.push_back(num);
        }
    }

    int sum = 0;
    bool in_bracket = false;
    int minus_sum = 0;
    for(int k = 0; k < numbers.size(); k++){
        if(k == 0){
            sum += numbers[0];
            continue;
        }

        if(signs[k-1] == -1){
            sum -= minus_sum;
            minus_sum = 0;
            in_bracket = true;
            minus_sum += numbers[k];
        }
        else if(in_bracket){
            minus_sum += numbers[k];
        }
        else{
            sum += numbers[k];
        }
    }
    sum -= minus_sum;

    cout << sum;
}