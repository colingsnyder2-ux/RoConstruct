// from server: 100% by colin
struct CXTPControlSelector
{
    char pad[0x180];
    int m_nWidth;
    int m_nHeight;
    char pad2[0x8];
    int m_nWidth2;
    int m_nHeight2;
    void GetSize(int* pSize, int);
};

void CXTPControlSelector::GetSize(int* pSize, int)
{
    pSize[0] = m_nWidth2 * m_nWidth;
    pSize[1] = m_nHeight2 * m_nHeight;
}
