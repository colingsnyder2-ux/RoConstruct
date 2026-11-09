// from server: 100% by colin
// roc 2007-08 0042ecf0  unit: CWrapperView  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042ecf0

extern "C" int __stdcall sub_630442(void*);

struct CWrapperView {
    int sub_42ecf0(void*);
};

int CWrapperView::sub_42ecf0(void* arg) {
    if (sub_630442(arg) == 0) {
        return 0;
    }
    *(unsigned int*)((char*)arg + 0x2c) &= 0xfffffdff;
    return 1;
}
