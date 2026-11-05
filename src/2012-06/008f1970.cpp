// from server: 59% by atomic.potato
struct Sub {
    char pad0[0x40];
    int (__stdcall *m_fn)(int);
};

struct Obj {
    char pad0[0x104];
    Sub* m_sub;
    char pad1[0x1c];
    int m_arr[1];
};

int f(Obj* a, int b, Obj* c)
{
    int v1 = a->m_sub->m_fn(b);
    int s = a->m_arr[v1];
    int v2 = c->m_sub->m_fn(b);
    if (s == 2 || c->m_arr[v2] == 2)
        return 1;
    return 0;
}
