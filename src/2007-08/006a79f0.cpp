// from server: 100% by colin
struct CXTPRibbonBar {
    void sub_6A79F0();
};

struct CXTPRibbonBarImpl {
    virtual void vfunc1(int);
};

struct CXTPRibbonBarImpl2 {
    void sub_67A660();
};

struct CXTPRibbonBarImpl3 {
    void sub_6FE640();
};

struct CXTPRibbonBarTail {
    void sub_6458C0();
};

void CXTPRibbonBar::sub_6A79F0() {
    CXTPRibbonBarImpl* p1 = *(CXTPRibbonBarImpl**)((char*)this + 0x27c);
    if (p1 != 0) {
        void (__thiscall *fn)(CXTPRibbonBarImpl*, int) = *(void (__thiscall**)(CXTPRibbonBarImpl*, int))*(void**)p1;
        fn(p1, 1);
        *(void**)((char*)this + 0x27c) = 0;
    }
    CXTPRibbonBarImpl2* p2 = *(CXTPRibbonBarImpl2**)((char*)this + 0x260);
    if (p2 != 0) {
        p2->sub_67A660();
    }
    CXTPRibbonBarImpl3* p3 = *(CXTPRibbonBarImpl3**)((char*)this + 0x264);
    if (p3 != 0) {
        CXTPRibbonBarImpl3* p4 = (CXTPRibbonBarImpl3*)((char*)p3 + 0x178);
        p4->sub_6FE640();
    }
    ((CXTPRibbonBarTail*)this)->sub_6458C0();
}
