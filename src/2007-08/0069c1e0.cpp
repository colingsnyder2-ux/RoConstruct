// from server: 100% by colin
struct CXTPPropertyGridView
{
    char pad[0xb0];
    void* m_pItem;
    char pad2[0x2c];
    void* m_pSelected;

    void Refresh();
};

extern void* __fastcall sub_69be70(void* self);

void CXTPPropertyGridView::Refresh()
{
    void* p = sub_69be70(this);
    if (m_pSelected)
    {
        void** vt = *(void***)m_pSelected;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x2c];
        fn(m_pSelected);
    }
    if (p)
    {
        void** vt = *(void***)p;
        void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x2b];
        fn(p);
    }
    m_pSelected = p;
    if (p)
    {
        void** vt = *(void***)m_pItem;
        void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[0x56];
        fn(m_pItem, p);
    }
}
