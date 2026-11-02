// from server: 100% by tajop
struct B0 {
    virtual void f0();
    char pad0[0x1c];
};
struct B1 {
    virtual void f1();
    char pad1[0xe8];
};
struct B2 {
    virtual void f2();
    char pad2[0x18];
};
struct Base : B0, B1, B2 {
    Base(void* a, void* b);
};
struct Vec {
    void* first;
    void* last;
    void* end;
    Vec() { first = last = end = 0; }
};
struct XBrickColorItem : Base, Vec {
    XBrickColorItem(void* a, void* b);
};
XBrickColorItem::XBrickColorItem(void* a, void* b) : Base(a, b) {
}
