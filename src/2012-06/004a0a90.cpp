// from server: 65% by atomic.potato
struct S_func_004f3c90 {
    char pad0[88];
    int m_x;
    int* f();
};

int* S_func_004f3c90::f()
{
    return &m_x;
}

struct S_func_004a0a90 {
    int f(int);
};

extern "C" S_func_004f3c90* __cdecl func_004f3c90();
extern "C" void func_0049da00(S_func_004f3c90*, int);
extern "C" void func_0049d9d0(S_func_004f3c90*, int);

int S_func_004a0a90::f(int)
{
    S_func_004f3c90* p = func_004f3c90();
    func_0049da00(p, 1);
    func_0049d9d0(p, 1);
    return 0;
}
