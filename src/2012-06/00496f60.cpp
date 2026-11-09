// from server: 36% by atomic.potato
struct C_00496f60 {
    void* m_a;
    char m_b[0x20];

    void f_00496f60(void* p1, void* p2);
};

extern "C" void f_00496650(void*, void*);
extern "C" void f_0075a4e0(void*, void*, void*);

void C_00496f60::f_00496f60(void* p1, void* p2)
{
    m_a = p1;
    f_00496650(&m_b[0], p2);
    void* t = 0;
    if (p1 != 0)
        t = (char*)p1 + 0x20;
    f_0075a4e0(&m_b[0], t, p1);
}
