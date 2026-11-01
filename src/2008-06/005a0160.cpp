// from server: 100% by king_originala
struct S {
    unsigned char padding[4];
    unsigned char a, b, c, d;
    int f() const;
};

int S::f() const {
    if (a || b || c || d)
        return 1;
    return 0;
}
