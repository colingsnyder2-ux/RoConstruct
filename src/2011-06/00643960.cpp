// from server: 30% by atomic.potato
struct VWorkspace;

struct BoundFuncDesc
{
    void* p;
    void* q;
    void* r;
    void* s;
};

extern "C" void* __cdecl sub_80A05E(unsigned int);
extern "C" void __cdecl sub_4F77E0(void*, void*, void*);
extern "C" void __cdecl sub_642640(void*);

struct VWorkspace
{
    void __cdecl AddBoundFuncDesc(void* a, void* b);
    char pad[0x40];
};

void VWorkspace::AddBoundFuncDesc(void* a, void* b)
{
    BoundFuncDesc* d = (BoundFuncDesc*)sub_80A05E(0xD8);
    if (d)
    {
        d->p = 0;
        if (b)
        {
            d->p = b;
            void** vt = *(void***)b;
            void* tmp = (char*)d + 8;
            ((void (__stdcall*)(void*, void*, void*))vt[0])(b, &tmp, 0);
        }
        sub_642640(d);
    }
    else
    {
        d = 0;
    }
    sub_4F77E0(this, d, a);
    if (d)
    {
        void** vt = *(void***)d;
        if (vt)
        {
            ((void (__stdcall*)(void*, void*, int))vt[0])(d, &d, 2);
        }
    }
}
