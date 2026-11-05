// from server: 59% by atomic.potato
typedef void *Ptr;

extern "C" Ptr __cdecl G1_func_007a1d10(Ptr);
extern "C" void __cdecl G1_func_0074b5a0(Ptr);
extern "C" void __cdecl G1_func_007a1d20(Ptr);

struct S
{
    void f();
    Ptr field_94;
};

void S::f()
{
    Ptr p = this ? field_94 : 0;
    Ptr q = G1_func_007a1d10(p);
    G1_func_0074b5a0(q);
    G1_func_007a1d20(this);
}
