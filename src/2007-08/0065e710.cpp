// from server: 100% by atomic.potato
struct Inner {
    void method(void* arg);
};

struct CXTPReportColumn {
    char pad[0x54];
    Inner* m_pInner;
    void f();
};

void CXTPReportColumn::f() {
    m_pInner->method(this);
}
