// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
namespace boost { namespace detail {
class sp_counted_base
{
public:
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    virtual void* get_deleter(const void*) = 0;
private:
    long use_count_;
    long weak_count_;
};
template<class T> class sp_ms_deleter
{
    bool initialized_;
    int storage_[sizeof(T) / sizeof(int)];
    void destroy()
    {
        if (initialized_)
        {
            reinterpret_cast<T*>(storage_)->~T();
            initialized_ = false;
        }
    }
public:
    sp_ms_deleter() : initialized_(false) {}
    sp_ms_deleter(const sp_ms_deleter&) : initialized_(false) {}
    ~sp_ms_deleter() { destroy(); }
    void operator()(T*) { destroy(); }
};
template<class P, class D> class sp_counted_impl_pd : public sp_counted_base
{
    P ptr;
    D del;
public:
    sp_counted_impl_pd(P p, D d);
    virtual void dispose();
    virtual void* get_deleter(const void*);
};
template<class P, class D> sp_counted_impl_pd<P, D>::sp_counted_impl_pd(P p, D d) : ptr(p), del(d) {}
}}struct Item;
struct Alloc { int dummy; };
void destroy_range(Item* f, Item* l, Alloc& a);
struct Vec
{
    Alloc al; Item* first; Item* last; Item* end;
    ~Vec() { if (first) { destroy_range(first, last, al); operator delete(first); } }
};
template class boost::detail::sp_counted_impl_pd<Vec*, boost::detail::sp_ms_deleter<Vec> >;
