// from server: 100% by atomic.potato
extern "C" void* __cdecl Allocate(unsigned int);

struct S {
    void f();
};

void S::f()
{
    void* p = Allocate(0x38);
    if (p)
        *(void**)p = p;

    void* q = (char*)p + 4;
    if (q)
        *(void**)q = p;
}
