// from server: 44% by colin
struct Tool {
    int field_0x1f8;
    void sub_006353b0(int);
    void func_00635750();
};

void Tool::func_00635750()
{
    int v = field_0x1f8;
    int r = v & 0x80000001;
    if (r < 0)
        r = (r - 1) | 0xfffffffe;
    r = r + 1;
    sub_006353b0(r + v);
}
