// from server: 100% by tester
struct CXTPControlGalleryPaintManager
{
    char pad[0xc0];
    int m_0xc0;
    int m_0xc4;
    int m_0xc8;
    int m_0xcc;
    char pad2[0xfc - 0xd0];
    void* m_0xfc;

    void func(int a, int b);
};

void CXTPControlGalleryPaintManager::func(int a, int b)
{
    int local[4];
    int* p;
    if (a == 0)
    {
        local[0] = m_0xc0;
        local[1] = m_0xc4;
        local[2] = m_0xc8;
        local[3] = m_0xcc;
        p = local;
    }
    else
    {
        p = (int*)a;
    }
    void** vtbl = *(void***)m_0xfc;
    typedef void (__thiscall *Fn)(void*, int*, int);
    Fn fn = (Fn)vtbl[0x19c / 4];
    fn(m_0xfc, p, b);
}
