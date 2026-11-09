// from server: 100% by colin
// roc 2007-08 004561b0  unit: CRobloxView  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004561b0

struct CRobloxView {
    char pad[0x88];
    void sub_630004();
    void sub_630922(int);
    void sub_63091c();
    CRobloxView* sub_62ff50(CRobloxView*, int);
    void func(int);
};

void CRobloxView::func(int a) {
    sub_630922(a);
    CRobloxView* r = sub_62ff50(this, 0);
    r->sub_63091c();
    ((CRobloxView*)((char*)this + 0x88))->sub_630004();
}
