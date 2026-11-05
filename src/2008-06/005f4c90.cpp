// from server: 100% by atomic.potato
extern "C" void __cdecl func_005f4470();

extern void* g_0080257c;
extern void* g_00802580;
extern void* g_00802584;

struct S
{
    char padding[20];
    void* member_14;
    void f();
};

void S::f()
{
    func_005f4470();
    member_14 = g_00802584;
    member_14 = g_00802580;
    ((void (__cdecl *)(void*))g_0080257c)(&member_14);
}
