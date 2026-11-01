// from server: 100% by king_originala
struct String;

extern void (__thiscall *stringDefault)(String *);
extern void (__thiscall *stringFromText)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *);
extern unsigned long __cdecl getLocalScope();

struct String {
    unsigned char storage[28];
    String();
    String(const char *);
    ~String();
};

inline String::String() {
    stringDefault(this);
}

inline String::String(const char *text) {
    stringFromText(this, text);
}

inline String::~String() {
    stringDestroy(this);
}

struct Guid {
    String text;
    unsigned long scope;
    Guid();
};

inline Guid::Guid() : text(), scope(getLocalScope()) {
}

struct Vector {
    float x, y, z;
    Vector();
};

inline Vector::Vector() : x(1.0f), y(1.0f), z(1.0f) {
}

struct Base {
    unsigned long words[76];
    Base();
    ~Base();
    void setName(const String &);
};

struct S : Base {
    unsigned long type;
    Vector scale;
    Guid mesh;
    Guid texture;
    Vector vertexColor;

    S();
    unsigned long initializeTables();
};

inline unsigned long S::initializeTables() {
    words[0] = 0x833584;
    words[4] = 0x833578;
    words[5] = 0x833570;
    words[8] = 0x833568;
    words[9] = 0x833558;
    words[17] = 0x833548;
    words[25] = 0x833538;
    words[33] = 0x833528;
    words[41] = 0x833518;
    words[49] = 0x833508;
    return 0;
}

S::S()
    : Base(),
      type(initializeTables()),
      scale(),
      mesh(),
      texture(),
      vertexColor() {
    setName(String("Mesh"));
}
