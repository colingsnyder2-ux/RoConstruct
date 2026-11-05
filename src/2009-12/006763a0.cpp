// from server: 36% by atomic.potato
struct Sub {
    char pad0[0x60];
    bool (__thiscall *m_fn)(Sub*);
};

struct S {
    char pad0[0x14];
    int m_kind;
    void f(int* a, int* b);
};

void S::f(int* a, int* b)
{
    Sub* s = (Sub*)((char*)this - 0x94);
    if (!s->m_fn(s))
        goto fail;
    if (*a < 1 || *a > 7)
        goto fail;
    switch (m_kind) {
    case 0:
        ((void (__thiscall *)(Sub*, int*, int*))0x675cc0)(s, b, a);
        break;
    case 1:
        ((void (__thiscall *)(Sub*, int*, int*))0x675ba0)(s, b, a);
        break;
    case 2:
        ((void (__thiscall *)(Sub*, int*, int*))0x676300)(s, b, a);
        break;
    default:
        goto fail;
    }
    return;
fail:
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
}
