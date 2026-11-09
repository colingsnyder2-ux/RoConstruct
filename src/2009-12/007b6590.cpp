// from server: 87% by atomic.potato
typedef long LONG;
typedef void *LPVOID;

extern "C" void __stdcall EnterCriticalSection(LPVOID);
extern "C" LONG __stdcall InterlockedDecrement(volatile LONG *);
extern "C" void __stdcall LeaveCriticalSection(LPVOID);
extern "C" void * __cdecl sub_44F3C0();

struct GlueJoint
{
    int value;

    void f(int *out);
};

extern "C" void *g_98B204;
extern "C" void *g_98B200;
extern "C" void *g_98B208;
extern "C" void *g_B7B428;

void GlueJoint::f(int *out)
{
    void *p = sub_44F3C0();
    ((void (__stdcall *)(void *))g_98B204)(p);
    int v = *(int *)((char *)p + 0x18);
    *out = v;
    *(int *)((char *)p + 0x18) = (int)out;
    ((void (__stdcall *)(void *))g_98B200)(p);
    ((void (__stdcall *)(void *))g_98B208)(g_B7B428);
}
