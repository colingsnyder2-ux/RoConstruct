// from server: 100% by king_originala
struct Getter {
    virtual void slot0();
    virtual void slot1();
    virtual double get(void *);
};

struct S {
    unsigned char padding[24];
    Getter *getter;
    int equal(void *, void *);
};

int S::equal(void *first, void *second)
{
    double value = getter->get(first);
    return getter->get(second) == value ? 1 : 0;
}
