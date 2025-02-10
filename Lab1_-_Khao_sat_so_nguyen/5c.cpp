#include<bits/stdc++.h>
using namespace std;

int main() {

    int p_max = numeric_limits<int>::max();
    int p_min = numeric_limits<int>::min();
    unsigned int q_max = numeric_limits<unsigned int>::max();
    unsigned int q_min = numeric_limits<unsigned int>::min();
    unsigned char r_max = numeric_limits<unsigned char>::max();
    unsigned char r_min = numeric_limits<unsigned char>::min();

    // Tính giá trị lớn nhất
    long x_max = (long)p_max + q_max + r_max;
    cout << "Gia tri lon nhat cua x = " << x_max << endl;

    // Tính giá trị nhỏ nhất
    long x_min = (long)p_min + q_min + r_min;
    cout << "Gia tri nho nhat cua x = " << x_min << endl;

    return 0;
}
//Biểu thức x = p + q + r 
// có thể bị ảnh hưởng bởi thứ tự các toán hạng do quy tắc ép kiểu
