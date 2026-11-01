// from server: 100% by colin
extern "C" {
    __declspec(dllimport) int __stdcall DestroyIcon(void*);
    __declspec(dllimport) int __stdcall DeleteObject(void*);
}

struct CXTPCommandBar {
    void* m_pData;
    void* m_pData2;
    void* m_pData3;
    int m_nCount;
    void Clear();
};

void CXTPCommandBar::Clear() {
    if (m_nCount != 0) {
        if (m_pData != 0) {
            DeleteObject(m_pData);
        }
        if (m_pData2 != 0) {
            DestroyIcon(m_pData2);
        }
    }
    if (m_pData3 != 0) {
        DestroyIcon(m_pData3);
    }
    m_pData = 0;
    m_pData2 = 0;
    m_pData3 = 0;
}
