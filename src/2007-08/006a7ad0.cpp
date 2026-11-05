// from server: 100% by colin
struct CXTPRibbonBar {
    char pad[0x264];
    void* field_264;
    void* get();
};

extern "C" void* __fastcall func_006fe810(void*);

void* CXTPRibbonBar::get()
{
    return func_006fe810((char*)field_264 + 0x178);
}
