// from server: 81% by atomic.potato
extern "C" long __stdcall InterlockedIncrement(long volatile *);

struct VCXTPReportRowInternalCollection
{
    char pad0[4];
    char *m_pData;
    int m_nCount;
    void *GetAt(int nIndex, int bAddRef);
};

void *VCXTPReportRowInternalCollection::GetAt(int nIndex, int bAddRef)
{
    if (nIndex < 0 || nIndex >= m_nCount)
        return 0;
    char *p = m_pData + nIndex * 8;
    if (bAddRef)
    {
        long *pRef = (long *)(*(char **)(p + 4));
        if (pRef)
            InterlockedIncrement(pRef + 1);
    }
    return *(void **)(p + 4);
}
