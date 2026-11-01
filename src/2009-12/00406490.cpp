// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
extern char table_80b40c[];
extern char table_80b58c[];
extern char table_80b574[];
extern char table_80b558[];
extern char table_80b50c[];

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
};

extern Interface* global_96c268;

struct S {
    char* table0;
    char* volatile table4;
    unsigned int field8;
    char* table12;
    unsigned int field16;
    char* table20;
    unsigned int field24;

    S* initialize(int);
};

S* S::initialize(int)
{
    field24 = 0;
    table4 = table_80b40c;
    field8 = 0;
    field16 = 0;
    table0 = table_80b58c;
    table4 = table_80b574;
    table12 = table_80b558;
    table20 = table_80b50c;
    global_96c268->slot1();
    return this;
}