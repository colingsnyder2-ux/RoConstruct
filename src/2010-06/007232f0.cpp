// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct A { void* m_pad; void* m_a; void* m_b; void* m_c; };
struct X {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual bool doIt(int, void*);
    char pad[0x1c - 4];
    void* m_f1c;
    bool f(int a1, A* a);
};
bool X::f(int a1, A* a)
{
    if (a->m_b != m_f1c)
        return false;
    return doIt(a1, a->m_c);
}
