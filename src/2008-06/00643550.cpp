// from server: 100% by king_originala
extern const float initialValue;
extern void* primaryTable[];
extern void* secondaryTable[];

struct Base
{
    void* primary;
    void* secondary;
    int field8;
    float fieldC;

    Base(void* argument);
};

struct S : Base
{
    S(void* argument);
};

S::S(void* argument)
    : Base(argument)
{
    fieldC = initialValue;
    primary = primaryTable;
    secondary = secondaryTable;
}
