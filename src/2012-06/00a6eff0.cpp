// from server: 100% by tester
struct CXTPRibbonGroupControlPopup
{
    char pad[0x100];
    void* field_fc;
    void* func_007190c0(void* arg1, void* arg2);
};

extern "C" void* __fastcall func_00643a40(void* p);

void* CXTPRibbonGroupControlPopup::func_007190c0(void* arg1, void* arg2)
{
    void* p = func_00643a40(field_fc);
    void** vtbl = *(void***)p;
    void* (__thiscall *fn)(void*, void*, void*, void*, void*) = (void* (__thiscall *)(void*, void*, void*, void*, void*))vtbl[0x144 / 4];
    fn(p, arg1, arg2, this, 0);
    return arg1;
}
