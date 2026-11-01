// from server: 100% by tester
struct CPropertyGridItemBrickColor {
    char pad[0x20];
    int m_value;
};

extern "C" int __stdcall sub_671c80(int, int);

int __stdcall sub_671d50(int a, int b)
{
    int v;
    if (b == 0)
        v = 0;
    else
        v = ((CPropertyGridItemBrickColor*)b)->m_value;
    sub_671c80(a, v);
    return a;
}
