// from server: 100% by colin
struct CXTPRibbonBar {
    char pad_0x000[0x240];
    int field_0x240;
    int GetSomething();
};

extern CXTPRibbonBar* GetRibbonBarHelper();

int CXTPRibbonBar::GetSomething()
{
    if (field_0x240 != 0)
    {
        CXTPRibbonBar* p = GetRibbonBarHelper();
        return *(int*)((char*)p + 0x630);
    }
    return 2;
}
