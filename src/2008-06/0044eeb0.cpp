// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Primary
{
    virtual void primary();
    char padding[0x70];
};

struct Secondary
{
    virtual void secondary();
    char padding1[0x18];
    int enabled;
    char padding2[0x78];
    unsigned flags;
    unsigned padding3;
};

struct Base : Primary, Secondary
{
    Base(unsigned, unsigned, unsigned);
    ~Base();
    void setFlags(unsigned);
};

struct S : Base
{
    std::string text;

    S(unsigned, const char *, unsigned);
    virtual void primary();
    virtual void secondary();
};

S::S(unsigned first, const char *value, unsigned third)
    : Base(first, 0x72, third), text(value)
{
    enabled = 1;
    setFlags(flags | 0x01844013);
}
