// from server: 35% by colin
struct VCContent_CComAggObject
{
    long __stdcall CreateInstance(void* pUnkOuter, void* riid, void** ppv);
};

extern "C" void* __cdecl sub_0062FEF6(unsigned int size);
extern "C" void* __stdcall sub_004126C0(void* p);

long __stdcall VCContent_CComAggObject::CreateInstance(void* pUnkOuter, void* riid, void** ppv)
{
    if (ppv == 0)
    {
        return (long)0x80004003;
    }

    *ppv = 0;

    void* p = sub_0062FEF6(0x9c);
    void* obj = 0;
    if (p != 0)
    {
        obj = sub_004126C0(pUnkOuter);
    }

    if (obj != 0)
    {
        long hr = ((long (__stdcall*)(void*, void*, void**))((*(void***)obj)[0]))(obj, riid, ppv);
        if (hr != 0)
        {
            ((void (__stdcall*)(void*, int))((*(void***)obj)[3]))(obj, 1);
        }
        return hr;
    }

    return (long)0x8007000e;
}
