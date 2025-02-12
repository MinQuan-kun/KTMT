#include <bits/stdc++.h>
using namespace std;

class Nhiphan {
private:
    string _s;

public:
    Nhiphan();
    Nhiphan(string s);

    int Change(); // Chuyển nhị phân sang thập phân
    bool checkam();

    Nhiphan operator+(const Nhiphan& b);
    Nhiphan operator-(const Nhiphan& b);
    Nhiphan operator*(const Nhiphan& b);
    Nhiphan operator/(const Nhiphan& b);

    friend istream& operator>>(istream& in, Nhiphan& N);
    friend ostream& operator<<(ostream& out, const Nhiphan& N);
};

// Constructor mặc định
Nhiphan::Nhiphan() { _s = "0"; }

// Constructor nhận chuỗi nhị phân
Nhiphan::Nhiphan(string s) { _s = s; }

// Nhập số nhị phân
istream& operator>>(istream& in, Nhiphan& n) {
    in >> n._s;
    return in;
}

// Xuất số nhị phân
ostream& operator<<(ostream& out, const Nhiphan& n) {
    out << n._s;
    return out;
}

// Kiểm tra số âm (bù hai)
bool Nhiphan::checkam() {
    return _s[0] == '1';
}

// Chuyển nhị phân sang thập phân (hỗ trợ số âm bù hai)
int Nhiphan::Change() {
    int res = 0;
    if (!checkam()) { // Số dương
        for (size_t i = 0; i < _s.size(); i++)
            if (_s[i] == '1')
                res += pow(2, _s.size() - i - 1);
    } else { // Số âm (bù hai)
        string s_buHai = _s;
        for (char &c : s_buHai) c = (c == '1') ? '0' : '1'; // Đảo bit

        for (size_t i = 0; i < s_buHai.size(); i++)
            if (s_buHai[i] == '1')
                res += pow(2, s_buHai.size() - i - 1);

        res = -(res + 1);
    }
    return res;
}

// Chuyển số thập phân về nhị phân
string ChuyenNP(int num) {
    if (num == 0) return "0";

    string result;
    bool check = num < 0;
    num = abs(num);

    while (num) {
        result = (char)((num % 2) + '0') + result;
        num /= 2;
    }

    return check ? "-" + result : result;
}

// Phép cộng hai số nhị phân
Nhiphan Nhiphan::operator+(const Nhiphan& b) {
    int k = this->Change() + b.Change();
    return Nhiphan(ChuyenNP(k));
}

// Phép trừ hai số nhị phân
Nhiphan Nhiphan::operator-(const Nhiphan& b) {
    int k = this->Change() - b.Change();
    return Nhiphan(ChuyenNP(k));
}

// Phép nhân hai số nhị phân
Nhiphan Nhiphan::operator*(const Nhiphan& b) {
    int k = this->Change() * b.Change();
    return Nhiphan(ChuyenNP(k));
}

// Phép chia hai số nhị phân
Nhiphan Nhiphan::operator/(const Nhiphan& b) {
    int k = b.Change();
    if (k == 0) {
        throw runtime_error("Lỗi: Không thể chia cho 0!");
    }
    int quotient = this->Change() / divisor;
    return Nhiphan(ChuyenNP(quotient));
}

int main() {
    Nhiphan a, b;
    cout << "Nhập hai số nhị phân: ";
    cin >> a >> b;
    cout << "Tổng: " << (a + b) << endl;
    cout << "Hiệu: " << (a - b) << endl;
    cout << "Tích: " << (a * b) << endl;
    cout << "Thương: " << (a / b) << endl;
    return 0;
}