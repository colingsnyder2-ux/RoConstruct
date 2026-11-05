// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned char storage[28];
    String(const char *s);
    ~String();
};

inline String::String(const char *s) {
    stringConstruct(this, s);
}

inline String::~String() {
    stringDestroy(this);
}

struct Base {
    Base(const String &, int, const char *);
    virtual ~Base();
};

struct S : Base {
    S(int);
    virtual ~S();
};

S::S(int value)
    : Base(String("TranslucentVerb"), value, "Transparent") {
}
