// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    unsigned char flags[9];
    int f();
};

int S::f() {
    if (flags[0] || flags[1] || flags[2] ||
        flags[3] || flags[4] || flags[5] ||
        flags[6] || flags[7] || flags[8])
        return 1;
    return 0;
}