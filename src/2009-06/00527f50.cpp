// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
inline bool interlocked_bit_test_and_set(long* x, long bit) { return _interlockedbittestandset(x, bit) != 0; }
struct TimedMutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock() {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, offset);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!interlocked_bit_test_and_set(&active_count, 30)) {
                SetEvent(get_event());
            }
        }
    }
};
struct Mutex {
    long recursion_count;
    long locking_thread_id;
    TimedMutex mutex;
    void lock();
    void unlock() {
        if (!--recursion_count) {
            _InterlockedExchange(&locking_thread_id, 0);
            mutex.unlock();
        }
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

extern unsigned int initialization;
extern void __cdecl initialize();
extern State* __cdecl getInstance();
extern void __cdecl ensureInitialized(void (__cdecl*)(), unsigned int*);
extern void* __cdecl allocate(unsigned int, unsigned int);
extern void* __cdecl fill(void*, int, unsigned int);

void __cdecl clearState() {
    ensureInitialized(initialize, &initialization);
    State* s = getInstance();
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
