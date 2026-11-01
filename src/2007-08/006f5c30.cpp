// from server: 100% by colin
struct CXTPPropertyGridInplaceButton {
    char pad[0x28];
    void* m_pItem;
    int IsSelected() const;
};

int CXTPPropertyGridInplaceButton::IsSelected() const {
    return *(CXTPPropertyGridInplaceButton**)((char*)m_pItem + 0x158) == this;
}
