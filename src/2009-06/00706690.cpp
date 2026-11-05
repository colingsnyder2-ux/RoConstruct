// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct String;

extern String* (__thiscall *copy_string)(String*, const String&);
extern void (__thiscall *destroy_string)(String*);

struct String {
    unsigned char data[28];

    String(const String& other);
    ~String();
};

inline String::String(const String& other) {
    copy_string(this, other);
}

inline String::~String() {
    destroy_string(this);
}

struct Function {
    typedef void (__cdecl *Manager)(const void*, void*, int);

    struct Table {
        Manager invoke;
    };

    Table* manager;
    unsigned int reserved;
    unsigned char storage[24];

    Function(const Function& other);
    ~Function();
};

inline Function::Function(const Function& other) : manager(0) {
    if (other.manager) {
        manager = other.manager;
        other.manager->invoke(other.storage, storage, 0);
    }
}

inline Function::~Function() {
    if (manager) {
        Manager invoke = manager->invoke;
        if (invoke)
            invoke(storage, storage, 2);
        manager = 0;
    }
}

struct S {
    unsigned char data[64];
    int value;
    S(Function function, String text, struct P number);
};
struct P { int v; };
struct D : S {
    D(Function function, String text, P number);
};
D::D(Function function, String text, P number) : S(function, text, number) {}
