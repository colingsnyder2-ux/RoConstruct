// from server: 100% by king_originala
extern void __cdecl initialize(void (__cdecl*)(), void*);
extern void __cdecl initializeCallback();
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

struct Mutex {
    unsigned char data[12];
    void acquire();
    void release();
};

struct Guard {
    Mutex* mutex;
    bool acquired;
    Guard(Mutex*);
    ~Guard();
};

inline Guard::Guard(Mutex* p) : mutex(p) {
    mutex->acquire();
    acquired = true;
}

inline Guard::~Guard() {
    mutex->release();
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
    unsigned int unknown;
    unsigned int count;
    void* storage;
    unsigned int capacity;
    Mutex mutex;
    TreeA first;
    TreeB second;
    void clearStorage();
};

void resetState() {
    initialize(initializeCallback, reinterpret_cast<void*>(0x972750));
    State* s = *reinterpret_cast<State**>(0x972738);
    Guard guard(&s->mutex);
    s->clearStorage();
    s->capacity = 20;
    s->count = 0;
    s->storage = allocate(80, 16);
    fill(s->storage, 0, s->capacity * 4);

    TreeA* first = &s->first;
    first->erase(first->head->parent);
    first->head->parent = first->head;
    first->count = 0;
    first->head->left = first->head;
    first->head->right = first->head;

    TreeB* second = &s->second;
    second->erase(second->head->parent);
    second->head->parent = second->head;
    second->count = 0;
    second->head->left = second->head;
    second->head->right = second->head;
}
