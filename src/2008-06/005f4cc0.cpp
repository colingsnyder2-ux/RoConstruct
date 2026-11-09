// from server: 100% by atomic.potato
typedef unsigned long DWORD;

struct S
{
    void f();
};

extern "C" void __cdecl sub_5f4500();
extern "C" void (__cdecl *g_80257c)(void *);
extern DWORD g_802580;
extern DWORD g_802584;

void S::f()
{
    sub_5f4500();
    DWORD *p = (DWORD *)((char *)this + 0x18);
    *p = g_802584;
    *p = g_802580;
    g_80257c(p);
}
