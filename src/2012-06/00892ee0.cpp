// from server: 48% by atomic.potato
struct seg_00890000 {
    char pad0[20];
    int m_flags;

    int f();
};

int seg_00890000::f()
{
    return (m_flags & 0x300) != 0;
}
