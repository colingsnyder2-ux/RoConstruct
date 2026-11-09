// from server: 34% by atomic.potato
struct P_func_006a4b30 {
    void g();
};

struct S_func_006a4b30 {
    char pad[264];
    P_func_006a4b30* m_p;
    void f();
};

void S_func_006a4b30::f()
{
    m_p->g();
}

struct T_func_00671db0 {
    char pad_50[80];
    char field_c8[120];
    void f();
};

void T_func_00671db0::f()
{
    P_func_006a4b30* p = *(P_func_006a4b30**)((char*)this + 0xc8);
    p->g();
}
