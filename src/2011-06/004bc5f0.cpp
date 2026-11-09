// from server: 63% by atomic.potato
struct S_func_004bc5f0 {
    int f(int a, int b);
};

int S_func_004bc5f0::f(int a, int b)
{
    typedef int (__thiscall *Fn)(void *, S_func_004bc5f0 *);
    void **vtable = *(void ***)b;
    Fn fn = (Fn)vtable[1];
    return fn((void *)b, this);
}
