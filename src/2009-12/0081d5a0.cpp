// from server: 100% by atomic.potato
struct CXTPReportControl {
    char pad0[0x108];
    int m_nItem;
    void SetCurSel(int nItem);
};

extern "C" void __stdcall sub_00926670(int, int, int);

void CXTPReportControl::SetCurSel(int nItem)
{
    if (nItem != m_nItem)
    {
        if (nItem < 0)
            nItem = 0;
        m_nItem = nItem;
        sub_00926670(1, nItem, 1);
        (*(void (__thiscall **)(CXTPReportControl *))(*(int *)this + 0x164))(this);
    }
}
