// from server: 100% by colin
struct CXTPTabPaintManager {
    char pad[0x58];
    int* m_pArray;
    int m_nCount;
};

extern CXTPTabPaintManager* g_pTabPaintManager;

int __cdecl CompareTabIndices(int* pIndex1, int* pIndex2)
{
    int nIndex1 = *pIndex1;
    int nIndex2;
    int nVal1;
    int nVal2;

    if (nIndex1 >= 0 && nIndex1 < g_pTabPaintManager->m_nCount)
        nVal1 = g_pTabPaintManager->m_pArray[nIndex1];
    else
        nVal1 = 0;

    nVal1 = *(int*)((char*)nVal1 + 0x20);

    nIndex2 = *pIndex2;
    if (nIndex2 >= 0 && nIndex2 < g_pTabPaintManager->m_nCount)
        nVal2 = g_pTabPaintManager->m_pArray[nIndex2];
    else
        nVal2 = 0;

    nVal2 = *(int*)((char*)nVal2 + 0x20);

    if (nVal1 > nVal2)
        return -1;
    return nVal1 < nVal2;
}
