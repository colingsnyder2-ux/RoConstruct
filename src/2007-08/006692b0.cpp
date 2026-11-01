// from server: 100% by colin
struct CXTPColorManager {
    void* m_vtable;
    char pad1[12];
    char field_10[12];
    float field_1c;
    void sub_6684a0();
    void sub_668ec0(void* arg);
    CXTPColorManager* construct(void* arg);
};

extern float g_797e9c;

CXTPColorManager* CXTPColorManager::construct(void* arg)
{
    m_vtable = (void*)0x7ca684;
    ((CXTPColorManager*)((char*)this + 4))->sub_6684a0();
    ((CXTPColorManager*)((char*)this + 0x10))->sub_6684a0();
    field_1c = g_797e9c;
    sub_668ec0(arg);
    return this;
}
