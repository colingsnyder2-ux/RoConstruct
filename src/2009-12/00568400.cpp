// from server: 40% by atomic.potato
struct RakPeerInner
{
    void *m0;
    void *m1;
    int m2;
    int m3;
    int m4;
};

struct RakPeer
{
    char pad[0xb58];
    RakPeerInner m_inner;
    void f(void *);
};

void RakPeer::f(void *value)
{
    RakPeerInner *p = &m_inner;
    p->m0 = 0;
    *(void **)p = 0;
    p->m4++;
    *(char *)((char *)p->m1 + 4) = 1;
    p->m1 = *(void **)((char *)p->m1 + 8);
}
