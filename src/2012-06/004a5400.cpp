// from server: 100% by tajop
struct IUnk
{
    virtual long __stdcall QueryInterface(void* iid, void** out);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

struct S
{
    bool f(IUnk* other);
};

bool S::f(IUnk* other)
{
    IUnk* p = *(IUnk**)((char*)this + 0xf0);
    if (p)
    {
        p->AddRef();
    }
    bool result = p == other;
    if (p)
    {
        p->Release();
    }
    return result;
}
