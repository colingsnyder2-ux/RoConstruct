// from server: 100% by king_originala
typedef void (__cdecl *Manager)(void *, void *, int);

struct Argument {
    unsigned char prefix[8];
    Manager *manager;
    unsigned char padding[4];
    unsigned char storage[28];

    ~Argument();
};

inline Argument::~Argument()
{
    if (manager) {
        Manager f = *manager;
        if (f)
            f(storage, storage, 1);
    }
}

extern bool __cdecl func_0060a2f0();
extern void *__cdecl allocate(unsigned int);
extern void __cdecl initialize(void *, Argument *);
extern Manager managerTable[];

struct S {
    Manager *manager;
    unsigned int padding;
    void *object;

    S(Argument argument);
};

S::S(Argument argument) : manager(0)
{
    typedef bool (__cdecl *Predicate)(Argument *);

    if (!reinterpret_cast<Predicate>(&func_0060a2f0)(&argument)) {
        void *p = allocate(40);
        initialize(p, &argument);
        object = p;
        manager = managerTable;
    } else {
        manager = 0;
    }
}
