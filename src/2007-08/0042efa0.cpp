// from server: 84% by colin
// roc 2007-08 0042efa0  unit: CWrapperView  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042efa0
//
// 0042efa0  e8791a2000           call 0x630a1e
// 0042efa5  83c430               add esp, 0x30
// 0042efa8  c20400               ret 4

extern "C" void __cdecl sub_630a1e();

struct CWrapperView {
    void sub_42efa0(int);
};

void CWrapperView::sub_42efa0(int) {
    sub_630a1e();
}
