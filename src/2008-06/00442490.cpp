// from server: 100% by EspClaude


extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" {
    __declspec(dllimport) int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);
}

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void *object;
    Control *control;

    Shared(const Shared &other) : object(other.object), control(other.control)
    {
        if (control) {
            volatile long *count = &control->strong;
            _InterlockedExchangeAdd(count, 1);
        }
    }

    ~Shared();
};

struct Change {
    Shared first;
    Shared second;
    ~Change();
};

struct Mutex {
    void *handle;
    bool criticalSection;
    unsigned int count;
    void lock();
    void unlock();
};

struct Lock {
    Mutex *mutex;
    bool held;

    Lock(Mutex &m) : mutex(&m), held(false)
    {
        mutex->lock();
        held = true;
    }

    ~Lock()
    {
        if (held)
            mutex->unlock();
    }
};

struct Node {
    Node *left;
    Node *parent;
    Node *right;
};

struct Tree {
    char padding[24];
    Node *head;
    unsigned int size;
    void erase(Node *);
};

struct Base {
    void first(Shared);
    void second(Shared);
};

struct Grid {
    char pad0[32];
    void *window;
    char pad1[396 - 36];
    Mutex mutex;
    char pad2[500 - 396 - sizeof(Mutex)];
    bool pending;
    void requestUpdate()
    {
        Lock lock(mutex);
        if (!pending) {
            if (window)
                PostMessageA(window, 1125, 0, 0);
            pending = true;
        }
    }
};

struct S {
    void f(int argument, Change change);
};

void S::f(int argument, Change change)
{
    if (change.first.object)
        reinterpret_cast<Base *>(reinterpret_cast<char *>(this) - 568)->first(change.first);

    if (change.second.object)
        reinterpret_cast<Base *>(reinterpret_cast<char *>(this) - 568)->second(change.second);

    Lock lock(*reinterpret_cast<Mutex *>(reinterpret_cast<char *>(this) - 172));
    *reinterpret_cast<bool *>(reinterpret_cast<char *>(this) - 67) = true;

    Tree *tree = reinterpret_cast<Tree *>(reinterpret_cast<char *>(this) - 64);
    tree->erase(tree->head->parent);
    tree->head->parent = tree->head;
    tree->size = 0;
    tree->head->left = tree->head;
    tree->head->right = tree->head;

    reinterpret_cast<Grid *>(reinterpret_cast<char *>(this) - 568)->requestUpdate();
}
