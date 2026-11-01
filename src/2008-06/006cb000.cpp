// from server: 100% by tester
struct CXTPReportControl {
    char pad[0x288];
    void* field_200;
    void sub_655af0(void*);
    void f();
};

void CXTPReportControl::f() {
    void* p = field_200;
    void* q = *(void**)((char*)p + 0x94);
    sub_655af0(q);
}
