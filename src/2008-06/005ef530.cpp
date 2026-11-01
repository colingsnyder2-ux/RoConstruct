// from server: 100% by king_originala
unsigned int __cdecl descriptor();

extern char table0[];
extern char table10[];
extern char table14[];
extern char table20[];
extern char table24[];
extern char table44[];
extern char table64[];
extern char table84[];
extern char tableA4[];
extern char tableC4[];
extern char table130[];

struct Base {
    unsigned int words[0x134 / 4];
    Base();
    ~Base();
};

struct S : Base {
    volatile int first;
    volatile int second;
    volatile int third;
    int mode;

    S();
};

S::S()
{
    words[0x1c / 4] = descriptor();
    third = 0;
    first = -1;
    second = -1;

    words[0x00 / 4] = reinterpret_cast<unsigned int>(table0);
    words[0x10 / 4] = reinterpret_cast<unsigned int>(table10);
    words[0x14 / 4] = reinterpret_cast<unsigned int>(table14);
    words[0x20 / 4] = reinterpret_cast<unsigned int>(table20);
    words[0x24 / 4] = reinterpret_cast<unsigned int>(table24);
    words[0x44 / 4] = reinterpret_cast<unsigned int>(table44);
    words[0x64 / 4] = reinterpret_cast<unsigned int>(table64);
    words[0x84 / 4] = reinterpret_cast<unsigned int>(table84);
    words[0xa4 / 4] = reinterpret_cast<unsigned int>(tableA4);
    words[0xc4 / 4] = reinterpret_cast<unsigned int>(tableC4);
    words[0x130 / 4] = reinterpret_cast<unsigned int>(table130);

    mode = 5;
}
