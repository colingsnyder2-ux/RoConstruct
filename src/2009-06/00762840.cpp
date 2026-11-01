// from server: 100% by tester
namespace ns_ROCX00000b {
struct CXTPControlColorSelector {
    int sub_672E50(int, int);
    void sub_672460(int);
    void func(int, int);
};

void CXTPControlColorSelector::func(int a, int b) {
    int r = sub_672E50(a, b);
    if (r != -1) {
        sub_672460(r);
    }
}
}
