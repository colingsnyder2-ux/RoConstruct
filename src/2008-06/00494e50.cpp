// from server: 61% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);

struct Function {
    Manager *manager;
    unsigned long reserved;
    unsigned long storage[18];

    Function(const Function &);
    ~Function();
};

inline Function::~Function()
{
    if (manager) {
        Manager callback = *manager;
        if (callback)
            callback(storage, storage, 1);
        manager = 0;
    }
}

struct Base {
    Base();
    ~Base();
};

struct S : Base {
    S(Function a, Function b);
    void finish(Function a, Function b);
};

S::S(Function a, Function b)
{
    finish(a, b);
}
