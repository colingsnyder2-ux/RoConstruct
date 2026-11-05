// from server: 100% by colin
struct CXTShadowWnd {
    void sub_712a80(CXTShadowWnd*);
    void sub_6e4770(CXTShadowWnd*);
    void func(CXTShadowWnd*);
};

void CXTShadowWnd::func(CXTShadowWnd* other) {
    other->sub_712a80(this);
    this->sub_6e4770(other);
}
