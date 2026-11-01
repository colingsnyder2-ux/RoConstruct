// from server: 100% by king_originala
struct Manager {
    void (__cdecl *destroy)(void *, void *, int);
};

struct Argument {
    unsigned char prefix[8];
    const Manager *manager;
    unsigned char reserved[4];
    unsigned char storage[44];

    ~Argument();
};

inline Argument::~Argument()
{
    if (manager) {
        void (__cdecl *fn)(void *, void *, int) = manager->destroy;
        if (fn)
            fn(storage, storage, 1);
    }
}

extern bool __cdecl func_0060a2f0();
extern void *__cdecl allocate(unsigned int);
extern void __cdecl construct(void *, const Argument *);
extern const Manager allocatedManager;

struct S {
    const Manager *manager;
    unsigned int reserved;
    void *object;

    S(Argument argument);
};

S::S(Argument argument)
{
    manager = 0;
    if (!reinterpret_cast<bool (__cdecl *)(Argument *)>(
            func_0060a2f0)(&argument)) {
        void *p = allocate(56);
        construct(p, &argument);
        object = p;
        manager = &allocatedManager;
    } else {
        manager = 0;
    }
}
