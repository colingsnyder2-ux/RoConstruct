// from server: 100% by tester
struct CXTPCommandBarAnimation {
    void* m_pAnimateInfo;
    void* m_pad0;
    void* m_pAnimateInfo2;
    char m_pad[0x18];
    void* m_pCommandBar;
    void Clear();
};

extern "C" int (__stdcall *g_pfnDeleteObject)(void*);

extern "C" void __fastcall sub_6c8fb0(void*);

void CXTPCommandBarAnimation::Clear()
{
    int (__stdcall *pfn)(void*) = g_pfnDeleteObject;
    pfn(m_pAnimateInfo);
    pfn(m_pAnimateInfo2);
    sub_6c8fb0((char*)this + 0x24);
}
