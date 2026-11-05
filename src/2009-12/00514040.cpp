// from server: 100% by atomic.potato
extern "C" void* __cdecl G1_func_007f3860(unsigned int);

struct S
{
    void f();
};

void S::f()
{
    void* p = G1_func_007f3860(0x44);
    if (p)
        *(void**)p = p;
    void* q = (char*)p + 4;
    if (q)
        *(void**)q = p;
}
