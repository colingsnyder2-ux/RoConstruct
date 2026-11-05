// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
void __cdecl operator delete(void*);

struct String;
extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

__forceinline String::String(const char* text) {
    stringConstruct(this, text);
}

__forceinline String::~String() {
    stringDestroy(this);
}

struct Joint {
    unsigned int words[34];
    Joint();
};

struct WeldJoint : Joint {
    WeldJoint();
};

__forceinline WeldJoint::WeldJoint() : Joint() {
    words[0] = 0x83e0bc;
}

struct Base {
    unsigned int words[77];
    Base(Joint*);
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    S();
};

S::S() : Base(new WeldJoint) {
    words[0] = 0x83f24c;
    words[4] = 0x83f240;
    words[5] = 0x83f238;
    words[8] = 0x83f230;
    words[9] = 0x83f220;
    words[17] = 0x83f210;
    words[25] = 0x83f200;
    words[33] = 0x83f1f0;
    words[41] = 0x83f1e0;
    words[49] = 0x83f1d0;
    words[76] = 0x83f1b8;
    String name(reinterpret_cast<const char*>(0x83f28c));
    setValue(name);
}
