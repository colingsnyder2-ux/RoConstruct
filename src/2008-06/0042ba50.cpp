// from server: 100% by tester
typedef void (__cdecl *Manager)(void *, void *, int);

struct ManagerTable {
    Manager destroy;
};

struct Argument {
    ManagerTable *table;
    unsigned int reserved;
    char storage[28];

    ~Argument();
};

inline Argument::~Argument()
{
    if (table) {
        Manager destroy = table->destroy;
        if (destroy)
            destroy(storage, storage, 1);
    }
}

extern bool __cdecl func_0060a2f0(const Argument *);
extern void *__cdecl operator new(unsigned int);
extern void __cdecl func_00429040(void *, const Argument *);
extern ManagerTable managerTable;

struct ThreadLogManager {
    ManagerTable *table;
    unsigned int reserved;
    void *storage;

    ThreadLogManager(Argument argument);
};

ThreadLogManager::ThreadLogManager(Argument argument)
{
    table = 0;
    if (!func_0060a2f0(&argument)) {
        void *allocated = operator new(32);
        func_00429040(allocated, &argument);
        storage = allocated;
        table = &managerTable;
    } else {
        table = 0;
    }
}
