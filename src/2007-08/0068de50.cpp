// from server: 100% by colin
struct CXTPTabClientWnd
{
    void sub_738580();
    void* sub_689740();
    void sub_68d750(int);
    void func_0068de50();
};

void CXTPTabClientWnd::func_0068de50()
{
    sub_738580();
    void* p = sub_689740();
    (*(void (__thiscall**)(void*))(*(int*)p + 0x6c))(p);
    sub_68d750(1);
}
