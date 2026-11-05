// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);

struct Argument {
    unsigned char prefix[8];
    Manager *manager;
    unsigned char padding[4];
    unsigned char storage[28];

    ~Argument();
};

struct Value {
    void *object;
    unsigned char padding[4];
    Manager *manager;
    unsigned char reserved[4];
    unsigned char storage[24];

    Value(const Argument &);
    Value(const Value &);
    ~Value();
};

inline Argument::~Argument()
{
    if (manager) {
        Manager f = *manager;
        if (f)
            f(storage, storage, 1);
    }
}

inline Value::Value(const Argument &other)
{
    object = *(void *const *)other.prefix;
    manager = 0;
    if (other.manager) {
        manager = other.manager;
        (*manager)((void *)other.storage, storage, 0);
    }
}

inline Value::~Value()
{
    if (manager) {
        Manager f = *manager;
        if (f)
            f(storage, storage, 1);
    }
}

struct S {
    S(Argument);
    void initialize(Value, int);
};

S::S(Argument argument)
{
    initialize(Value(argument), 0);
}
