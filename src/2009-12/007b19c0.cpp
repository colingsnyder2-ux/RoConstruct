// from server: 71% by atomic.potato
extern "C" void __stdcall EnterCriticalSection(void *);
extern "C" long __stdcall InterlockedDecrement(long *);
extern "C" void __stdcall LeaveCriticalSection(void *);

struct S
{
    int f(int *);
};

extern "C" S *__cdecl sub_7b1810();
extern "C" void *__stdcall sub_7b1900(void *);
extern "C" void __stdcall sub_7b1930(void *, void *);
extern "C" void __stdcall sub_7b19f0(void *);

S *g_98b200;
void *g_98b204;
void *g_98b208;
void *g_b7b430;

int S::f(int *p)
{
    S *q = sub_7b1810();
    EnterCriticalSection(q);
    *p = q->f(0);
    q->f(p);
    LeaveCriticalSection(q);
    sub_7b19f0(g_b7b430);
    return 0;
}
