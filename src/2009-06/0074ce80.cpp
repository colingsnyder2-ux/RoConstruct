// from server: 100% by tester
struct CXTPReportColumn {
    char pad0[88];
    void* m_pOwner;
    char pad1[0x5c - 0x58];
    int m_nWidth;
    void SetWidth(int nWidth);
};

extern "C" void* __fastcall sub_006d3460(void* p);

void CXTPReportColumn::SetWidth(int nWidth)
{
    if (nWidth != m_nWidth)
    {
        m_nWidth = nWidth;
        void* p = sub_006d3460(m_pOwner);
        void** vtbl = *(void***)p;
        void (__thiscall *fn)(void*) = (void (__thiscall*)(void*))vtbl[0x90 / 4];
        fn(p);
    }
}
