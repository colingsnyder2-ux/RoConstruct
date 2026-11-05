// from server: 100% by tester
struct CXTPReportControl {
    char m_pad[0x108];
    int m_nValue;
    void SetValue(int nValue);
};

extern "C" void __stdcall sub_738544(int, int, int);

void CXTPReportControl::SetValue(int nValue)
{
    if (nValue != this->m_nValue)
    {
        if (nValue < 0)
            nValue = 0;
        this->m_nValue = nValue;
        sub_738544(1, nValue, 1);
        (*(void (__thiscall **)(CXTPReportControl *))(*(int *)this + 0x164))(this);
    }
}
