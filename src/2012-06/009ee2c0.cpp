// from server: 66% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __stdcall ImportedCall(void *, void *);

struct CXTAuxData
{
    void *f(void *);
};

void *CXTAuxData::f(void *arg)
{
    void *self = (char *)this + 0x54;
    ImportedCall(arg, self);
    return arg;
}
