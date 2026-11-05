// from server: 100% by king_originala
unsigned long __cdecl getDescriptor();

extern const unsigned long table_8474FC[];
extern const unsigned long table_8474EC[];
extern const unsigned long table_8474E4[];
extern const unsigned long table_8474DC[];
extern const unsigned long table_8474CC[];
extern const unsigned long table_8474BC[];
extern const unsigned long table_8474AC[];
extern const unsigned long table_84749C[];
extern const unsigned long table_84748C[];
extern const unsigned long table_84747C[];
extern const unsigned long table_847460[];
extern const unsigned long table_847454[];

struct Base {
    unsigned long data[0x13C / 4];
    Base(void*);
    ~Base();
};

struct S : Base {
    S(void*);
};

S::S(void* p) : Base(p)
{
    data[0x1C / 4] = getDescriptor();
    data[0x00 / 4] = reinterpret_cast<unsigned long>(table_8474FC);
    data[0x10 / 4] = reinterpret_cast<unsigned long>(table_8474EC);
    data[0x14 / 4] = reinterpret_cast<unsigned long>(table_8474E4);
    data[0x20 / 4] = reinterpret_cast<unsigned long>(table_8474DC);
    data[0x24 / 4] = reinterpret_cast<unsigned long>(table_8474CC);
    data[0x44 / 4] = reinterpret_cast<unsigned long>(table_8474BC);
    data[0x64 / 4] = reinterpret_cast<unsigned long>(table_8474AC);
    data[0x84 / 4] = reinterpret_cast<unsigned long>(table_84749C);
    data[0xA4 / 4] = reinterpret_cast<unsigned long>(table_84748C);
    data[0xC4 / 4] = reinterpret_cast<unsigned long>(table_84747C);
    data[0x130 / 4] = reinterpret_cast<unsigned long>(table_847460);
    data[0x138 / 4] = reinterpret_cast<unsigned long>(table_847454);
}
