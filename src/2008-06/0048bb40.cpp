// from server: 100% by king_originala
struct Getter {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void get(unsigned int* result, unsigned int object) = 0;
};

struct S {
    unsigned char padding[24];
    Getter* getter;
    int equal(unsigned int a, unsigned int b);
};

int S::equal(unsigned int a, unsigned int b)
{
    unsigned int value;
    getter->get(&value, b);
    getter->get(&b, a);
    return b == value;
}
