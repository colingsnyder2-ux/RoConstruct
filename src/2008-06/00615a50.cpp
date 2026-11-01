// from server: 100% by king_originala
struct String;

extern String (__cdecl *prepend)(const char *, const String &);
extern String (__cdecl *append)(const String &, const char *);
extern void (__thiscall *copyString)(String *, const String &);
extern void (__thiscall *destroyString)(String *);

struct String {
    unsigned allocator;
    union {
        char buffer[16];
        char *pointer;
    } storage;
    unsigned length;
    unsigned capacity;

    String(const String &);
    ~String();
};

inline String::String(const String &other) {
    copyString(this, other);
}

inline String::~String() {
    destroyString(this);
}

struct Result {
    String text;
    unsigned value;

    Result(const Result &);
    ~Result();
    const Result &reference() const;
};

inline Result::Result(const Result &other)
    : text(other.text), value(other.value) {
}

inline Result::~Result() {
}

inline const Result &Result::reference() const {
    return *this;
}

extern Result __cdecl makeResult(const String &);

struct Tool {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual String name();

    Result getTexture();
};

Result Tool::getTexture() {
    return makeResult(append(prepend("Textures\\", name()), ".png")).reference();
}
