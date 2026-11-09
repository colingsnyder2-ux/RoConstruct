// from server: 100% by atomic.potato
struct S_func_007404c0 {
    unsigned char m_pad[60];
    unsigned char f(unsigned char *a1);
};

unsigned char S_func_007404c0::f(unsigned char *a1)
{
    return a1[reinterpret_cast<unsigned char *>(this) - reinterpret_cast<unsigned char *>(0) + 0x3c];
}
