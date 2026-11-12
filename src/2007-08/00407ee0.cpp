// from server: 92% by EspClaude
// boost 1.34 shared_count(P p, D d) with an empty deleter: new sp_counted_impl_pd (0x14 bytes)
namespace RBX { class ScriptContext; }

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int const& ti) = 0;
};

struct null_deleter { void operator()(void const*) const; };

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int const& ti) { return 0; }
};

class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d) : pi_(0)
    {
        try {
            pi_ = new sp_counted_impl_pd<P, D>(p, d);
        } catch (...) {
            d(p);
            throw;
        }
    }
};

template shared_count::shared_count(RBX::ScriptContext*, null_deleter);
