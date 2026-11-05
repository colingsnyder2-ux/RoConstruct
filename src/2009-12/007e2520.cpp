// from server: 100% by nuck16
// roc 2009-12 007e2520  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::delete_data
// boost::detail::shared_count::shared_count(P p, D d): pi_ = new sp_counted_impl_pd<P, D>(p, d)
// (0x9efd5c is that class's vtable; the catch funclet that calls d(p) and rethrows lies outside this extent)
struct Deleter
{
    void operator()(void *p) const;
};

struct sp_counted_base
{
    int vtable;
    long use_count_;
    long weak_count_;
    sp_counted_base() : use_count_(1), weak_count_(1) {}
};

struct sp_counted_impl_pd : sp_counted_base
{
    void *ptr;
    Deleter del;
    sp_counted_impl_pd(void *p, Deleter d) { vtable = 0x9efd5c; ptr = p; del = d; }
};

struct shared_count
{
    sp_counted_base *pi_;
    shared_count(void *p, Deleter d);
};

shared_count::shared_count(void *p, Deleter d) : pi_(0)
{
    try
    {
        pi_ = new sp_counted_impl_pd(p, d);
    }
    catch (...)
    {
        d(p);
        throw;
    }
}
