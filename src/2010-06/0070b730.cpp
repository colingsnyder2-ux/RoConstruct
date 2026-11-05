// from server: 66% by atomic.potato
extern "C" double __cdecl f(double);

struct S_func_0070b730
{
    void* f();
};

void* S_func_0070b730::f()
{
    int* p = *(int**)((char*)this + 0x18);
    int n = p[1] * 6 + p[10] + 4;
    return (void*)((int)::f(::f((double)n)) + 1);
}
