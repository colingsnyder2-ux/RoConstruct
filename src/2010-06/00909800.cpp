// from server: 0% by atomic.potato
struct Inner {
    char pad[0x50];
    Inner(void*);
};

struct Outer {
    void* m0;
    void* m4;
    void* m8;
    Inner m_c;
    char m_5c;
    char m_5d;
};

extern "C" void* __cdecl alloc_7a79a0(unsigned int);
extern "C" Inner* __cdecl ctor_909160(Inner*, void*);

void* __stdcall create_909800(void* a, void* b, void* c, void* d, char e)
{
    Outer* p = (Outer*)alloc_7a79a0(0x60);
    if (p) {
        p->m0 = a;
        p->m4 = b;
        p->m8 = c;
        ctor_909160(&p->m_c, d);
        p->m_5c = e;
        p->m_5d = 0;
    }
    return p;
}
