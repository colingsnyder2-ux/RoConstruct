// from server: 100% by tester
struct CXTPRibbonBar;

struct CXTPRibbonBarVtbl {
    char pad[0x1dc];
    void* fn1c8;
};

struct CXTPRibbonBar {
    void* vtable;
    void* m1();
    CXTPRibbonBar* m2(void* arg);
};

extern "C" void* __stdcall sub_6aae00();

CXTPRibbonBar* CXTPRibbonBar::m2(void* arg)
{
    void* p = sub_6aae00();
    CXTPRibbonBar* self = (CXTPRibbonBar*)p;
    void* vt = self->vtable;
    void* fn = *(void**)((char*)vt + 0x1dc);
    typedef void (__thiscall *Fn)(CXTPRibbonBar*, void*, void*);
    ((Fn)fn)(self, this, arg);
    return self;
}
