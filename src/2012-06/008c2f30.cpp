// from server: 92% by atomic.potato
extern "C" void __stdcall sub_414da0(int);

struct S_func_008c2f30 {
    char pad0[204];
    int m_data;
    void f(unsigned char value);
};

void S_func_008c2f30::f(unsigned char value)
{
    if (*((unsigned char *)(m_data + 0x90)) != value) {
        *((unsigned char *)(m_data + 0x90)) = value;
        sub_414da0(0xe53264);
    }
}
