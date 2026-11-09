// from server: 100% by king_originala
#pragma optimize("", off)
struct S {
    unsigned int unused;
    unsigned int value;
    int f(const S& other);
};

int S::f(const S& other) {
    return value < other.value;
}
