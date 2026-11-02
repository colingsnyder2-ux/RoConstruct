// from server: 71% by Yeetserama
struct MyXTPCommandBars
{
    void func_00632c00(int arg);
};

struct CXTPDockingPaneManager
{
    void func(int arg);
};

struct ObjectAt26C
{
    void func_68d500(int arg);
};

struct CMainFrame
{
    char pad_0[0xd8];
    MyXTPCommandBars* m_pCommandBars;
    char pad_dc[0x10];
    unsigned char m_byte_ec;
    char pad_ed[0x33];
    CXTPDockingPaneManager m_dockingPaneManager;
    char pad_124[0x148];
    ObjectAt26C m_obj_26c;
    void func(int arg1, int arg2);
    void sub_63036a(int arg1, int arg2);
};

void CMainFrame::func(int arg1, int arg2)
{
    if (m_pCommandBars)
        m_pCommandBars->func_00632c00(arg1);

    int flag = 0;
    if (arg1 == 0)
        flag = (m_byte_ec == 0);

    m_obj_26c.func_68d500(flag);

    m_dockingPaneManager.func(arg1);

    if (m_pCommandBars)
        m_pCommandBars->func_00632c00(arg1);

    sub_63036a(arg1, arg2);
}
