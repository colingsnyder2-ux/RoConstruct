// from server: 100% by colin
struct InnerColorSelector {
    char pad[0xe4];
    unsigned int flags;
};

struct CRobloxControlColorSelector {
    char pad[0xfc];
    InnerColorSelector* m_pInner;
    void MarkDirty();
};

void CRobloxControlColorSelector::MarkDirty() {
    InnerColorSelector* p = m_pInner;
    if (p) {
        p->flags |= 1;
    }
}
