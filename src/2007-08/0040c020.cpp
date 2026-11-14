// from server: 100% by Intel
// from server: 91% by Intel
// roc 2007-08 0040c020  unit: ?sub_40C020@@YGJPAX00PAPAUIUnknown@@@Z  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040c020
// 100% achieved by mirroring twin (00416470) class-method pattern with ComHolder.

struct IUnknown
{
    virtual long __stdcall QueryInterface(void*, void**) = 0;
    virtual unsigned long __thiscall AddRef(void* self) = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Factory
{
    IUnknown* pUnk;
    long Create(void* pUnkOuter);
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

extern ComHolder g_holder;

long __stdcall sub_40C020(void* a1, void* a2, void* a3, IUnknown** ppOut)
{
    return g_holder.GetInstance(a1, a2, a3, ppOut);
}
