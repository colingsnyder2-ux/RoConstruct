// from server: 100% by tester
// roc-flags: /O2 /GS- /EHsc /MD
struct seg_004c0000 {
    int get_19c(int *out);
};

int seg_004c0000::get_19c(int *out) {
    *out = *(int *)((char *)this + 0x3fc);
    return (int)out;
}