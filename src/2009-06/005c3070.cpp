// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("", off)
struct S {
    unsigned int unused;
    unsigned int value;
    int f(const S& other);
};

int S::f(const S& other) {
    return value < other.value;
}