// from server: 86% by atomic.potato
struct CRobloxControlColorSelector {
    struct VTable {
        char pad[232];
        void (__thiscall *f)(void *, void *, void *, int);
    };

    VTable *m_vtable;
    int f(int a1, int a2);
};

int CRobloxControlColorSelector::f(int a1, int a2)
{
    m_vtable->f(this, (void *)a2, (void *)a1, 0);
    return 1;
}
