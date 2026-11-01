// from server: 100% by king_originala
struct Item {
    char padding[12];
    int value;
    char key;
};

struct S {
    unsigned char compare(const Item* a, const Item* b) const;
};

unsigned char S::compare(const Item* a, const Item* b) const {
    if (&a->key < &b->key)
        return 1;
    if (&a->key > &b->key)
        return 0;
    if (a->value < b->value)
        return 1;
    if (a->value > b->value)
        return 0;
    return static_cast<unsigned char>(a < b);
}
