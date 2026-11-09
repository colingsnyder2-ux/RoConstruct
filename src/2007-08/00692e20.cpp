// from server: 100% by colin
struct CXTPStatusBar
{
    int GetPane(int nIndex);
};

extern CXTPStatusBar* __stdcall FindStatusBar(int nID);

int CXTPStatusBar::GetPane(int nIndex)
{
    CXTPStatusBar* pBar = FindStatusBar(nIndex);
    if (pBar == 0)
        return 0;
    return *(int*)((char*)pBar + 0x28);
}
