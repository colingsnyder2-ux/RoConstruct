// from server: 39% by atomic.potato
struct S_func_009dcb20 {
    char pad0[140];
    int m_x;
    int f();
};

struct S_func_009f1350 {
    char pad0[0x8c];
    int m_field8c;
    char pad1[0x44];
    void* m_fieldd4;
    void set(int);
};

struct S {
    char pad0[0xc4];
    void* m_fieldc4;
    void* construct(int, int);
};

void* S::construct(int a, int b)
{
    S_func_009dcb20* p = (S_func_009dcb20*)this;
    p->f();
    int v = p->f();
    v |= 4;
    ((S_func_009f1350*)this)->set(v);
    void* q = m_fieldc4;
    void** vt = *(void***)q;
    typedef void (__stdcall *Fn)(void*, int, int, const char*);
    Fn fn = (Fn)vt[0x58/4];
    fn(q, 1, 0xe120, (const char*)0xb56c8c);

    return this;
}
