// from server: 100% by king_originala
extern unsigned int descriptor[];
extern unsigned int table0[];
extern unsigned int table10[];
extern unsigned int table14[];
extern unsigned int table20[];
extern unsigned int table24[];
extern unsigned int table44[];
extern unsigned int table64[];
extern unsigned int table84[];
extern unsigned int tableA4[];
extern unsigned int tableC4[];

struct Base {
    unsigned int words[50];
    void initialize(unsigned int*);
    Base* f();
};

Base* Base::f()
{
    initialize(descriptor);
    words[0]  = reinterpret_cast<unsigned int>(table0);
    words[4]  = reinterpret_cast<unsigned int>(table10);
    words[5]  = reinterpret_cast<unsigned int>(table14);
    words[8]  = reinterpret_cast<unsigned int>(table20);
    words[9]  = reinterpret_cast<unsigned int>(table24);
    words[17] = reinterpret_cast<unsigned int>(table44);
    words[25] = reinterpret_cast<unsigned int>(table64);
    words[33] = reinterpret_cast<unsigned int>(table84);
    words[41] = reinterpret_cast<unsigned int>(tableA4);
    words[49] = reinterpret_cast<unsigned int>(tableC4);
    return this;
}
