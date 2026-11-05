// from server: 100% by colin
struct CXTPPaintManager
{
    char m_pad[0xf8];
    int m_nFieldF8;
    int m_nFieldFC;
    int GetValue();
};

int CXTPPaintManager::GetValue()
{
    int n;
    if (m_nFieldFC > 0)
    {
        n = m_nFieldF8;
    }
    else
    {
        n = m_nFieldF8 + 3;
        if (n < 0x16)
            n = 0x16;
    }
    return n + n - 0x11;
}
