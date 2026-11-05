// from server: 90% by atomic.potato
struct S_008df380
{
    char pad0[48];
    int m_base;
    int m_index;
    int f(int p);
};

struct S_008de0e0
{
    char pad0[132];
};

void Call_008de0e0(S_008de0e0 *);

int S_008df380::f(int p)
{
    int x;
    if (p)
        x = p - 28;
    else
        x = 0;
    S_008de0e0 *v = (S_008de0e0 *)x;
    int y = *(int *)((char *)v + 132);
    y = *(int *)((char *)y + m_index);
    y += m_base;
    Call_008de0e0((S_008de0e0 *)(y + x + 132));
    return 0;
}
