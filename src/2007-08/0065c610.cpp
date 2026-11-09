// from server: 100% by colin
struct CXTPReportControl {
    char pad[0xd0];
    struct Inner* pInner;
    void sub_65AC80(int, int);
    void f();
};

struct Inner {
    char pad[0x40];
    int field40;
};

void CXTPReportControl::f() {
    sub_65AC80(-0x34, 0);
    pInner->field40 = 0;
}
