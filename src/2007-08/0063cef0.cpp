// from server: 100% by colin
struct CXTPPaintManager {
    char pad0[0xf8];
    int m_nMinHeight;
    int GetMinHeight();
};

int CXTPPaintManager::GetMinHeight()
{
    int value = m_nMinHeight;
    if (value < 0x16)
        value = 0x16;
    return value;
}
