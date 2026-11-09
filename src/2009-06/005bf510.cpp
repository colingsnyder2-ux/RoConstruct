// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    unsigned int value;
    bool operator<(const S& other) const;
};

#pragma optimize("", off)
bool S::operator<(const S& other) const {
    return value < other.value;
}