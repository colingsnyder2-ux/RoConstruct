// from server: 100% by king_originala
#pragma optimize("", off)

struct S {
    unsigned int value;
    bool f(const S& other) const;
};

bool S::f(const S& other) const {
    return value > other.value;
}
