// from server: 82% by atomic.potato
struct T
{
    long ref;
};

struct S
{
    void f(T** p);
};

extern "C" T* __cdecl f();
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" long __stdcall InterlockedDecrement(long*);
extern "C" void __stdcall LeaveCriticalSection(void*);

void S::f(T** p)
{
    T* x = ::f();
    EnterCriticalSection(x);
    *p = (T*)x->ref;
    x->ref = (long)p;
    InterlockedDecrement(&x->ref);
    LeaveCriticalSection(x);
}
