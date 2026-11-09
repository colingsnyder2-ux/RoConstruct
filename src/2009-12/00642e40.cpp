// from server: 84% by atomic.potato
extern "C" void* __cdecl allocate(unsigned int);

struct S
{
    float pad;
    float x;
    float y;
    void* f();
};

void* S::f()
{
    void* p = allocate(12);
    if (p)
    {
        *(void**)p = (void*)0x009cc8e0;
        *(float*)((char*)p + 4) = x;
        *(float*)((char*)p + 8) = y;
    }
    return p;
}
