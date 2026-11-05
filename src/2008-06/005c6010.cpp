// from server: 100% by king_originala
struct String;

typedef String* (__thiscall *StringConstructor)(String*, const char*);
typedef void (__thiscall *StringDestructor)(String*);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text) {
    stringConstructor(this, text);
}

inline String::~String() {
    stringDestructor(this);
}

struct Base {
    Base(const String&, void*, const char*);
    virtual ~Base();
};

struct S : Base {
    S(void*);
    virtual ~S();
};

S::S(void* argument)
    : Base(String("AnchorVerb"), argument, "Anchored") {
}
