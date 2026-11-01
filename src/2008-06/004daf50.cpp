// from server: 100% by king_originala
struct Mutex {
    unsigned char data[12];
    void lock();
    void unlock();
};

struct Node {
    Node* left;
    Node* parent;
    Node* right;
};

struct TreeA {
    unsigned char data[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct TreeB {
    unsigned char data[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
};

struct State {
    unsigned int unknown;
    unsigned int count;
    void* buffer;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void reset();
};

struct Lock {
    Mutex* mutex;
    bool acquired;
    Lock(Mutex*);
    ~Lock();
};

inline Lock::Lock(Mutex* p) : mutex(p) {
    mutex->lock();
    acquired = true;
}

inline Lock::~Lock() {
    if (acquired)
        mutex->unlock();
}

extern State* instance;
extern unsigned int initialization;
extern void __cdecl initialize();
extern void __cdecl ensureInitialized(void (__cdecl*)(), unsigned int*);
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void __cdecl clearState() {
    ensureInitialized(initialize, &initialization);
    State* s = instance;
    Lock lock(&s->mutex);

    s->reset();
    s->capacity = 20;
    s->count = 0;
    s->buffer = allocate(80, 16);
    fill(s->buffer, 0, s->capacity * 4);

    TreeA* a = &s->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    a->head->right = a->head;

    TreeB* b = &s->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    b->head->right = b->head;
}
