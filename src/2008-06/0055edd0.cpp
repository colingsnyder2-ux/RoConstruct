// from server: 100% by king_originala
typedef void (__cdecl *Manager)(const void *, void *, int);

struct Function {
    Manager *manager;
    union Storage {
        double alignment[3];
        char bytes[24];
    } storage;

    Function(const Function &);
    ~Function();
};

inline Function::Function(const Function &other) : manager(0)
{
    if (other.manager) {
        manager = other.manager;
        (*other.manager)(&other.storage, &storage, 0);
    }
}

typedef void (__cdecl *Invoke)(void *, void *, Function);

struct Object {
    Invoke invoke;
    unsigned int padding;
    Function function;
};

void __cdecl reconstruct(Object **object, void *a, void *b)
{
    Object *p = *object;
    p->invoke(a, b, p->function);
}
