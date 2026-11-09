// from server: 100% by king_originala
extern "C" int (__stdcall *PostMessageA)(void*, unsigned int, unsigned int, long);

struct FunctionTable {
    void (__cdecl *manager)(void*, void*, int);
};

struct Function {
    FunctionTable* table;
    unsigned int reserved;
    unsigned int storage[6];

    ~Function();
};

inline Function::~Function()
{
    if (table) {
        void (__cdecl *manager)(void*, void*, int) = table->manager;
        if (manager)
            manager(storage, storage, 1);
    }
}

struct Queue {
    unsigned int reserved[4];
    void** blocks;
    unsigned int capacity;
    unsigned int start;
    unsigned int count;

    void append(const void*);
};

struct Mutex {
    void* object;
    char kind;

    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool locked;

    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* value) : mutex(value)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        mutex->unlock();
}

struct Marshaller {
    unsigned int reserved;
    void* window;
    unsigned char padding[36];
    Queue queue;
    Mutex mutex;

    void submit(Function);
};

void Marshaller::submit(Function value)
{
    {
        Lock guard(&mutex);
        queue.append(&value);
    }
    PostMessageA(window, 0x465, 0, 0);
}
