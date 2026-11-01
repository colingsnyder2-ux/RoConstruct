// from server: 100% by colin
struct sp_counted_base {
    virtual void dispose(int);
};

struct sp_counted_impl_p {
    void dispose();
};

void sp_counted_impl_p::dispose()
{
    sp_counted_base* p = *(sp_counted_base**)((char*)this + 8);
    if (p)
        p->dispose(1);
}
