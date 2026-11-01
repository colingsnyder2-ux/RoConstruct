// from server: 100% by king_originala
struct S {
    char padding[0x20];
    S* parent;
    S* f();
    S* next();
};

S* S::f() {
    if (parent)
        return parent->next();
    return this;
}
