// from server: 34% by atomic.potato
struct S_0047e660 {
    void* m_a;
    char m_pad[0x1c];
    void* m_b;
    void f_0047e660(void* a, void* b);
};

extern "C" void __stdcall sub_0047d1b0(void* a, void* b);
extern "C" void __stdcall sub_0075a4e0(void* a, void* b, void* c);

void S_0047e660::f_0047e660(void* a, void* b)
{
    m_a = a;
    sub_0047d1b0(b, a);
    void* p = 0;
    if (a != 0)
        p = (char*)a + 0x20;
    sub_0075a4e0(&m_b, p, a);
}
