// from server: 100% by tester
struct CRobloxView {
    char pad[0xa0];
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
    ((CRobloxView*)((char*)this + 0xa0))->sub_630004();
}
