// from server: 100% by colin
struct CXTPReportControl
{
    void SetFocusedRow(int nRow);
    char pad0[0xbc];
    int m_nFocusedRow;
    char pad1[8];
    int m_bSomeFlag;
};

void CXTPReportControl::SetFocusedRow(int nRow)
{
    if (nRow < 0)
        nRow = 0;
    if (nRow == this->m_nFocusedRow)
        return;
    this->m_nFocusedRow = nRow;
    if (this->m_bSomeFlag == 0)
    {
        extern void __stdcall sub_738544(int, int, int);
        sub_738544(0, nRow, 1);
    }
    void (CXTPReportControl::*pfn)() = *(void (CXTPReportControl::**)())(*(int*)this + 0x154);
    (this->*pfn)();
}
