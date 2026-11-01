// from server: 100% by king_originala
typedef void (__cdecl *Manager)(const void *, void *, int);

struct Result;

struct Function {
    Manager *manager;
    union Storage {
        double alignment[3];
        char bytes[24];
    } storage;

    Function(Result, int);
    Function(const Function &);
    ~Function();
};

struct Result {
    double data[5];
    Result(const Result &);
};

struct String {
    unsigned char data[32];
};

extern unsigned char flag1;
extern unsigned char flag2;
extern void __cdecl callback();
extern Result __cdecl bindCallback(void (__cdecl *)(), int, int, Function);

struct S {
    void invoke(const String &, Function);
    void f(const String &, Function);
};

inline Function::Function(const Function &other)
{
    manager = 0;
    if (other.manager) {
        manager = other.manager;
        (*other.manager)(&other.storage, &storage, 0);
    }
}

inline Function::~Function()
{
    if (manager) {
        Manager destroy = *manager;
        if (destroy)
            destroy(&storage, &storage, 1);
    }
}

void S::f(const String &s, Function function)
{
    invoke(s, Function(bindCallback(callback, flag1, flag2, function), 0));
}
