// from server: 87% by atomic.potato
struct S_func_00912a10 {
    void f(int a1);
};

struct CRobloxView {
    char pad[0xa0];
    S_func_00912a10 field_a0;
    void func_0045f4c0(int, int);
};

void CRobloxView::func_0045f4c0(int a, int b)
{
    if (a != 0)
        field_a0.f(1);
    else
        field_a0.f(0);
    ((void (__thiscall*)(CRobloxView*, int, int))0x7f3e96)(this, a, b);
}
