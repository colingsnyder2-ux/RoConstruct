// from server: 100% by tester
struct CXTPDockingPaneAutoHidePanel
{
    char pad[0x54];
    int field_54;
    char pad2[0x1a4 - 0x58];
    void* field_1a0;
    int func_006e0b90();
};

extern "C" int __stdcall func_00630004();
extern "C" int __fastcall func_006e0540(int);
extern "C" int __fastcall func_0066e3d0(int);

int CXTPDockingPaneAutoHidePanel::func_006e0b90()
{
    if (field_1a0 != 0)
    {
        void** vtbl = *(void***)field_1a0;
        int (__fastcall *fn)(void*) = (int (__fastcall *)(void*))vtbl[0x58 / 4];
        fn(field_1a0);
    }
    else
    {
        func_00630004();
    }
    int r = func_006e0540((int)(this->pad + 0x54));
    return func_0066e3d0(r);
}
