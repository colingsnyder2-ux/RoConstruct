// from server: 100% by tester
#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
};

class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(const weak_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->weak_add_ref(); }
};
}

template<class T>
class weak_ptr {
public:
    T* px;
    detail::weak_count pn;
};
}

struct Item;

struct Owner {
    boost::weak_ptr<Item> item;
    boost::weak_ptr<Item> get() const;
};

boost::weak_ptr<Item> Owner::get() const
{
    volatile int state = 0;
    return item;
}
