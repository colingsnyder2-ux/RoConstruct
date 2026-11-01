// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#pragma optimize("", off)

struct S {
    unsigned int value;
    bool f(const S& other) const;
};

bool S::f(const S& other) const {
    return value > other.value;
}