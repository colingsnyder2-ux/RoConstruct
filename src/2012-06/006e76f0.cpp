// from server: 69% by atomic.potato
extern "C" void __stdcall sub_4015A0(void*, void*);
extern "C" void* __stdcall sub_6E0790();

struct S
{
};

bool __cdecl f(void* a1)
{
    void* v;
    sub_4015A0((void*)0x6E07F0, (void*)0xE2FCF8);
    void* p = sub_6E0790();
    void* obj = a1;
    void** vtbl = *(void***)obj;
    bool (__stdcall *fn)(void*, void*, int);
    fn = (bool (__stdcall *)(void*, void*, int))vtbl[0x2c / 4];
    if (!fn(obj, &v, 2))
        return false;
    *(void**)a1 = v;
    return true;
}
