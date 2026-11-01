// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count() : pi_(0) {}
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(shared_count const& r) {
        sp_counted_base* tmp = r.pi_;
        if (tmp != pi_) { if (tmp != 0) tmp->add_ref_copy(); if (pi_ != 0) pi_->release(); pi_ = tmp; }
        return *this;
    }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr() : px(0), pn() {}
    shared_ptr(shared_ptr const& r) : px(r.px), pn(r.pn) {}
    shared_ptr& operator=(shared_ptr const& r) { px = r.px; pn = r.pn; return *this; }
    void swap(shared_ptr& other) { T* tmp = px; px = other.px; other.px = tmp; pn.swap(other.pn); }
};
template<class T> inline bool operator<(shared_ptr<T> const& a, shared_ptr<T> const& b) { return a.pn.pi_ < b.pn.pi_; }
namespace detail { namespace win32 {
struct basic_timed_mutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock() {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, offset);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!_interlockedbittestandset(&active_count, 30)) {
                SetEvent(get_event());
            }
        }
    }
};
struct basic_recursive_timed_mutex {
    long recursion_count;
    long locking_thread_id;
    basic_timed_mutex mutex;
    void lock();
    void unlock() {
        if (!--recursion_count) {
            _InterlockedExchange(&locking_thread_id, 0);
            mutex.unlock();
        }
    }
};
}}
typedef detail::win32::basic_recursive_timed_mutex recursive_mutex;
template<class Mutex> class unique_lock {
    Mutex* m;
    bool is_locked;
public:
    explicit unique_lock(Mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~unique_lock() { if (is_locked) m->unlock(); }
    void lock() { m->lock(); is_locked = true; }
};
}
namespace RBX { class Instance; }
class CItemQueue {
public:
    virtual ~CItemQueue();
    char pad[0xc4 - 4];
    boost::recursive_mutex mutex;
    char pad2[0xec - 0xd4];
    std::set<boost::shared_ptr<RBX::Instance> > items;
    __declspec(noalias) void process(const boost::shared_ptr<RBX::Instance>& item);
    void processItems();
};
void CItemQueue::processItems()
{
    for (int i = 0; i < 10; ++i) {
        boost::shared_ptr<RBX::Instance> item;
        {
            boost::unique_lock<boost::recursive_mutex> lock(mutex);
            std::set<boost::shared_ptr<RBX::Instance> >::iterator it = items.begin();
            if (it == items.end())
                return;
            item = *it;
            items.erase(it);
        }
        process(item);
    }
}
