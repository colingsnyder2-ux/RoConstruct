// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
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

struct Base {
    unsigned long storage[0x130 / 4];
    Base();
    ~Base();
};

struct ObjectBase : Base {
    void* object;
    ObjectBase();
    ~ObjectBase();
};

__forceinline ObjectBase::ObjectBase() {
    storage[0x00 / 4] = 0x00838c04;
    storage[0x10 / 4] = 0x00838bf8;
    storage[0x14 / 4] = 0x00838bf0;
    storage[0x20 / 4] = 0x00838be8;
    storage[0x24 / 4] = 0x00838bd8;
    storage[0x44 / 4] = 0x00838bc8;
    storage[0x64 / 4] = 0x00838bb8;
    storage[0x84 / 4] = 0x00838ba8;
    storage[0xa4 / 4] = 0x00838b98;
    storage[0xc4 / 4] = 0x00838b88;
    object = 0;
}

struct Control {
    void* pointer;
    Control();
    ~Control();
};

__forceinline Control::Control() {
    pointer = 0;
}

struct S : ObjectBase {
    Control control;
    S();
    void setValue(const String&);
};

S::S() {
    setValue(String("Value"));
}
