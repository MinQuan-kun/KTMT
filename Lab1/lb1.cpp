#include<bits/stdc++.h>
using namespace std;
int Dequy(int n, int k, int m)
{
    n -= k;
    n += m;
    k *= 10;
    m *= 10;
    string s = to_string(n);
    for(auto it: s)
        if(it == '2')
            return Dequy(n, k, m);
    return n;
}
int main()
{
    int n;
    cout << "Nhập số cần chuyển sang hệ nhị phân: ";
    cin >> n; // Số cần chuyển sang hệ nhị phân
    stack<int> res; // stack lưu kết quả
    if(n > 0)
    {
        while(n!= 0)
        {
            int temp = n % 2;   // biến lấy kết quả chia lấy dư
            n /= 2;             // chia lấy nguyên
            res.push(temp);
        }
        cout << "10-bit: ";
        for(int i = 0; i < 10 - res.size(); i++)
            cout << "0";
        while(!res.empty())
        {
            cout << res.top();
            res.pop();
        }
    }
    else if(n < 0)
    {
        while(n!= 0)
        {
            int temp = n % 2;   // biến lấy kết quả chia lấy dư
            n /= 2;             // chia lấy nguyên
            if(temp == 0)
                res.push(1);
            else 
                res.push(0);
        }
        string s = "";
        cout << "10-bit: ";
        for(int i = 0; i < 10 - res.size(); i++)
            s+= "1";
        while(!res.empty())
        {
            s += to_string(res.top());
            res.pop();
        }
        int num = stoi(s);
        num += 1;
        int t = num;
        if(t % 10 == 2)
            cout << Dequy(num, 2, 10);
        else
            cout << num;
    }
}