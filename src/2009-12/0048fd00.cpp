// from server: 100% by atomic.potato
struct RbxSubEntity_0048fd00
{
    char pad0[100];
    int m_value;
    char pad1[248];
    int m_items[64];

    int f(int index);
};

int RbxSubEntity_0048fd00::f(int index)
{
    if (index == 0)
        return m_value;
    return m_items[index - 1];
}
