// from server: 100% by tester
struct CXTPControlGallery {
    char pad[0x158];
    void* m_pSomething;
    int GetValue();
};

int CXTPControlGallery::GetValue()
{
    void* p = m_pSomething;
    if (p == 0)
        return 0;
    return *(int*)((char*)p + 0x20);
}
