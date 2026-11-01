// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
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