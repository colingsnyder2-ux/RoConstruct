// from server: 100% by king_originala
struct ContentProvider {
    int value;
    unsigned char flag;
    int count;
    void enter();
    void f();
};

struct FunctionTable {
    void (__cdecl *manager)(void *, void *, int);
    void (__cdecl *invoke)(void *, void *);
};

struct Function {
    FunctionTable *table;
    unsigned int reserved;
    unsigned char storage[24];
    void f(void *);
    ~Function();
};

__forceinline Function::~Function()
{
    if (table) {
        void (__cdecl *manager)(void *, void *, int) = table->manager;
        if (manager)
            manager(storage, storage, 1);
    }
}

struct Guard {
    ContentProvider *provider;
    bool locked;
    Guard(ContentProvider *);
    ~Guard();
};

__forceinline Guard::Guard(ContentProvider *p)
    : provider(p)
{
    provider->enter();
    locked = true;
}

__forceinline Guard::~Guard()
{
    if (locked)
        provider->f();
}

struct S {
    unsigned char padding[0x130];
    ContentProvider provider;
    void *object;
    void f(Function callback);
};

void S::f(Function callback)
{
    Guard guard(&provider);
    void *p = object;
    if (p)
        callback.f(p);
}
