// from server: 100% by atomic.potato
struct CXTPCommandBar {
    char pad0[0x20];
    void* m_p0x20;
    char pad1[0xc4];
    unsigned int m_flags0xe8;
    void f1();
    void f2();
    int f(int, int);
};

extern "C" int __stdcall sub_9cc618();

int CXTPCommandBar::f(int, int)
{
    if (this == 0)
        return 0;
    if (m_p0x20 == 0)
        return 0;
    if ((sub_9cc618() & 0x10000000) == 0)
        return 0;
    f1();
    f2();
    if ((m_flags0xe8 & 2) != 0) {
        void** vt = *(void***)this;
        void (__thiscall *p)(void*, int, int) = (void (__thiscall *)(void*, int, int))vt[0x1ac / 4];
        p(this, 0, 1);
    }
    if ((m_flags0xe8 & 1) != 0) {
        void** vt = *(void***)this;
        void (__thiscall *p)(void*) = (void (__thiscall *)(void*))vt[0x184 / 4];
        p(this);
        m_flags0xe8 &= 0xfffffffe;
    }
    return 0;
}
