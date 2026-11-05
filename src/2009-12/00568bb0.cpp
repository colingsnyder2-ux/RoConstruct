// from server: 59% by atomic.potato
struct Inner {
    char pad0[0x34];
    int m_34;
    char pad1[4];
    int m_3c;
    char pad2[4];
    char m_40;
};

struct Outer {
    char pad0[0xc];
    Inner* m_c;
    char pad1[4];
    int m_14;
    char pad2[0xa0c - 0x18];
    char m_a0c;
    Inner* f(int a, char b, int c);
};

struct Caller {
    Inner* sub_568520(char* p);
};

extern Caller g_caller;

Inner* Outer::f(int a, char b, int c)
{
    Inner* r = g_caller.sub_568520(&m_a0c);
    r->m_34 = a;
    r->m_3c = 2;
    r->m_40 = 0;
    r->m_40 = b;
    r->m_3c = c;
    Inner* edx = m_c;
    m_14 += 1;
    edx->m_40 = 1;
    Inner* eax = m_c;
    m_c = eax->m_40 ? (Inner*)0 : (Inner*)0;
    return r;
}
