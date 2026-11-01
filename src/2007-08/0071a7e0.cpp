// from server: 100% by colin
struct CXTPRibbonControlSystemRecentFileList {
    void* f(int a1);
};

extern "C" void* __fastcall sub_0071A770(void* self);

void* CXTPRibbonControlSystemRecentFileList::f(int a1)
{
    void* p = sub_0071A770(this);
    void** vt = *(void***)p;
    void (__thiscall *fn)(void*, void*, int) = (void (__thiscall *)(void*, void*, int))vt[0x38];
    fn(p, this, a1);
    return p;
}
