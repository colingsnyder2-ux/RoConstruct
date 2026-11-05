// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);
typedef void (__cdecl *Callback)(const void *);

struct ManagerTable {
    Manager destroy;
};

extern ManagerTable managerTable;
extern "C" void __cdecl callback(const void *);

void *__cdecl operator new(unsigned int);
void __cdecl operator delete(void *);

struct Argument {
    ManagerTable *table;
    unsigned int reserved;
    char storage[24];

    Argument(Callback);
    ~Argument();
};

inline Argument::Argument(Callback fn)
{
    table = 0;
    Callback *target = reinterpret_cast<Callback *>(storage);
    if (managerTable.destroy)
        managerTable.destroy(target, target, 1);
    if (fn) {
        *target = fn;
        table = &managerTable;
    } else {
        table = 0;
    }
}

inline Argument::~Argument()
{
    if (table)
        table->destroy(storage, storage, 2);
}

struct Node {
    char data[32];
    Node(Argument, int);
};

struct S {
    void assign(Node *);
    S *f();
};

S *S::f()
{
    assign(new Node(callback, 0));
    return this;
}
