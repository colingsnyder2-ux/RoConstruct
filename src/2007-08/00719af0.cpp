// from server: 100% by colin
struct CXTPRibbonControlSystemPopupBarListItem {
    char pad0[0x20];
    int m_field20;
    char pad24[0x15c - 0x24];
    int m_field15c;
    int m_field160;
    CXTPRibbonControlSystemPopupBarListItem* construct();
};

extern "C" void __stdcall sub_6ca460();

CXTPRibbonControlSystemPopupBarListItem* CXTPRibbonControlSystemPopupBarListItem::construct()
{
    sub_6ca460();
    *(int*)this = 0x7e028c;
    *(int*)((char*)this + 0x20) = 0x7e022c;
    *(int*)((char*)this + 0x15c) = 0x12c;
    *(int*)((char*)this + 0x160) = 0x15;
    return this;
}
