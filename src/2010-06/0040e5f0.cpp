// from server: 40% by atomic.potato
struct VCBrowserViewExternal_CComObjectNoLock
{
    char pad0[0x2b0];
    char field_2b0[4];
    int __thiscall init();
};

extern "C" void __stdcall sub_40DF40();
extern "C" void* __stdcall sub_402D10();
extern "C" void* __stdcall sub_40D310(void*, void*, void*);
extern "C" void __stdcall sub_9EC580(void*);
extern "C" void __stdcall sub_9ECEF0(void*);

int VCBrowserViewExternal_CComObjectNoLock::init()
{
    void* a;
    void* b;
    void* c;
    sub_40DF40();
    *(void**)this = (void*)0xa020a4;
    void* p = sub_402D10();
    void* q = sub_40D310(&a, p, (void*)0xa0208c);
    sub_9EC580(q);
    sub_9ECEF0(&b);
    sub_9ECEF0(&c);
    return (int)this;
}
