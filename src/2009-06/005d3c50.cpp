// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
namespace boost {
namespace detail {
class sp_counted_base {
public:
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(shared_count const& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
};
}
namespace RBX {
class A; class B; class Item;
struct Args {
    boost::shared_ptr<A> a;
    boost::shared_ptr<B> b;
    ~Args();
};
typedef void (*VisitFn)(Item*, const Args&);
struct Visitor {
    VisitFn fn;
    Args args;
};
class Node {
public:
    void visit(Visitor v);
};
class Holder {
public:
    Node* node;
    void visit(Visitor v);
};
void Holder::visit(Visitor v)
{
    if (node)
        node->visit(v);
}
}
