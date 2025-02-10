#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Không dấu!" << endl;
    // int x = numeric_limits<int>::max();
    int x = numeric_limits<int>::min();
    cout << x << endl;
    // int a = x + 1;
    int a = x - 1;
    cout << a;

    cout << endl;

    cout << "Có dấu" << endl;
    // unsigned int x1 = numeric_limits<unsigned int>::max();
    unsigned int x1 = -1;
    cout << x1 << endl;
    // unsigned int a1 = x1 + 1;
    unsigned int a1 = x1 - 1;
    cout << a1;
}
// Kết luận: 1 là tràn số, 2 là sẽ quay vòng về giá trị ngược lại, ví dụ max sẽ quay về min,
// min sẽ quay về max và undefined behavior tùy vào trình biên dịch