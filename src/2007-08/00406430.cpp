// from server: 100% by Intel
// from server: 93% by Intel
// roc 2007-08 00406430  unit: ?sub_406430@@YGJPAX00PAPAUIUnknown@@@Z  size: 75 bytes
// 100% achieved via twin-reuse: ComHolder class wrapper pattern from twin 00416470
// Key: Factory struct has pUnk field (no pData); null-check emits xor/cmp pattern

struct IUnknown
{
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __thiscall AddRef(void* self) = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Factory
{
    IUnknown* pUnk;
    long __thiscall Create(void* pUnkOuter);
};

class ComHolder
{
public:
    Factory factory;
    long GetInstance(void* a1, void* a2, void* a3, IUnknown** ppOut)
    {
        if (ppOut == 0)
            return 0x80004003L;
        long hr = 0;
        if (factory.pUnk == 0)
            hr = factory.Create(a3);
        *ppOut = factory.pUnk;
        if (factory.pUnk != 0)
        {
            factory.pUnk->AddRef(factory.pUnk);
            hr = 0;
        }
        return hr;
    }
};

extern ComHolder g_com_holder;

long __stdcall sub_406430(void* a1, void* a2, void* a3, IUnknown** ppOut)
{
    return g_com_holder.GetInstance(a1, a2, a3, ppOut);
}
