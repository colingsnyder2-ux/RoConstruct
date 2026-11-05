// from server: 34% by colin
struct PooledItem_0057b960 {
    void* m_p0;
    void* m_p4;
    void* m_p8;
};

struct S_0057b960 {
    char pad0[4];
    PooledItem_0057b960* m_p4;
    int m_p8;
    char pad_c[0xe00];
    int m_e0c;
    S_0057b960* ctor();
};

extern "C" void* __cdecl func_005cb190();
extern "C" void __cdecl func_0098337a(void* dst, int a, int b, int c, int d);

extern int g_b22654;
extern int g_b2263c;

S_0057b960* S_0057b960::ctor()
{
    PooledItem_0057b960* p = (PooledItem_0057b960*)func_005cb190();
    m_p4 = p;
    *(unsigned char*)((char*)p + 0x2d) = 1;
    p->m_p4 = p;
    p->m_p0 = p;
    p->m_p8 = p;
    m_p8 = 0;
    func_0098337a((char*)this + 0xc, 0x1c, 0x80, g_b22654, g_b2263c);
    m_e0c = 1;
    return this;
}
