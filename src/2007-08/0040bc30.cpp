// from server: 28% by colin
struct VCBrowserViewExternal_CComAggObject
{
    void Construct();
};

extern "C" void __stdcall sub_466B20(void*);
extern void* g_8bae44;
extern void* g_8b5188;

void VCBrowserViewExternal_CComAggObject::Construct()
{
    *(void**)this = (void*)0x785d14;
    *(unsigned int*)((char*)this + 4) = 0xc0000001;

    void* p = g_8bae44;
    void** vtbl = *(void***)p;
    void (*fn)(void*) = (void (*)(void*))vtbl[2];
    fn(p);

    char* p2 = (char*)this + 8;
    if (p2 != 0)
    {
        sub_466B20(p2 + 8);
    }
    else
    {
        sub_466B20(0);
    }
}
