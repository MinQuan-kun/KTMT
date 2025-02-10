#include<bits/stdc++.h>
using namespace std;
int main()
{
    int8_t x;     // Biến nguyên 8-bit (phạm vi: -128 đến 127)
    int y = 300; 
    x = y;  // Giá trị 300 vượt quá phạm vi của int8_t
    cout << x;
    return 0;
}
// Kết luận:khi gán giá trị vượt phạm vi kiểu dữ liệu của biến, 
// chương trình có thể gặp lỗi tràn số, mất dữ liệu hoặc cho ra giá trị không mong muốn.
