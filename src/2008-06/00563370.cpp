// from server: 100% by king_originala
struct String;

extern void (__thiscall *stringDefaultConstruct)(String *);
extern void (__thiscall *stringTextConstruct)(String *, const char *);
extern void (__thiscall *stringCopyConstruct)(String *, const String &);
extern void (__thiscall *stringDestroy)(String *);

extern const char productNameKey[];
extern const char fallbackName[];

struct String {
    unsigned char storage[28];

    String();
    String(const char *);
    String(const String &);
    ~String();
};

inline String::String() {
    stringDefaultConstruct(this);
}

inline String::String(const char *text) {
    stringTextConstruct(this, text);
}

inline String::String(const String &other) {
    stringCopyConstruct(this, other);
}

inline String::~String() {
    stringDestroy(this);
}

extern bool __cdecl readProductName(const String &, String &);

struct S {
    String f();
};

String S::f() {
    String result;
    bool found = readProductName(String(productNameKey), result);
    if (found)
        return result;
    return String(fallbackName);
}
