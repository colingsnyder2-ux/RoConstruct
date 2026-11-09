// from server: 100% by king_originala
extern "C" void *__cdecl getInitialType();
extern "C" void *__cdecl getFirstType();
extern "C" void *__cdecl getOtherType();
extern "C" const char *__cdecl getValue(void *, int);

struct Property {
    void *type;
    void set(const char *, void *, void *);
};

struct S {
    unsigned char prefix[0x14];
    Property property;
    unsigned char padding[0x28];
    unsigned char first[8];
    unsigned char second[8];
    unsigned char third[8];
    unsigned char fourth[8];

    void initialize(void *, void *, void *, void *);
};

void S::initialize(void *a, void *b, void *c, void *d)
{
    property.type = getInitialType();
    property.set(getValue(a, -1), getFirstType(), first);
    property.set(getValue(b, -1), getOtherType(), second);
    property.set(getValue(c, -1), getOtherType(), third);
    property.set(getValue(d, -1), getOtherType(), fourth);
}
