// from server: 44% by atomic.potato
extern "C" int __cdecl G1_func_00524cb0(void *);
extern "C" void __stdcall _exit(int);

struct S {
    void f(void *);
};

void S::f(void *p)
{
    int v = G1_func_00524cb0(p);
    _exit(1);
}
