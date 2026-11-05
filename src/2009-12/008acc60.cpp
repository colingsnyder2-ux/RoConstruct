// from server: 35% by atomic.potato
extern "C" int __stdcall PtInRect(const void* rect, int x, int y);

struct CMap {
    char pad0[0x100];
    int* m_pData;
    int m_nSize;
    int Find(int x, int y);
};

int CMap::Find(int x, int y) {
    int i = 0;
    if (m_nSize <= 0)
        return 0;
    while (i >= 0 && i < m_nSize) {
        int v = m_pData[i];
        if (PtInRect((const void*)v, x, y))
            return v;
        ++i;
        if (i >= m_nSize)
            break;
    }
    return 0;
}
