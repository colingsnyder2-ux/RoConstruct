// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" unsigned char __cdecl _interlockedbittestandset(long*, long);
#pragma intrinsic(_interlockedbittestandset)
extern "C" int (__stdcall* SetEvent_ptr)(void*);
extern "C" void (__cdecl* free_ptr)(void*);

struct Empty {};
struct Base {};
struct Node;
void intrusive_ptr_add_ref(Base*);
void call_once(long&, void (*)());
void init_once();

struct Ptr {
    Node* px;
    Ptr(const Ptr& o);
    ~Ptr();
    Ptr& operator=(const Ptr& o);
};

struct Node : Empty, Base {
    virtual ~Node();
    int pad;
    Ptr next;
};

inline void intrusive_ptr_release(Base* p) {
    Node* n = static_cast<Node*>(p);
    long* c = (long*)((char*)n - 8);
    if (_InterlockedDecrement(c) == 0) {
        n->~Node();
        if (_InterlockedDecrement(c + 1) == 0)
            free_ptr(c);
    }
}

inline Ptr::Ptr(const Ptr& o) : px(o.px) {
    if (px)
        intrusive_ptr_add_ref(px);
}

inline Ptr::~Ptr() {
    if (px)
        intrusive_ptr_release(px);
}

struct Mutex {
    long count;
    void* event;
    Mutex() { count = 0; event = 0; }
    ~Mutex();
    void* get_event();
    void unlock() {
        long const offset = (long)0x80000000;
        long const old = _InterlockedExchangeAdd(&count, offset);
        if (!(old & 0x40000000) && old > offset) {
            if (!_interlockedbittestandset(&count, 30))
                SetEvent_ptr(get_event());
        }
    }
};

struct Lock {
    Mutex* m;
    bool locked;
    Lock(Mutex& mm) : m(&mm), locked(false) { lock(); }
    ~Lock() {
        if (locked)
            m->unlock();
    }
    void lock();
};

struct S {
    Ptr head;
    bool step(Ptr& cur);
};

bool S::step(Ptr& cur) {
    Ptr old(cur);
    static long flag = 0;
    call_once(flag, init_once);
    static Mutex m;
    Lock lock(m);
    if (!cur.px)
        cur = head;
    else
        cur = cur.px->next;
    if (!cur.px)
        return false;
    return true;
}
