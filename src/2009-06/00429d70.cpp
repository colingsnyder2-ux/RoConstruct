// from server: 100% by why2
extern int G_00a3a25c;

struct CMainFrame {
    char pad[0x109];
    char field_109;
    void func_00429ae0();
    void func_00429d70();
};

void CMainFrame::func_00429d70()
{
    if (G_00a3a25c == 0)
    {
        field_109 = 1;
        func_00429ae0();
    }
}
