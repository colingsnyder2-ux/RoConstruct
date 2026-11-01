// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);

struct ManagerTable {
    Manager destroy;
};

extern ManagerTable functionTable;
extern void __cdecl threadEntry();

struct Argument {
    ManagerTable *table;
    unsigned int reserved;
    char storage[24];

    Argument(void (__cdecl *f)());
    ~Argument();
};

inline Argument::Argument(void (__cdecl *f)())
{
    table = 0;
    void *destination = storage;
    if (functionTable.destroy)
        functionTable.destroy(destination, destination, 1);
    if (f) {
        *reinterpret_cast<void (__cdecl **)()>(destination) = f;
        table = &functionTable;
    } else {
        table = 0;
    }
}

inline Argument::~Argument()
{
    if (table)
        table->destroy(storage, storage, 0);
}

struct Worker {
    char data[32];
    Worker(Argument, int);
};

struct ThreadLogManager {
    void assign(Worker *);
    ThreadLogManager *initialize();
};

ThreadLogManager *ThreadLogManager::initialize()
{
    Worker *worker = new Worker(threadEntry, 0);
    assign(worker);
    return this;
}
