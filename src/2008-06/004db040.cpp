// from server: 100% by king_originala
struct Mutex {
    unsigned char storage[12];
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool held;
    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* p) : mutex(p) {
    mutex->lock();
    held = true;
}

inline Lock::~Lock() {
    if (held)
        mutex->unlock();
}

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct TreeA {
    unsigned char storage[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct TreeB {
    unsigned char storage[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct State {
    unsigned int field0;
    unsigned int count;
    void* data;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void clear();
};

extern State* state;
extern unsigned int initialization;
extern void __cdecl initializeState();
extern void __cdecl initialize(void (__cdecl*)(), unsigned int*);
extern void* __cdecl alignedAllocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void resetState() {
    initialize(initializeState, &initialization);
    State* p = state;
    Lock guard(&p->mutex);

    p->clear();
    p->capacity = 20;
    p->count = 0;
    p->data = alignedAllocate(80, 16);
    fill(p->data, 0, p->capacity * 4);

    TreeA* a = &p->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    Node* n = a->head;
    n->right = n;

    TreeB* b = &p->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    n = b->head;
    n->right = n;
}
