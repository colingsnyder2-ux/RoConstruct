// from server: 100% by colin
struct CXTPToolBar {
    int GetCount();
    void* GetAt(int index);
    char pad[0xfc];
    void* m_pControls;

    int CControlButtonCustomize();
};

int CXTPToolBar::CControlButtonCustomize()
{
    int i = 0;
    int count = ((CXTPToolBar*)m_pControls)->GetCount();
    if (count > 0)
    {
        do
        {
            void* p = ((CXTPToolBar*)m_pControls)->GetAt(i);
            if (*(int*)((char*)p + 0xd0) == 2)
                return 1;
            i++;
        } while (i < ((CXTPToolBar*)m_pControls)->GetCount());
    }
    return 0;
}
