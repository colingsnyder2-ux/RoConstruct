// from server: 92% by EspClaude
// roc 2007-08 004a8b90  std::map<boost::shared_ptr<Instance>, boost::signals::connection>::_Buynode (VS2005 xtree)
// roc-flags: /O2 /GS /EHsc /MD
#include <map>
#include <intrin.h>
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
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
    sp_counted_base* pi_;
public:
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
template<class T> inline bool operator<(const shared_ptr<T>& a, const shared_ptr<T>& b) { return a.px < b.px; }
namespace signals {
class connection {
public:
    connection(const connection&);
    ~connection();
private:
    void* base;
    boost::shared_ptr<void> con;
    bool controlling_connection;
};
}
}
namespace RBX { class Instance; }
template class std::_Tree<std::_Tmap_traits<boost::shared_ptr<RBX::Instance>, boost::signals::connection, std::less<boost::shared_ptr<RBX::Instance> >, std::allocator<std::pair<const boost::shared_ptr<RBX::Instance>, boost::signals::connection> >, false> >;
