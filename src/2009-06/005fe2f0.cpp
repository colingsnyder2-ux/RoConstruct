// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
struct once_flag { long epoch; };
template<typename Function> void call_once(once_flag& flag, Function f);
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
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
};
}
namespace RBX {
class Event { public: void* h; void Set(); };
struct Waiter { int pad; Event event; };
struct Tss { void set(void* v); };
extern boost::once_flag tssFlag;
void initTss();
Tss* getTss();
class ScopedState {
    void* oldValue;
    void* newValue;
    boost::shared_ptr<Waiter> waiter;
public:
    ~ScopedState();
};
ScopedState::~ScopedState()
{
    if (oldValue != newValue)
    {
        boost::call_once(tssFlag, &initTss);
        Tss* t = getTss();
        t->set(newValue);
        waiter->event.Set();
    }
}
}
