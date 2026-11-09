// from server: 100% by king_originala
struct Mutex {
    unsigned char storage[12];
    void lock();
    void unlock();
};

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
    void release();
};

extern State* state;
extern int initialization;
extern void __cdecl initialize();
extern void __cdecl initializeOnce(void (__cdecl*)(), int*);
extern void* __cdecl allocateAligned(unsigned int, unsigned int);
extern void* __cdecl fillMemory(void*, int, unsigned int);

struct Guard {
    Mutex* mutex;
    bool locked;

    Guard(Mutex* p) : mutex(p) {
        mutex->lock();
        locked = true;
    }

    ~Guard() {
        if (locked)
            mutex->unlock();
    }
};

void reset()
{
    initializeOnce(initialize, &initialization);
    State* p = state;
    Guard guard(&p->mutex);

    p->release();
    p->capacity = 20;
    p->count = 0;
    p->data = allocateAligned(80, 16);
    fillMemory(p->data, 0, p->capacity * 4);

    TreeA* a = &p->first;
    a->erase(a->head->parent);
    a->head->parent = a->head;
    a->size = 0;
    a->head->left = a->head;
    a->head->right = a->head;

    TreeB* b = &p->second;
    b->erase(b->head->parent);
    b->head->parent = b->head;
    b->size = 0;
    b->head->left = b->head;
    b->head->right = b->head;
}
