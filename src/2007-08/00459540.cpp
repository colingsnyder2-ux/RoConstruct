// from server: 100% by colin
struct CRobloxWnd {
    void sub_459540(int, int, int);
    void sub_4593b0(int, int, int);
    void sub_63023e();
};

void CRobloxWnd::sub_459540(int a, int b, int c)
{
    sub_63023e();
    if (*(int*)((char*)this + 0x58) == 2)
        sub_4593b0(a, b, c);
}
