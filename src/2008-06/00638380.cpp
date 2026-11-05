// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *stringConstructor)(String*, const char*);
extern void (__thiscall *stringDestructor)(String*);

inline String::String(const char* text) {
    stringConstructor(this, text);
}

inline String::~String() {
    stringDestructor(this);
}

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

struct Base {
    unsigned long words[76];
    Base();
    ~Base();
    void setName(const String&);
};

struct S : Base {
    double value;
    S();
};

S::S() : Base(), value(0.0) {
    words[0]  = (unsigned long)table0;
    words[4]  = (unsigned long)table10;
    words[5]  = (unsigned long)table14;
    words[8]  = (unsigned long)table20;
    words[9]  = (unsigned long)table24;
    words[17] = (unsigned long)table44;
    words[25] = (unsigned long)table64;
    words[33] = (unsigned long)table84;
    words[41] = (unsigned long)tableA4;
    words[49] = (unsigned long)tableC4;
    setName(String("Value"));
}
