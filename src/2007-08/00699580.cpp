// from server: 100% by colin
struct CXTPPropertyGridItem
{
    void sub_6994C0(CXTPPropertyGridItem*);
    int sub_5B4D40();
    void* sub_6F7190(int);
    CXTPPropertyGridItem* sub_699580(CXTPPropertyGridItem*);
    char pad[0xcc];
    void* m_pItems;
};

CXTPPropertyGridItem* CXTPPropertyGridItem::sub_699580(CXTPPropertyGridItem* param)
{
    sub_6994C0(param);
    int count = ((CXTPPropertyGridItem*)m_pItems)->sub_5B4D40();
    int i = count - 1;
    if (i >= 0)
    {
        do
        {
            void* item = ((CXTPPropertyGridItem*)m_pItems)->sub_6F7190(i);
            void** vtbl = *(void***)item;
            void (__thiscall *fn)(void*, CXTPPropertyGridItem*) = (void (__thiscall *)(void*, CXTPPropertyGridItem*))vtbl[0x144 / 4];
            fn(item, param);
            i--;
        } while (i >= 0);
    }
    return param;
}
