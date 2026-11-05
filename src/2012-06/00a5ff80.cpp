// from server: 100% by tester
struct CXTColorHex_PAUHEXCOLOR_CELL_CList {
    char pad0[0x60];
    int m_flag;
    void sub_709f50(int, int);
    void sub_63023e();
    void f(int, int, int);
};

void CXTColorHex_PAUHEXCOLOR_CELL_CList::f(int a1, int a2, int a3)
{
    if (m_flag != 0) {
        sub_709f50(a2, a3);
    }
    sub_63023e();
}
