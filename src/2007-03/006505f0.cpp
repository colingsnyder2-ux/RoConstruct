// from server: 100% by tester
struct VCXTPReportRows_CXTPHeapObjectT {
    void sub_664360(int, int);
    void f(int*);
};

void VCXTPReportRows_CXTPHeapObjectT::f(int* p) {
    if (p) {
        int v = (*(int (__thiscall **)(int*))(*(int*)p + 0x6c))(p);
        if (v != -1) {
            sub_664360(v, v);
        }
    }
}
