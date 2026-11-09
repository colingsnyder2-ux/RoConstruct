// from server: 100% by colin
struct CXTPReportControlLocale {
    int pad0[0x15];
    int m_bSomething;
    int m_pSomething;
    int m_nRefCount;
    void OnFinalRelease();
    void DecrementRef();
};

extern "C" void __stdcall sub_655CE0(int);

void CXTPReportControlLocale::DecrementRef()
{
    m_bSomething = 1;
    if (--m_nRefCount == 0)
    {
        if (m_pSomething != 0)
        {
            m_pSomething = 0;
            sub_655CE0(1);
        }
        OnFinalRelease();
    }
}
