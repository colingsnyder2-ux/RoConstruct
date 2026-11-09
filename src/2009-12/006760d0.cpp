// from server: 54% by atomic.potato
struct Inner {
    char pad0[0x60];
    char (__thiscall *fn)(Inner*);
    char (__thiscall *fn2)(int);
};

struct Sub {
    char pad0[0x20];
    float m_20;
    char pad1[0x70];
    Inner* m_94;
};

struct S {
    char pad0[0x20];
    float m_20;
    char pad1[0x70];
    Inner* m_94;
    int f_helper(int* a, int* b);
    int f(int* a, int* b);
};

extern "C" float g_9a6a88;

int S::f(int* a, int* b)
{
    Sub* sub = (Sub*)((char*)this - 0x94);
    if (!sub->m_94->fn(sub->m_94))
        goto fail;

    {
        int tmp[4];
        this->f_helper(a, tmp);
        if (tmp[0] == 1) {
            b[0] = 1;
            b[1] = tmp[1];
            b[2] = tmp[2];
            b[3] = tmp[3];
            return 0;
        }
        if (this->m_20 > g_9a6a88) {
            if (*a >= 1 && *a <= 7) {
                int r = sub->m_94->fn2(a[2]);
                if (r) {
                    b[0] = 1;
                    b[1] = 0;
                    b[2] = 0;
                    b[3] = 0;
                    return 0;
                }
            }
        }
    }
fail:
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    return 0;
}
