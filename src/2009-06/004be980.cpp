// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <vector>
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
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
class any {
public:
    any();
    any(const any&);
    ~any();
    any& operator=(const any&);
    template<class V> any& operator=(const V& v);
    void* content;
};
}
template<> std::vector<boost::any>::~vector();
namespace RBX {
class Instance;
class GenericSlotWrapper {
public:
    virtual ~GenericSlotWrapper();
    virtual void execute(const std::vector<boost::any>& arguments) = 0;
    void operator()(boost::shared_ptr<Instance> arg1);
};
void GenericSlotWrapper::operator()(boost::shared_ptr<Instance> arg1)
{
    std::vector<boost::any> arguments(1);
    arguments[0] = arg1;
    execute(arguments);
}
}
