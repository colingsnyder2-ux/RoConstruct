// from server: 92% by atomic.potato
extern "C" void __cdecl free(void*);

struct S
{
    void f();
    void* p0;
    void* p4;
    void* p8;
};

void S::f()
{
    if (p0)
    {
        free(p0);
        p0 = 0;
    }
    p8 = 0;
    p4 = 0;
}
