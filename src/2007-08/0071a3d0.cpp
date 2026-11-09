// from server: 100% by colin
struct CXTPRibbonControlSystemPopupBarListItem
{
    void* CreateItem(void* pParam);
};

void* func_0071a360();

void* CXTPRibbonControlSystemPopupBarListItem::CreateItem(void* pParam)
{
    void* pItem = func_0071a360();
    void** vtbl = *(void***)pItem;
    typedef void* (__thiscall *Fn)(void*, void*, void*);
    Fn fn = (Fn)vtbl[0x38];
    fn(pItem, this, pParam);
    return pItem;
}
