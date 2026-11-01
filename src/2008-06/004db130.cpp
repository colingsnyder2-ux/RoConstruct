// from server: 100% by king_originala
struct Mutex {
    unsigned char data[12];
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool active;
    Lock(Mutex*);
    ~Lock();
};

Lock::Lock(Mutex* p) : mutex(p) {
    mutex->lock();
    active = true;
}

Lock::~Lock() {
    if (active)
        mutex->unlock();
}

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct TreeA {
    unsigned char data[24];
    Node* head;
    unsigned int count;
    void erase(Node*);
};

struct TreeB {
    unsigned char data[24];
    Node* head;
    unsigned int count;
    void erase(Node*);
};

struct State {
    unsigned int unused;
    unsigned int count;
    void* storage;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void release();
};

extern State* state;
extern int initializationFlag;

void __cdecl initialize();
void __cdecl ensureInitialized(void (__cdecl*)(), int*);
void* __cdecl allocate(unsigned int, unsigned int);
void* __cdecl fill(void*, int, unsigned int);

void __cdecl reset()
{
    ensureInitialized(initialize, &initializationFlag);
    State* p = state;
    Lock lock(&p->mutex);

    p->release();
    p->capacity = 20;
    p->count = 0;
    p->storage = allocate(80, 16);
    fill(p->storage, 0, p->capacity * 4);

    TreeA* a = &p->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->count = 0;
    a->head->left = a->head;
    Node* n = a->head;
    n->right = n;

    TreeB* b = &p->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->count = 0;
    b->head->left = b->head;
    n = b->head;
    n->right = n;
}
