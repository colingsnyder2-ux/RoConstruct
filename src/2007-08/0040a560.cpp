// from server: 41% by Yeetserama
extern "C" void* __cdecl func_0062fef6(unsigned int size);
extern "C" int __cdecl func_0040a380(void* p);

struct VCApp_CComAggObject
{
    int __stdcall CreateInstance(void* pOuter, void* pUnkOuter, void** ppv);
};

int __stdcall VCApp_CComAggObject::CreateInstance(void* pOuter, void* pUnkOuter, void** ppv)
{
    if (ppv != 0)
        return (int)0x80004003;

    *ppv = 0;

    void* p = func_0062fef6(0x34);
    int hr = (int)0x8007000e;
    if (p != 0)
    {
        hr = func_0040a380(pOuter);
        if (hr != 0)
        {
            void** vtbl = *(void***)p;
            int (*fn)(void*, void*, void**) = (int (*)(void*, void*, void**))vtbl[0];
            hr = fn(p, pUnkOuter, ppv);
            if (hr != 0)
            {
                void** vtbl2 = *(void***)p;
                void (*release)(void*, int) = (void (*)(void*, int))vtbl2[3];
                release(p, 1);
            }
        }
    }
    return hr;
}
