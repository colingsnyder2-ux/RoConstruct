// from server: 100% by nuck16
// roc 2009-12 0049c070  unit: RBX::VPBBBuilder::?$BuilderLevelGenFunc
// boost::detail::shared_count::shared_count(Y *p): pi_ = new sp_counted_impl_p<Y>(p)
// (0x9b3968 is that class's vtable; the catch funclet that deletes p and rethrows lies outside this extent)
struct sp_counted_base
{
    int vtable;
    long use_count_;
    long weak_count_;
    sp_counted_base() : use_count_(1), weak_count_(1) {}
};

struct sp_counted_impl_p : sp_counted_base
{
    void *px_;
    sp_counted_impl_p(void *px) { vtable = 0x9b3968; px_ = px; }
};

void checked_delete(void *p);

struct shared_count
{
    sp_counted_base *pi_;
    shared_count(void *p);
};

shared_count::shared_count(void *p) : pi_(0)
{
    try
    {
        pi_ = new sp_counted_impl_p(p);
    }
    catch (...)
    {
        checked_delete(p);
        throw;
    }
}
