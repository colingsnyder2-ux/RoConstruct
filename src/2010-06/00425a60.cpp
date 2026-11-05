// from server: 45% by atomic.potato
extern "C" unsigned long __stdcall GetCurrentThreadId();

struct S
{
    int f();
    int g();
};

int S::f()
{
    int v = (int)GetCurrentThreadId();
    if (v == *(int*)((char*)this + 12))
        return g();
    return f();
}
