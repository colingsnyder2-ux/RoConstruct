// from server: 64% by atomic.potato
struct S_func_00892f00 {
    char pad0[20];
    unsigned char m_flags;

    int f();
};

int S_func_00892f00::f()
{
    return (m_flags & 0xc0) != 0;
}
