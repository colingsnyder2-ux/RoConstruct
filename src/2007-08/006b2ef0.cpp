// from server: 100% by colin
struct CXTPResourceManager
{
    void* m_pVtable;
    int m_nField4;
    int m_nField8;
    unsigned short m_nFieldC;
    CXTPResourceManager* Init();
};

CXTPResourceManager* CXTPResourceManager::Init()
{
    CXTPResourceManager* p = this;
    p->m_pVtable = (void*)0x7d5f8c;
    p->m_nField4 = 1;
    p->m_nField8 = 0;
    p->m_nFieldC = 0x409;
    return p;
}
