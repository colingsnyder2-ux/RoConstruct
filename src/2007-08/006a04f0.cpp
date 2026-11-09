// from server: 100% by colin
struct CXTPDockingPaneAutoHidePanel
{
    char pad[0x78];
    void* field_78;
    void Destruct();
};

extern "C" void (__fastcall *g_77ddbc)(void*);
extern "C" void __fastcall sub_630412(CXTPDockingPaneAutoHidePanel*);

void CXTPDockingPaneAutoHidePanel::Destruct()
{
    g_77ddbc(&field_78);
    sub_630412(this);
}
