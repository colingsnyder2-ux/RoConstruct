// from server: 100% by king_originala
struct Manager {
    void (__cdecl *manage)(const void *, void *, int);
};

struct Function {
    Manager *manager;
    unsigned int padding;
    char storage[24];

    Function(const Function &other)
        : manager(0)
    {
        if (other.manager) {
            manager = other.manager;
            other.manager->manage(other.storage, storage, 0);
        }
    }

    ~Function()
    {
        if (manager) {
            void (__cdecl *callback)(const void *, void *, int) = manager->manage;
            if (callback)
                callback(storage, storage, 1);
        }
    }
};

struct S {
    char padding[32];
    int value;

    void set(Function function);
    S &f(Function function, int newValue);
};

S &S::f(Function function, int newValue)
{
    set(function);
    value = newValue;
    return *this;
}
