// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /EHsc /MD
extern "C" long __cdecl _InterlockedExchangeAdd(long volatile*, long);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" unsigned char _interlockedbittestandset(long*, long);
#pragma intrinsic(_InterlockedExchangeAdd, _InterlockedIncrement, _interlockedbittestandset)
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
namespace detail {
struct basic_timed_mutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, 0x80000000);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!(_interlockedbittestandset(&active_count, 30) != 0)) {
                SetEvent(get_event());
            }
        }
    }
};
struct thread_data_base { virtual ~thread_data_base(); long count; };
inline void intrusive_ptr_add_ref(thread_data_base* p) { _InterlockedIncrement(&p->count); }
void intrusive_ptr_release(thread_data_base* p);
}
template<class T> class intrusive_ptr {
    T* p;
public:
    intrusive_ptr(const intrusive_ptr& r) : p(r.p) { if (p != 0) intrusive_ptr_add_ref(p); }
    ~intrusive_ptr() { if (p != 0) intrusive_ptr_release(p); }
};
class mutex : public detail::basic_timed_mutex {};
template<class Mutex> class unique_lock {
    Mutex* m;
    bool is_locked;
public:
    explicit unique_lock(Mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~unique_lock() { if (owns_lock()) m->unlock(); }
    void lock();
    bool owns_lock() const { return is_locked; }
};
template<> void unique_lock<mutex>::lock();
class thread {
    mutable mutex thread_info_mutex;
    intrusive_ptr<detail::thread_data_base> thread_info;
public:
    intrusive_ptr<detail::thread_data_base> get_thread_info() const;
};
intrusive_ptr<detail::thread_data_base> thread::get_thread_info() const
{
    unique_lock<mutex> l(thread_info_mutex);
    return thread_info;
}
}
