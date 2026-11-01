// from server: 100% by king_originala
struct S {
    char padding[20];
    S* parent;
    int depth();
};

int S::depth() {
    if (parent)
        return parent->depth() + 1;
    return 1;
}
