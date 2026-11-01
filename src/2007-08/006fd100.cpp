// from server: 100% by colin
struct CXTPTabManagerItem;

struct CXTPTabManagerItemVtbl
{
    void* slot0;
    void* slot1;
    void* slot2;
};

struct CXTPTabManagerItem
{
    char pad[0x60];
    CXTPTabManagerItem* p60;
    void invoke();
};

void CXTPTabManagerItem::invoke()
{
    if (p60 != 0)
    {
        CXTPTabManagerItemVtbl* vt = *(CXTPTabManagerItemVtbl**)p60;
        void (__thiscall *fn)(CXTPTabManagerItem*) = (void (__thiscall *)(CXTPTabManagerItem*))vt->slot2;
        fn(p60);
    }
}
