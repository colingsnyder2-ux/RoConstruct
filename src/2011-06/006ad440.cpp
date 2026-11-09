// from server: 41% by atomic.potato
struct S {
    char pad0[0x1c];
    void* field1c;
    void* field20;
    void* field24;
    S* ctor(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h);
};

extern "C" void __cdecl f_401610(void*, void*);
extern "C" void* __cdecl f_5d04b0();
extern "C" void* __cdecl f_5cd490();
extern "C" void __cdecl f_5e4090();
extern "C" void __cdecl f_6a8740();
extern "C" void __cdecl f_80a058(void*);

S* S::ctor(void* a, void* b, void* c, void* d, void* e, void* f, void* g, void* h)
{
    f_401610((void*)0x5d0510, (void*)0xcca304);
    void* edi = f_5d04b0();
    f_5cd490();
    f_5e4090();
    field1c = edi;
    f_6a8740();
    field20 = 0;
    *(void**)this = (void*)0xaa3804;
    if (h) f_80a058(h);
    f_401610((void*)0x5d0510, (void*)0xcca304);
    field24 = f_5d04b0();
    return this;
}
