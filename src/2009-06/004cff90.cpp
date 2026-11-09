// from server: 100% by EspClaude
// roc 2009-06 004cff90  size: 305 bytes
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" unsigned char __cdecl _interlockedbittestandset(volatile long*, long);
#pragma intrinsic(_interlockedbittestandset)
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
};
class mutex {
public:
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, 0x80000000);
        if (!(old_count & 0x40000000) && (old_count > offset))
        {
            if (!(_interlockedbittestandset(&active_count, 30) != 0))
                SetEvent(get_event());
        }
    }
};
template<class M> class unique_lock {
public:
    M* m;
    bool is_locked;
    explicit unique_lock(M& m_) : m(&m_), is_locked(false) { lock(); }
    ~unique_lock() { if (is_locked) m->unlock(); }
    void lock();
};
}
namespace RBX {
class Dependency { public: char pad[0xd0]; boost::mutex mutex; };
class Object { public: void initialize(Dependency* d); };
boost::shared_ptr<Dependency> getDependency();
boost::shared_ptr<Object> makeObject();
extern Object* globalObject;
Object* getObject2()
{
    Dependency* d = getDependency().get();
    boost::unique_lock<boost::mutex> lock(d->mutex);
    if (!globalObject)
    {
        boost::shared_ptr<Object> o = makeObject();
        o->initialize(d);
    }
    return globalObject;
}
}
