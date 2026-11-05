// from server: 100% by colin
struct CXTPOffice2003Theme {
    int sub_006420c0(int* a, int* b);
    int func_006c14f0(int* a, int* b);
};

int CXTPOffice2003Theme::func_006c14f0(int* a, int* b)
{
    int v = b[0xfc / 4];
    if (v != 0 && v != 1)
    {
        sub_006420c0(a, b);
        return (int)a;
    }
    a[0] = 4;
    a[1] = 2;
    a[2] = 2;
    a[3] = 2;
    return (int)a;
}
