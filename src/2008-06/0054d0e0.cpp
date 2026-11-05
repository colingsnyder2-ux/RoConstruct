// from server: 100% by king_originala
struct S {
    bool less(const unsigned int& a, const unsigned int& b) const;
};

#pragma optimize("", off)
bool S::less(const unsigned int& a, const unsigned int& b) const {
    return a < b;
}
#pragma optimize("", on)
