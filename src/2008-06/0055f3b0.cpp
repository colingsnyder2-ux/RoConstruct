// from server: 100% by king_originala
typedef void (__cdecl *Manager)(const void *, void *, int);

struct Function {
    Manager *manager;
    union Storage {
        double alignment[3];
        char bytes[24];
    } storage;

    Function(int, int, Function);
    Function(const Function &);
    ~Function();
};

struct Result {
    void *value;
    Function function;

    Result(void *, const Function &);
};

inline Function::Function(const Function &other) : manager(0)
{
    if (other.manager) {
        manager = other.manager;
        (*other.manager)(&other.storage, &storage, 0);
    }
}

inline Function::~Function()
{
    if (manager) {
        Manager m = *manager;
        if (m)
            m(&storage, &storage, 1);
        manager = 0;
    }
}

inline Result::Result(void *p, const Function &f)
    : value(p), function(f)
{
}

Result __cdecl reconstruct(void *p, int a, int b, Function f)
{
    return Result(p, Function(a, b, f));
}
