// from server: 100% by king_originala
struct S {
    unsigned int value;
    bool operator<(const S& other) const;
};

#pragma optimize("", off)
bool S::operator<(const S& other) const {
    return value < other.value;
}
