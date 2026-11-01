// from server: 100% by king_originala
struct Lock {
    int value;
    unsigned char flag;
    int count;
    void acquire();
    void release();
};

struct Node {
    Node *left;
    Node *parent;
    Node *right;
};

struct Container {
    unsigned char padding[24];
    Node *head;
    unsigned int size;
    Lock lock;
    void erase(Node *);
};

struct Guard {
    Lock *lock;
    bool held;
    Guard(Lock *);
    ~Guard();
};

inline Guard::Guard(Lock *p) : lock(p)
{
    lock->acquire();
    held = true;
}

inline Guard::~Guard()
{
    if (held)
        lock->release();
}

extern Container *container;
extern int initialization;
extern void __cdecl initialize();
extern void __cdecl ensureInitialized(void (__cdecl *)(), void *);

void __cdecl func_004e5670()
{
    ensureInitialized(initialize, &initialization);
    Container *p = container;
    Guard guard(&p->lock);
    p->erase(p->head->parent);
    p->head->parent = p->head;
    p->size = 0;
    p->head->left = p->head;
    p->head->right = p->head;
}
