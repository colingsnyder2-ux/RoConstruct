// from server: 100% by colin
struct CXTColorSelectorCtrl {
    void SetCurSel(int n);
};

void CXTColorSelectorCtrl::SetCurSel(int n) {
    typedef void (CXTColorSelectorCtrl::*PMF)(int, int);
    PMF* vtbl = *(PMF**)this;
    (this->**(PMF*)((char*)vtbl + 0x140))(n, 0);
}
