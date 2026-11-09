// from server: 100% by tester
struct CRobloxControlColorSelector
{
    char pad[0xf4];
    void* field_f4;
    char pad2[4];
    void* field_fc;
    void* get();
};

struct CXTPToolBar__CControlButtonExpand
{
    void func(int, int);
};

extern "C" void* __fastcall sub_63A000();

void CXTPToolBar__CControlButtonExpand::func(int a, int b)
{
    void* p = sub_63A000();
    void** vt = *(void***)p;
    void (__thiscall *fn)(void*, int, void*, int) = (void (__thiscall *)(void*, int, void*, int))vt[0x90 / 4];
    fn(p, a, this, b);
}
