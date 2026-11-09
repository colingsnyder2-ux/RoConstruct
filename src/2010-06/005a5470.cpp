// from server: 77% by atomic.potato
extern "C" void* __cdecl func_007a79a0(unsigned int);

struct S {
    float x;
    float y;
    float z;
    void* f();
};

void* S::f()
{
    void* p = func_007a79a0(12);
    if (p)
    {
        *(unsigned int*)p = 0x00a2a848;
        *(float*)((char*)p + 4) = x;
        *(float*)((char*)p + 8) = y;
    }
    return p;
}
