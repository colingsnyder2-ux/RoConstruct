// from server: 92% by EspClaude
// boost::detail::shared_count(P p, D d) analog; allocation size 0x14 from target push 0x14,
// catch funclet at 0x40ee49 calls the deleter out of line: lea ecx,[ebp+0xc]; push p; call.
// use/weak counts at +4/+8, pointer at +0xc, empty deleter by value (ret 8).

class sp_counted_base
{
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void* ti) = 0;
private:
    long use_count_;
    long weak_count_;
};

template<class P, class D> class sp_counted_impl_pd : public sp_counted_base
{
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
    virtual void dispose() { del(ptr); }
    virtual void* get_deleter(const void* ti) { return 0; }
};

struct CChildFrame;
struct null_deleter
{
    void operator()(CChildFrame* p) const;
};

class shared_count
{
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
};

template<class P, class D> shared_count::shared_count(P p, D d) : pi_(0)
{
    try
    {
        pi_ = new sp_counted_impl_pd<P, D>(p, d);
    }
    catch (...)
    {
        d(p);
        throw;
    }
}

struct CChildFrame;
template shared_count::shared_count(CChildFrame*, null_deleter);
