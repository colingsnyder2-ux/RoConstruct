// from server: 100% by king_originala
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
            invoke(storage, storage, 1);
        manager = 0;
    }
}

struct S {
    unsigned char data[64];
    int value;

    void initialize(Function function, String text);
    S(Function function, String text, int number);
};

S::S(Function function, String text, int number) {
    initialize(function, text);
    value = number;
}
