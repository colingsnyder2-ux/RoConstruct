// from server: 100% by colin
struct CXTPStatusBar {
    char pad[0xb8];
    void* m_pFrameHelper;
    int m_bFrameHelperActive;
    void* GetFrameHelper();
};

extern "C" void* __cdecl sub_63dcb0(int);
extern "C" void* __fastcall sub_6321d0(void*);
extern void* g_8c86d8;

void* CXTPStatusBar::GetFrameHelper()
{
    if (m_bFrameHelperActive == 0)
        return 0;
    if (m_pFrameHelper != 0)
        return sub_6321d0(m_pFrameHelper);
    if (g_8c86d8 == 0)
        sub_63dcb0(0);
    return g_8c86d8;
}
