// from server: 40% by tester
struct S {
    int f();
    char pad0[0x20];
    int m20;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    char m40;
};

extern "C" void __stdcall sub_522800(int, int, int, int, int);

int S::f()
{
    int a, b, c, d;
    if (*(int*)this != 0) {
        sub_522800(m30, m34, m38, m3c, (int)&a);
        d = a;
        b = c;
        c = b;
        a = d;
    } else {
        a = m38;
        c = m3c;
        b = a;
        d = c;
    }
    if (c == m3c && d == m3c) {
        m20 = m28;
        if (m2c == m3c)
            m40 = 1;
    }
    m20 = m30;
    m28 = a;
    m24 = m34;
    m2c = c;
    m30 = b;
    m34 = d;
    return 0;
}
