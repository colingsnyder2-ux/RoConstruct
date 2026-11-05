// from server: 72% by atomic.potato
struct S_func_0048aff0
{
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_0048aff0::f()
{
    return &m_x;
}

struct S_ctrl
{
    void a(int);
    int b(int);
};

extern "C" int* __cdecl func_0048aff0();
extern "C" void func_0048acd0(S_ctrl*, int);
extern "C" void func_0048aca0(S_ctrl*, int);

void __stdcall func_0048dd90(int)
{
    int* p = func_0048aff0();
    S_ctrl* s = (S_ctrl*)p;
    func_0048acd0(s, 1);
    if (s)
        func_0048aca0(s, 1);
}
