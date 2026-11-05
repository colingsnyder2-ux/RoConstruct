// from server: 100% by king_originala
struct Name;
extern const Name& __cdecl getLocalScope();

extern const char table00[], table10[], table14[], table20[], table24[];
extern const char table44[], table64[], table84[], tableA4[], tableC4[];
extern const char table130[];
extern const char shirtGraphic[];

struct String;
extern void (__thiscall *stringDefaultConstruct)(String*);
extern void (__thiscall *stringTextConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(void* owner);
    String(const char* text);
    ~String();
};

__forceinline void* installTables(void* owner) {
    unsigned long* p = static_cast<unsigned long*>(owner);
    p[0x00 / 4] = reinterpret_cast<unsigned long>(table00);
    p[0x10 / 4] = reinterpret_cast<unsigned long>(table10);
    p[0x14 / 4] = reinterpret_cast<unsigned long>(table14);
    p[0x20 / 4] = reinterpret_cast<unsigned long>(table20);
    p[0x24 / 4] = reinterpret_cast<unsigned long>(table24);
    p[0x44 / 4] = reinterpret_cast<unsigned long>(table44);
    p[0x64 / 4] = reinterpret_cast<unsigned long>(table64);
    p[0x84 / 4] = reinterpret_cast<unsigned long>(table84);
    p[0xa4 / 4] = reinterpret_cast<unsigned long>(tableA4);
    p[0xc4 / 4] = reinterpret_cast<unsigned long>(tableC4);
    p[0x130 / 4] = reinterpret_cast<unsigned long>(table130);
    return owner;
}

__forceinline String::String(void* owner) {
    stringDefaultConstruct(this);
}

inline String::String(const char* text) {
    stringTextConstruct(this, text);
}

inline String::~String() {
    stringDestroy(this);
}

struct Base {
    char storage[0x134];
    Base();
    ~Base();
    void setValue(const String&);
};

struct Guid {
    String value;
    const Name* scope;
    Guid(void* owner);
    ~Guid();
};

__forceinline Guid::Guid(void* owner)
    : value(owner), scope(&getLocalScope()) {
}

inline Guid::~Guid() {
}

struct S : Base {
    Guid guid;
    S();
};

S::S() : Base(), guid(installTables(this)) {
    String name(shirtGraphic);
    setValue(name);
}
