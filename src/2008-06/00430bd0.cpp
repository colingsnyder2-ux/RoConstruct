// from server: 100% by tester
extern unsigned char g_flag;
extern void helper();

struct CMainFrame {
    unsigned char pad[261];
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
