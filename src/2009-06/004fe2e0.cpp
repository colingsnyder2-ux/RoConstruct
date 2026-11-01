// from server: 100% by atomic.potato
extern "C" void __cdecl sub_719EB6(void* dst, const void* src, int count);

struct RakPeer {
    char pad_0000[0x438];
    unsigned char m_field_438[0x100];
    unsigned char m_field_538;
    void f(unsigned char* a1, int* a2);
};

void RakPeer::f(unsigned char* a1, int* a2)
{
    int v = m_field_538;
    if (a1 == 0) {
        *a2 = v;
        return;
    }
    if (*a2 > v)
        *a2 = v;
    int n = *a2;
    if (n > 0)
        sub_719EB6(a1, m_field_438, n);
}
