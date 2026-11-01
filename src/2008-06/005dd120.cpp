// from server: 100% by king_originala
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
extern unsigned int table130[];
extern const char name[];

typedef void (__thiscall *StringConstructor)(void*);
extern StringConstructor stringConstructor;

struct Base {
    unsigned int* v0;
    char pad04[12];
    unsigned int* v10;
    unsigned int* v14;
    char pad18[8];
    unsigned int* v20;
    unsigned int* v24;
    char pad28[28];
    unsigned int* v44;
    char pad48[28];
    unsigned int* v64;
    char pad68[28];
    unsigned int* v84;
    char pad88[28];
    unsigned int* vA4;
    char padA8[28];
    unsigned int* vC4;
    char padC8[104];
    unsigned int* v130;

    Base(const char*);
    ~Base();
};

struct Data {
    int first;
    int second;
    int third;

    Data();
    ~Data();
};

inline Data::Data() : first(-1), second(-1), third(0)
{
}

struct S : Base {
    Data data;
    char text[28];

    S();
};

S::S() : Base(name), data()
{
    v0 = table0;
    v10 = table10;
    v14 = table14;
    v20 = table20;
    v24 = table24;
    v44 = table44;
    v64 = table64;
    v84 = table84;
    vA4 = tableA4;
    vC4 = tableC4;
    v130 = table130;
    stringConstructor(text);
}
