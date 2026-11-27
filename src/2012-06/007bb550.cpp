// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct T1 { char pad[0xac]; int q; void g(); };
struct T3 { void g(); };
struct S {
    char pad[0x108];
    T1* m_p;
    int f(int, int);
    T3* g(void*, int, int, int*);
};
int S::f(int a, int b)
{
    char buf[0x30];
    T1* p = m_p;
    p->g();
    g(buf, b, a, &p->q)->g();
    return a;
}
