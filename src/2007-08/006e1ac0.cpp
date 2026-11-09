// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer
{
    int GetCount(int* pCount);
    char m_pad[0x30];
    int m_nCount;
};

int CXTPDockingPaneTabbedContainer::GetCount(int* pCount)
{
    if (pCount == 0)
        return 0x80070057;
    *pCount = *(int*)((char*)this - 0x30) + 1;
    return 0;
}
