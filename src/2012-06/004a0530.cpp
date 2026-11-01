// from server: 38% by atomic.potato
struct S_func_004f3c90 {
    char pad0[88];
    int m_x;
    int* f();
};

struct S_func_004a0530 {
    int f();
};

int* S_func_004f3c90::f()
{
    return &m_x;
}

int S_func_004a0530::f()
{
    S_func_004f3c90* p = (S_func_004f3c90*)0x4f3c90;
    int* q = p->f();
    int a = ((int (__thiscall*)(void*, int))0x49ca30)(q, 1);
    int b = ((int (__thiscall*)(void*, int, int))0x49d560)(q, a, 1);
    return ((int (__thiscall*)(void*, int, int, int))0x49cda0)(q, b, 0, 1);
}
