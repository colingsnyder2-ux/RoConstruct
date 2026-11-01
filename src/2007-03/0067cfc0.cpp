// from server: 100% by tester
struct CXTPStatusBar {
    int* sub_00692C60(int);
    void sub_006933D0(int, int);
    void sub_00692E40(int, int, int);
    void f(int, int);
};

void CXTPStatusBar::f(int a, int b)
{
    int* p = sub_00692C60(a);
    if (p != 0) {
        int old = p[10];
        if (old != b) {
            if ((old ^ b) & 0x8000000) {
                p[10] = b;
                sub_006933D0(1, 0);
            }
            p[11] |= 1;
            p[10] = b;
            sub_00692E40(a, (int)(p + 12), 1);
        }
    }
}
