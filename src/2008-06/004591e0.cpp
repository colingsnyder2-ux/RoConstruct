// from server: 100% by king_originala
struct S_func_0070bdf0 {
    void f(int);
};

struct CRobloxView {
    char pad[0xb0];
    S_func_0070bdf0 field_b0;

    void sub_6A0CCE(int, int);
    void sub_4591E0(int, int);
};

void CRobloxView::sub_4591E0(int a1, int a2)
{
    if (a1)
        field_b0.f(1);
    else
        field_b0.f(0);
    sub_6A0CCE(a1, a2);
}
