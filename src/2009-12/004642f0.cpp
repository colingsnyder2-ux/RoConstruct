// from server: 100% by atomic.potato
extern "C" void __cdecl f004620b0(void*, void*, int);

struct S {
    void __cdecl f(void*, int);
};

void __cdecl S::f(void* a, int b)
{
    if (b != 4) {
        f004620b0(this, a, b);
        return;
    }

    unsigned char* p = (unsigned char*)a;
    *(unsigned long*)p = 0x00b0a9b8;
    p[4] = 0;
    p[5] = 0;
}
