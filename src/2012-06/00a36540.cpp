// from server: 35% by atomic.potato
struct CMap {
    char pad0[0x100];
    int* m_pData;
    int m_nCount;
    int Find(int a, int b);
};

extern "C" int (__stdcall *g_fn)(int, int, int);

int CMap::Find(int a, int b) {
    int i = 0;
    if (m_nCount <= 0)
        return 0;
    while (i >= 0 && i < m_nCount) {
        int v = m_pData[i];
        if (g_fn(v, a, b) != 0)
            return v;
        ++i;
        if (i >= m_nCount)
            break;
    }
    return 0;
}
