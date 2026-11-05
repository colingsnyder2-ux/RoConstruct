// from server: 100% by colin
struct CXTPPropertyGridItem {
    int IsChildOf(int) const;
};

int CXTPPropertyGridItem::IsChildOf(int arg) const {
    const CXTPPropertyGridItem* p = *(const CXTPPropertyGridItem**)((const char*)this + 0xb0);
    while (p) {
        if (p == (const CXTPPropertyGridItem*)arg)
            return 1;
        p = *(const CXTPPropertyGridItem**)((const char*)p + 0xb0);
    }
    return 0;
}
