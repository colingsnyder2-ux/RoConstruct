// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct String {
    unsigned char data[28];
    __declspec(dllimport) String(const String& other);
    __declspec(dllimport) ~String();
};
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
struct Base {
    unsigned char data[32];
    Base(Function function);
    ~Base();
};
struct Value {
    String t_;
    Value(const String& t) : t_(t) {}
};
struct S : Base {
    Value name;
    S(Function function, String text);
};
S::S(Function function, String text) : Base(function), name(text) {
}
