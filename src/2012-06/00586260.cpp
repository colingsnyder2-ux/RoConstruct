// from server: 100% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct CountedBase {
    virtual void v0();
    virtual void dispose();
    virtual void destroy();
    volatile long useCount;
    volatile long weakCount;

    void weakRelease() {
        if (_InterlockedDecrement(&weakCount) == 0) {
            destroy();
        }
    }
    void release() {
        if (_InterlockedDecrement(&useCount) == 0) {
            dispose();
            weakRelease();
        }
    }
};

struct Replicator {
    int query(int value);
};

struct ReplicatorPtr {
    Replicator* px;
    CountedBase* pn;
    ~ReplicatorPtr() {
        if (pn) {
            pn->release();
        }
    }
};

struct WeakReplicatorPtr {
    ReplicatorPtr lock() const;
    Replicator* px;
    CountedBase* pn;
};

struct Settings {
    char pad[0xb0];
    int value;
};

Settings* getSettings();

struct SendClusterJob {
    char pad[0x218];
    WeakReplicatorPtr replicator;
    bool check();
};

bool SendClusterJob::check() {
    ReplicatorPtr locked = replicator.lock();
    Replicator* target = locked.px;
    if (target) {
        return target->query(getSettings()->value) > 0;
    }
    return false;
}
