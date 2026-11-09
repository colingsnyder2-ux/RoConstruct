// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern const float initialValue;
extern void* primaryTable[];
extern void* secondaryTable[];

struct Base
{
    void* primary;
    void* secondary;
    int field8;
    float fieldC;

    Base(void* a, void* b);
};

struct S : Base
{
    S(void* a, void* b);
};

S::S(void* a, void* b)
    : Base(a, b)
{
    fieldC = initialValue;
    primary = primaryTable;
    secondary = secondaryTable;
}
