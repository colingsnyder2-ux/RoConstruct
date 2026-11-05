// from server: 97% by atomic.potato
extern "C" void __cdecl sub_0080b1d8(void *, int, unsigned int, const char *, ...);
extern "C" void __cdecl sub_0080a304(void *);

struct ProfiledRakPeer_0052fe30
{
    void f();
    void *m_data;
    char pad0[8];
    unsigned int m_count;
};

void ProfiledRakPeer_0052fe30::f()
{
    if (m_count > 0 && m_data != 0)
    {
        void *p = (char *)m_data - 4;
        sub_0080b1d8(m_data, 16, *(unsigned int *)p, ",SUVW");
        sub_0080a304(p);
    }
}
