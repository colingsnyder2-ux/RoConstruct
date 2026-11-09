// from server: 100% by why2
struct CXTPControlSelector {
    char pad[0xc];
    int (__stdcall *field_0xc)(int, int, int, int, int, int);
    int method(int a, int b, int c, int d, int e, int f);
};

int CXTPControlSelector::method(int a, int b, int c, int d, int e, int f)
{
    int (__stdcall *p)(int, int, int, int, int, int) = field_0xc;
    if (p != 0)
        return p(a, b, c, d, e, f);
    return 0;
}
