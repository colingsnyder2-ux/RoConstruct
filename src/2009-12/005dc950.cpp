// from server: 77% by atomic.potato
typedef unsigned int DWORD;

struct VTable_005dc950
{
    void (__thiscall *f40)(void *, void *);
};

extern "C" void __cdecl func_007e0cf0(void *, void *);

struct S_func_005dc950
{
    VTable_005dc950 **vtable;
    char pad[4];
    void *m_p;
    void f(void *, void *);
};

void S_func_005dc950::f(void *a, void *b)
{
    vtable[0]->f40(this, b);
    func_007e0cf0(a, m_p);
}
