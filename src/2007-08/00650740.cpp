// from server: 100% by colin
struct CXTPToolBar {
    char pad[0xfc];
    int m_nState;
    int sub_6506E0();
    int sub_6439B0();
    int sub_63023E();
    int func_650740(int, int, int);
};

int CXTPToolBar::func_650740(int a, int b, int c)
{
    if (m_nState != 4)
    {
        if (sub_6506E0() == 0)
        {
            if (sub_6439B0() == 0)
            {
                return sub_63023E();
            }
        }
    }
    return 3;
}
