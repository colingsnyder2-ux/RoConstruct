// from server: 100% by tester
struct CXTPPropertyGridInplaceButton {
    char pad[0x18];
    void* m_pItem;
    int IsSelected() const;
};

int CXTPPropertyGridInplaceButton::IsSelected() const {
    return *(CXTPPropertyGridInplaceButton**)((char*)m_pItem + 0xc0) == this;
}