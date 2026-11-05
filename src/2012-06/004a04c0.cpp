// from server: 26% by atomic.potato
struct S_func_004f3c90 {
    char pad0[88];
    int m_x;
    int* f();
};

struct S_func_004a04c0 {
    int* f();
};

int* S_func_004f3c90::f()
{
    return &m_x;
}

extern "C" int* __cdecl func_004f3c90();

struct S_ctrl {
    char pad0[84];
    int m_a;
    int m_b;
    int* f1(int);
    int* f2(int, int);
    int* f3(int, int, int);
};

int* S_ctrl::f1(int a)
{
    return (int*)a;
}

int* S_ctrl::f2(int a, int b)
{
    return (int*)a;
}

int* S_ctrl::f3(int a, int b, int c)
{
    return (int*)a;
}

int* S_func_004a04c0::f()
{
    S_ctrl* p = (S_ctrl*)func_004f3c90();
    int* a = p->f1(1);
    int* b = p->f2((int)a, 1);
    return p->f3((int)b, 0, 1);
}
