// from server: 100% by atomic.potato
struct CXTPReportRecords {
    char pad[0x28];
    int m_nCount;
    char pad2[0x08];
    int m_nCount2;
    char pad3[0x0c];
    int m_nCount3;
    int GetCount();
    void* GetAt(int);

    void SetIndex(int nIndex);
};

int CXTPReportRecords::GetCount()
{
    if (*(int*)((char*)this + 0x34) != 0)
        return *(int*)((char*)this + 0x38);
    return *(int*)((char*)this + 0x28);
}

void CXTPReportRecords::SetIndex(int nIndex)
{
    int i = nIndex;
    while (i < GetCount())
    {
        void* p = GetAt(i);
        *(int*)((char*)p + 0x4c) = i;
        i++;
    }
}
