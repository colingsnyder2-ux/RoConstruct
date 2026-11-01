// from server: 100% by colin
struct CMainFrame {
    char pad[0x24];
    CMainFrame* construct();
};

extern "C" void __stdcall sub_006a7960(int);

CMainFrame* CMainFrame::construct()
{
    sub_006a7960(0);
    *(int*)((char*)this + 0x00) = 0x810914;
    *(int*)((char*)this + 0x20) = 0x8108b4;
    return this;
}
