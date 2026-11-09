// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <deque>
#include <queue>
namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose()=0;
    virtual void destroy(){delete this;}
    long use_count_,weak_count_;
    void weak_add_ref(){_InterlockedIncrement(&weak_count_);}
    void weak_release(){if(_InterlockedDecrement(&weak_count_)==0)destroy();}
};
struct weak_count {
    sp_counted_base* pi_;
    weak_count(const weak_count& r):pi_(r.pi_){if(pi_)pi_->weak_add_ref();}
    ~weak_count(){if(pi_)pi_->weak_release();}
};
}
template<class T> class weak_ptr {
public:
    T* px; detail::weak_count pn;
};
}
namespace RBX {
class Instance;
class DebrisService {
public:
    char pad[0x8c];
    std::queue<boost::weak_ptr<Instance> > queue;
    int maxItems;
    void* timer;
    void cleanup();
};
}
void cleanup(boost::weak_ptr<RBX::Instance> item);
namespace RBX {
void DebrisService::cleanup()
{
    while ((int)queue.size() > maxItems)
    {
        ::cleanup(queue.front());
        queue.pop();
    }
}
}
