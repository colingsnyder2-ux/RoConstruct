// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <stdlib.h>
#include <intrin.h>
extern unsigned char g_assertEnabled;
extern char (__cdecl *g_assertHook)(const char*, const char*, int);
void __cdecl g_assertFail(unsigned char, const char*);
#define FILE_ "C:\\TeamCity\\buildAgent\\work\\8348b47e373515f7\\Client\\Base\\include\\rbx/signal.h"
#define ASSERT_(cond, cs, line, lines) if (g_assertEnabled && !(cond)) { if (!g_assertHook || !g_assertHook(cs, FILE_, line)) g_assertFail(g_assertEnabled, cs " file: " FILE_ " line: " lines); }
void __cdecl callOnce(int* flag, void (*fn)());
extern int g_onceFlag;
void onceFn();
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
namespace noncopyable_ {
class noncopyable {
protected:
    noncopyable() {}
    ~noncopyable() {}
private:
    noncopyable(const noncopyable&);
    const noncopyable& operator=(const noncopyable&);
};
}
typedef noncopyable_::noncopyable noncopyable;
namespace detail {
namespace win32 {
using ::SetEvent;
inline bool interlocked_bit_test_and_set(long* x, long bit) { return _interlockedbittestandset(x, bit) != 0; }
}
struct basic_timed_mutex {
    static const unsigned char lock_flag_bit = 31;
    static const unsigned char event_set_flag_bit = 30;
    static const long lock_flag_value = 1 << lock_flag_bit;
    static const long event_set_flag_value = 1 << event_set_flag_bit;
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = lock_flag_value;
        long const old_count = _InterlockedExchangeAdd(&active_count, lock_flag_value);
        if (!(old_count & event_set_flag_value) && (old_count > offset)) {
            if (!win32::interlocked_bit_test_and_set(&active_count, event_set_flag_bit)) {
                win32::SetEvent(get_event());
            }
        }
    }
};
}
class mutex : public detail::basic_timed_mutex {
public:
    mutex() { active_count = 0; event = 0; }
    ~mutex();
};
template<typename Mutex>
class unique_lock {
    Mutex* m;
    bool is_locked;
public:
    explicit unique_lock(Mutex& m_) : m(&m_), is_locked(false) { lock(); }
    void lock();
    bool owns_lock() const { return is_locked; }
    ~unique_lock() { if (owns_lock()) { m->unlock(); } }
};
template<class T>
class intrusive_ptr {
    T* px;
public:
    intrusive_ptr() : px(0) {}
    intrusive_ptr(T* p) : px(p) { if (px != 0) intrusive_ptr_add_ref(px); }
    intrusive_ptr(const intrusive_ptr& rhs) : px(rhs.px) { if (px != 0) intrusive_ptr_add_ref(px); }
    ~intrusive_ptr() { if (px != 0) intrusive_ptr_release(px); }
    intrusive_ptr& operator=(const intrusive_ptr& rhs) { intrusive_ptr(rhs).swap(*this); return *this; }
    intrusive_ptr& operator=(T* rhs) { intrusive_ptr(rhs).swap(*this); return *this; }
    void swap(intrusive_ptr& rhs) { T* tmp = px; px = rhs.px; rhs.px = tmp; }
    T* get() const { return px; }
    T* operator->() const { return px; }
};
}
namespace rbx {
template<class T, class Count = int, int a = 0, int b = 0>
class intrusive_ptr_target {
public:
    struct counts { long strong; long weak; };
};
template<class T, class Count, int a, int b>
void intrusive_ptr_add_ref(const intrusive_ptr_target<T, Count, a, b>* p);
template<class T, class Count, int a, int b>
void intrusive_ptr_release(const intrusive_ptr_target<T, Count, a, b>* p)
{
    T* t = const_cast<T*>(static_cast<const T*>(p));
    typename intrusive_ptr_target<T, Count, a, b>::counts* c = reinterpret_cast<typename intrusive_ptr_target<T, Count, a, b>::counts*>(t) - 1;
    if (_InterlockedDecrement(&c->strong) == 0) {
        t->~T();
        if (_InterlockedDecrement(&c->weak) == 0)
            free(c);
    }
}
template<int N, typename Signature>
class icallable {
public:
    virtual void call() = 0;
};
namespace signals {
class connection {
public:
    class islot : boost::noncopyable, public rbx::intrusive_ptr_target<islot> {
    public:
        virtual ~islot();
        virtual void disconnect() = 0;
        virtual bool connected() const = 0;
    };
};
template<typename Signature>
class signal {
public:
    class slot : public connection::islot, public rbx::icallable<1, Signature> {
    public:
        boost::intrusive_ptr<slot> next;
        signal* sig;
    };
    boost::intrusive_ptr<slot> head;
    static boost::mutex& mutex() { callOnce(&g_onceFlag, &onceFn); static boost::mutex m; return m; }
    void insert(slot* item);
};
template<typename Signature>
void signal<Signature>::insert(slot* item)
{
    ASSERT_(item, "item", 0x11b, "283")
    boost::unique_lock<boost::mutex> lock(mutex());
    slot* next = head.get();
    if (!next) { head = item; return; }
    boost::intrusive_ptr<slot> n(next);
    boost::intrusive_ptr<slot> unused;
    item->next = n;
        ASSERT_(next == head.get(), "next == head", 0x12f, "303")
    head = item;
}
}
}
template void rbx::signals::signal<void()>::insert(slot*);



