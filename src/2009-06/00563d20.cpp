// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);

struct basic_timed_mutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = (long)0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, (long)0x80000000);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!_interlockedbittestandset(&active_count, 30)) {
                SetEvent(get_event());
            }
        }
    }
};

struct recursive_mutex {
    long recursion_count;
    long locking_thread_id;
    basic_timed_mutex mutex;
    void lock();
    void unlock()
    {
        if (!--recursion_count) {
            _InterlockedExchange(&locking_thread_id, 0);
            mutex.unlock();
        }
    }
};

struct unique_lock {
    recursive_mutex* m;
    bool is_locked;
    explicit unique_lock(recursive_mutex& m_) : m(&m_), is_locked(false) { m->lock(); is_locked = true; }
    ~unique_lock() { if (is_locked) m->unlock(); }
};

struct Node { Node* left; Node* parent; Node* right; };

struct Tree {
    unsigned char data[24];
    Node* head;
    unsigned int size;
    void erase(Node*);
    void clear()
    {
        erase(head->parent);
        head->parent = head;
        size = 0;
        head->left = head;
        head->right = head;
    }
};
struct Container {
    Tree tree;
    recursive_mutex mutex;
};

struct once_flag { long status; };
extern once_flag containerFlag;
void initContainer();
void __cdecl call_once(once_flag&, void (*)());
Container* getContainer();

void reset()
{
    call_once(containerFlag, &initContainer);
    Container* p = getContainer();
    unique_lock lock(p->mutex);
    p->tree.clear();
}
