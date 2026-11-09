// from server: 100% by colin
struct CXTPPropertyGridItem {
    char pad[0xb4];
    CXTPPropertyGridItem* m_pOwner;
    CXTPPropertyGridItem* GetParent();
    int IsChildOf();
};

int CXTPPropertyGridItem::IsChildOf()
{
    CXTPPropertyGridItem* pOwner = m_pOwner;
    if (pOwner != 0)
    {
        if (pOwner->GetParent() == this)
            return 1;
    }
    return 0;
}
