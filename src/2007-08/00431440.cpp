// from server: 100% by colin
// roc 2007-08 00431440  unit: CMainFrame  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00431440

extern unsigned char g_flag;
extern void helper();

struct CMainFrame {
    unsigned char pad[0xed];
    unsigned char field_ed;
    void func();
};

void CMainFrame::func()
{
    if (!g_flag)
    {
        field_ed = 1;
        helper();
    }
}
