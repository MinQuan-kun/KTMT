#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool Heso(T n)
{
    if(n != 2 && n != 10)
        return false;
    return true;
}
template <typename T>
bool Heso2(T n)
{
    if(n == 2)
        return true;
    return false;
}

bool Check(string s)
{
    if(s.length() != 10)
        return false;
    for(char it: s)
        if(it != '1' && it != '0')
            return false;
    return true;
}

bool checkam(string s)
{
    if(s[0] == '1')
        return true;
    return false;
}

void NhapDay(string & s)
{
    while(true)
    {
        cout << "Nhập số nhị phân: ";
        cin >> s;
        if(Check(s))
            break;

        cout << "Error!";
    }    
}

// Hàm chuyển nhị phân sang số nguyên
template <typename T>
void Songuyen(string s) 
{
    T res = 0;
    if (!checkam(s)) { // Số dương
        for (int i = 0; i < 10; i++)
            if (s[i] == '1')
                res += pow(2, 10 - i - 1);
    } 
    else 
    { // Số âm (Bù hai)
        // Đảo bit
        for (int i = 0; i < 10; i++)
            s[i] = (s[i] == '1') ? '0' : '1';

        // Tính giá trị của số dương tương ứng
        for (int i = 0; i < 10; i++)
            if (s[i] == '1')
                res += pow(2, 10 - i - 1);

        // Cộng thêm 1
        res += 1;

        // Đổi dấu
        res = -res;
    }
    cout << "Số nguyên tương ứng: " << res;
}


// Hàm chuyển số nguyên sang nhị phân
template <typename T>
void Change(T n) 
{
    const int BITS = 10; // Biểu diễn nhị phân 10-bit
    stack<T> s; // Lưu kết quả

    // Nếu số là dương, chuyển bình thường
    if (n >= 0) 
    {
        for (int i = 0; i < BITS; i++) 
        {
            s.push(n % 2);
            n /= 2;
        }
    } 
    else
    {
        // Nếu là số âm, ta lấy bù hai
        n = abs(n); // Lấy giá trị tuyệt đối để xử lý

        // Bước 1: Chuyển giá trị tuyệt đối sang nhị phân
        for (int i = 0; i < BITS; i++) 
        {
            s.push(n % 2);
            n /= 2;
        }

        // Bước 2: Đảo bit
        stack<T> s2; // Lưu kết quả đảo bit
        while (!s.empty()) 
        {
            s2.push(1 - s.top()); // Đảo bit
            s.pop();
        }

        // Bước 3: Cộng 1 (Bù hai)
        bool check = true;
        while (!s2.empty()) 
        {
            int bit = s2.top();
            s2.pop();

            if (check) {
                if (bit == 0) 
                {
                    bit = 1;
                    check = false;
                } else {
                    bit = 0;
                }
            }
            s.push(bit);
        }
    }

    // In kết quả
    cout << "Biểu diễn nhị phân: ";
    while (!s.empty()) 
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() 
{
    cout << "Chọn kiểu dữ liệu (i: int, s: short, l: long): ";
    char kt;
    cin >> kt;
    kt = tolower(kt);

    switch (kt) 
    {
        case 'i': 
        {
            int l;
            int n;
            int max = numeric_limits<int>::max(); // Giá trị lớn nhất của int
            int min = numeric_limits<int>::min(); // Giá trị nhỏ nhất của int
            cout << "Chọn hệ số:";
            cin >> l;
            while(!Heso(l))
            {
                cout << "Vui lòng chọn lại hệ số phù hợp!";
                cin >> l;
            }
            if(!Heso2(l))
            {
                cout << "Nhập vào số nguyên: ";
                cin >> n;
                Change(n);
                //Change(min);
                //Change(max);
            }
            else
            {
                string s;
                NhapDay(s);
                Songuyen<int>(s);
            }
            
            break;
        }
        case 's': 
        {
            short l;
            short n;
            short max = numeric_limits<short>::max(); // Giá trị lớn nhất của short
            short min = numeric_limits<short>::min(); // Giá trị nhỏ nhất của short
            cout << "Chọn hệ số:";
            cin >> l;
            while(!Heso(l))
            {
                cout << "Vui lòng chọn lại hệ số phù hợp!";
                cin >> l;
            }
            
            if(!Heso2(l))
            {
                cout << "Nhập vào số nguyên: ";
                cin >> n;
                Change(n);
                //Change(min);
                //Change(max);
            }
            else
            {
                string s;
                NhapDay(s);
                Songuyen<short>(s);
            }

            break;
        }
        case 'l': 
        {
            long l;
            long n;
            long max = numeric_limits<long>::max(); // Giá trị lớn nhất của long
            long min = numeric_limits<long>::min(); // Giá trị nhỏ nhất của long
            cout << "Chọn hệ số:";
            cin >> l;
            while(!Heso(l))
            {
                cout << "Vui lòng chọn lại hệ số phù hợp!";
                cin >> l;
            }
            
            if(!Heso2(l))
            {
                cout << "Nhập vào số nguyên: ";
                cin >> n;
                Change(n);
                //Change(min);
                //Change(max);
            }
            else
            {
                string s;
                NhapDay(s);
                Songuyen<long>(s);
            }
            break;
        }
        default:
            cout << "Lựa chọn không hợp lệ!" << endl;
    }
    return 0;
}