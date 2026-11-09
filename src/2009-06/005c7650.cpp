// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    bool less(const unsigned int& a, const unsigned int& b) const;
};

#pragma optimize("", off)
bool S::less(const unsigned int& a, const unsigned int& b) const {
    return a < b;
}
#pragma optimize("", on)