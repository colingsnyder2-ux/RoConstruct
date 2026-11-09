// from server: 100% by colin
struct CXTPControlSelector
{
    int field_0;
    int field_4;
    int (__stdcall *field_8)(int, int, int, int, int, int);
    int method(int, int, int, int, int, int);
};

int CXTPControlSelector::method(int a, int b, int c, int d, int e, int f)
{
    int (__stdcall *p)(int, int, int, int, int, int) = field_8;
    if (p != 0)
        return p(a, b, c, d, e, f);
    return 0;
}
