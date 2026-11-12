// from server: 92% by EspClaude
// roc 2007-08 0040d2a0  unit: ChatEnter  size: 121 bytes
// boost 1.34 shared_count(P p, D d) shape: new sp_counted_impl_pd (0x14 bytes), catch(...) { d(p); throw; }
// catch funclet in exe after ret 8: mov edx,[ebp+8]; push edx; lea ecx,[ebp+0xc]; call deleter (thiscall, out-of-line)

class sp_counted_base {
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(int const&) = 0;
private:
    long use_count_;
    long weak_count_;
};

struct ChatEnter;

struct null_deleter {
    void operator()(ChatEnter* p) const;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base {
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(int const&) { return 0; }
};

class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
};

template<class P, class D> shared_count::shared_count(P p, D d) : pi_(0)
{
    try {
        pi_ = new sp_counted_impl_pd<P, D>(p, d);
    } catch (...) {
        d(p);
        throw;
    }
}

template shared_count::shared_count(ChatEnter*, null_deleter);
