// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)

extern "C" int (__stdcall *_imp__SetEvent)(void*);

struct OnceFlag { long status; };
extern OnceFlag onceFlag;
void onceInit();
void callOnce(OnceFlag& flag, void (*fn)());

struct Mutex {
    long active_count;
    void* event;
    Mutex() { active_count = 0; event = 0; }
    ~Mutex();
    void* get_event();
    void unlock() {
        long old_count = _InterlockedExchangeAdd(&active_count, (long)0x80000000);
        if (!(old_count & 0x40000000) && old_count > (long)0x80000000) {
            if (!_interlockedbittestandset(&active_count, 30)) {
                _imp__SetEvent(get_event());
            }
        }
    }
};

struct ScopedLock {
    Mutex* m;
    bool is_locked;
    ScopedLock(Mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~ScopedLock() {
        if (is_locked)
            m->unlock();
    }
    void lock();
};

struct S {
    void* value;
    bool isNull();
};

bool S::isNull() {
    callOnce(onceFlag, onceInit);
    static Mutex mutex;
    ScopedLock lock(mutex);
    return value == 0;
}
