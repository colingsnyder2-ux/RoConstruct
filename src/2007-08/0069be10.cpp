// from server: 100% by colin
struct CXTPPropertyGridView
{
    void sub_63023e();
    void* sub_69bca0(int, int);
    void sub_69aaf0(int, void*);
    void sub_69be10(int, int, int);
};

void CXTPPropertyGridView::sub_69be10(int a1, int a2, int a3)
{
    sub_63023e();
    void* p = sub_69bca0(a2, a3);
    if (p != 0)
    {
        (*(void (__thiscall**)(void*, int, int, int))(*(int*)p + 0xbc))(p, a1, a2, a3);
        if (p == sub_69bca0(a2, a3))
        {
            sub_69aaf0(9, p);
        }
    }
}
