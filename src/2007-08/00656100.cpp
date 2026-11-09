// from server: 100% by colin
struct CXTPReportControl {
    char m_pad[0xb8];
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
        (*(void (__thiscall **)(CXTPReportControl *))(*(int *)this + 0x154))(this);
    }
}
