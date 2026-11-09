// from server: 100% by colin
struct CRobloxControlColorSelector {
    char pad0[0xfc];
    CRobloxControlColorSelector* m_pOther;
    int f();
};

int CRobloxControlColorSelector::f()
{
    CRobloxControlColorSelector* p = m_pOther;
    if (p != 0 && p->m_pOther == (CRobloxControlColorSelector*)5)
        return 0;
    return 1;
}
