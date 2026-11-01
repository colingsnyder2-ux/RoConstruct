// from server: 100% by king_originala
struct Mutex {
    void lock();
    void unlock();
};

struct Lock {
    Mutex* mutex;
    bool held;

    Lock(Mutex& m) : mutex(&m) {
        mutex->lock();
        held = true;
    }

    ~Lock() {
        if (held)
            mutex->unlock();
    }
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
    unsigned int field0;
    unsigned int size;
    void* buffer;
    unsigned int capacity;
    Mutex mutex;
    unsigned char padding[11];
    TreeA first;
    TreeB second;

    void clear();
};

extern void __cdecl initialize(void (__cdecl*)(), void*);
extern void __cdecl callback();
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void reset()
{
    initialize(callback, reinterpret_cast<void*>(0x972748));

    State* state = *reinterpret_cast<State**>(0x972730);
    Lock lock(state->mutex);

    state->clear();
    state->capacity = 20;
    state->size = 0;
    state->buffer = allocate(80, 16);
    fill(state->buffer, 0, state->capacity * 4);

    TreeA* first = &state->first;
    first->erase(first->head->parent);
    first->head->parent = first->head;
    first->size = 0;
    first->head->left = first->head;
    first->head->right = first->head;

    TreeB* second = &state->second;
    second->erase(second->head->parent);
    second->head->parent = second->head;
    second->size = 0;
    second->head->left = second->head;
    second->head->right = second->head;
}
