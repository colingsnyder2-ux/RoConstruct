// from server: 100% by colin
extern unsigned long table0;
extern unsigned long tableEC;
extern unsigned long tableF0;
extern unsigned long table114;
extern unsigned long table158;

struct Base
{
    unsigned long table;
    char padding[0xe8];
    unsigned long secondaryTable;

    Base();
    ~Base();
};

struct MemberA
{
    volatile unsigned long table;
    char padding[0x20];

    MemberA();
    ~MemberA();
};

struct MemberB
{
    volatile unsigned long table;
    char padding[0x20];

    MemberB();
    ~MemberB();
};

struct S : Base
{
    MemberA a;
    MemberB b;
    volatile unsigned long field138;
    volatile unsigned long field13c;
    volatile unsigned long field140;
    volatile unsigned long field144;
    volatile unsigned long field148;
    volatile unsigned long field14c;
    volatile unsigned long field150;
    volatile unsigned char field154;
    volatile unsigned char field155;
    volatile unsigned char field156;
    unsigned char padding157;
    volatile unsigned long field158;
    unsigned long field15c;

    S();
};

S::S()
{
    table = (unsigned long)&table0;
    secondaryTable = (unsigned long)&tableEC;
    a.table = (unsigned long)&tableF0;
    b.table = (unsigned long)&table114;
    field138 = 0;
    field13c = 0;
    field140 = 0;
    field144 = 0;
    field148 = 0;
    field14c = 0;
    field150 = 0;
    field154 = 0;
    field155 = 0;
    field156 = 0;
    field158 = (unsigned long)&table158;
    field15c = 0;
}
