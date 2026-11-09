// from server: 100% by colin
struct S_func_0041c4e0 {
    void* f(void* p);
};

extern "C" void __cdecl G1_func_0041c3c0(void*);

void* S_func_0041c4e0::f(void* p)
{
    volatile int local = 0;
    G1_func_0041c3c0(p);
    return p;
}
