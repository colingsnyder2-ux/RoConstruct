// from server: 36% by atomic.potato
struct ScintillaFindReplaceDlg
{
    char pad[0x7c];
    int field_7c;
    unsigned int field_80;
    char pad3[0x98 - 0x84];
    int field_98;

    int sub_7f3b1e();
    int sub_7f472a(int, int, int, int, int);

    int func_0046b660(int a, int b, int c, int d, int e);
};

int ScintillaFindReplaceDlg::sub_7f3b1e()
{
    return 0;
}

int ScintillaFindReplaceDlg::sub_7f472a(int, int, int, int, int)
{
    return 0;
}

int ScintillaFindReplaceDlg::func_0046b660(int a, int b, int c, int d, int e)
{
    int v = sub_7f3b1e();
    field_7c = *(int*)(v + 0xc);
    field_80 |= 0x200;
    field_98 = (a != 0) ? 0x66 : 0x67;
    sub_7f472a(a, b, c, d, e);
    return 0;
}
