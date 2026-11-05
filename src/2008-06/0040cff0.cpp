// from server: 100% by king_originala
struct Base {
    unsigned long slots[76];
    Base();
    ~Base();
};

struct S : Base {
    unsigned char enabled;
    unsigned char flag1;
    unsigned char flag2;
    unsigned char padding;
    char text[28];

    S();
};

extern unsigned long table0[];
extern unsigned long table10[];
extern unsigned long table14[];
extern unsigned long table20[];
extern unsigned long table24[];
extern unsigned long table44[];
extern unsigned long table64[];
extern unsigned long table84[];
extern unsigned long tableA4[];
extern unsigned long tableC4[];

typedef void (__thiscall *StringConstructor)(void *);
extern StringConstructor constructString;

S::S() : Base()
{
    slots[0]  = reinterpret_cast<unsigned long>(table0);
    slots[4]  = reinterpret_cast<unsigned long>(table10);
    slots[5]  = reinterpret_cast<unsigned long>(table14);
    slots[8]  = reinterpret_cast<unsigned long>(table20);
    slots[9]  = reinterpret_cast<unsigned long>(table24);
    slots[17] = reinterpret_cast<unsigned long>(table44);
    slots[25] = reinterpret_cast<unsigned long>(table64);
    slots[33] = reinterpret_cast<unsigned long>(table84);
    slots[41] = reinterpret_cast<unsigned long>(tableA4);
    slots[49] = reinterpret_cast<unsigned long>(tableC4);

    enabled = 1;
    flag1 = 0;
    flag2 = 0;

    constructString(text);
}
