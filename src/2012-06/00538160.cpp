// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)
extern "C" int (__stdcall* pSetEvent)(void*);

struct timed_mutex {
    volatile long active_count;
    void* event;
    void* get_event();
    void unlock() {
        long const offset = (long)0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, offset);
        if (!(old_count & 0x40000000) && old_count > offset) {
            if (!_interlockedbittestandset(&active_count, 30)) {
                pSetEvent(get_event());
            }
        }
    }
};

struct scoped_lock {
    timed_mutex* m;
    bool is_locked;
    explicit scoped_lock(timed_mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~scoped_lock() {
        if (is_locked)
            m->unlock();
    }
    void lock();
};

timed_mutex& get_mutex();

struct callable;

struct slot_owner {
    void remove(callable* c);
};

struct callable {
    char pad[0x10];
    slot_owner* owner;
    void disconnect();
};

void callable::disconnect() {
    if (owner != 0) {
        scoped_lock lock(get_mutex());
        slot_owner* p = owner;
        if (p != 0) {
            owner = 0;
            p->remove(this);
        }
    }
}
