// from server: 100% by colin
struct CRobloxReportView {
    char pad[0x2b8];
    int m_field;
    int sub_630058(int);
    int func(int);
};

int CRobloxReportView::func(int arg)
{
    if (arg == 1) {
        int v = m_field;
        if (v != 0)
            return v;
    }
    return sub_630058(arg);
}
