// from server: 100% by king_originala
struct Function;

typedef void (__cdecl *Manager)(void*, void*, int);

struct FunctionTable {
    Manager manager;
};

struct Function {
    FunctionTable* table;
    unsigned int reserved;
    unsigned int buffer[6];
    ~Function();
};

inline Function::~Function()
{
    if (table) {
        Manager manager = table->manager;
        if (manager)
            manager(buffer, buffer, 1);
    }
}

struct Mutex {
    void* handle;
    char kind;
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool locked;
    Lock(Mutex& value);
    ~Lock();
};

inline Lock::Lock(Mutex& value) : mutex(&value)
{
    mutex->lock();
    locked = true;
}

inline Lock::~Lock()
{
    if (locked)
        mutex->unlock();
}

struct Queue {
    unsigned int reserved[4];
    void** blocks;
    unsigned int capacity;
    unsigned int start;
    unsigned int count;
    void append(const void* value);
};

struct S {
    unsigned char reserved[0x2ac];
    Mutex mutex;
    Queue queue;
    void f(Function value);
};

void S::f(Function value)
{
    Lock lock(mutex);
    queue.append(&value);
}
