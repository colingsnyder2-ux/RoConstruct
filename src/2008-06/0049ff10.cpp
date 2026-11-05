// from server: 100% by king_originala
unsigned __cdecl getSettings();

extern unsigned table00[];
extern unsigned table10[];
extern unsigned table14[];
extern unsigned table20[];
extern unsigned table24[];
extern unsigned table44[];
extern unsigned table64[];
extern unsigned table84[];
extern unsigned tableA4[];
extern unsigned tableC4[];
extern unsigned table130[];
extern unsigned table134[];

struct Base
{
    unsigned data[0x138 / 4];

    Base();
    ~Base();
};

struct Client : Base
{
    Client();
};

Client::Client()
    : Base()
{
    data[0x1c / 4] = getSettings();
    data[0x00 / 4] = reinterpret_cast<unsigned>(table00);
    data[0x10 / 4] = reinterpret_cast<unsigned>(table10);
    data[0x14 / 4] = reinterpret_cast<unsigned>(table14);
    data[0x20 / 4] = reinterpret_cast<unsigned>(table20);
    data[0x24 / 4] = reinterpret_cast<unsigned>(table24);
    data[0x44 / 4] = reinterpret_cast<unsigned>(table44);
    data[0x64 / 4] = reinterpret_cast<unsigned>(table64);
    data[0x84 / 4] = reinterpret_cast<unsigned>(table84);
    data[0xa4 / 4] = reinterpret_cast<unsigned>(tableA4);
    data[0xc4 / 4] = reinterpret_cast<unsigned>(tableC4);
    data[0x130 / 4] = reinterpret_cast<unsigned>(table130);
    data[0x134 / 4] = reinterpret_cast<unsigned>(table134);
}
