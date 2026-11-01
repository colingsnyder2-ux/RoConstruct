// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail {
class sp_counted_base;
class shared_count {
    sp_counted_base* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
    ~shared_count();
};
inline void sp_enable_shared_from_this(shared_count const&, ...) {}
struct tss_cleanup_function {
    virtual ~tss_cleanup_function() {}
    virtual void operator()(void* data) = 0;
};
template<typename T> T* heap_new();
template<typename T> struct do_heap_delete { void operator()(T* data) const; };
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    template<class Y, class D> shared_ptr(Y* p, D d) : px(p), pn(p, d)
    { detail::sp_enable_shared_from_this(pn, p, p); }
};
template<typename T> class thread_specific_ptr {
    struct delete_data : detail::tss_cleanup_function {
        void operator()(void* data) { delete static_cast<T*>(data); }
    };
    shared_ptr<detail::tss_cleanup_function> cleanup;
public:
    thread_specific_ptr()
        : cleanup(detail::heap_new<delete_data>(), detail::do_heap_delete<delete_data>())
    {}
    ~thread_specific_ptr();
};
}
namespace RBX {
class DataModel {
public:
    class GenericJob;
    static boost::thread_specific_ptr<GenericJob*>& currentJob();
};
boost::thread_specific_ptr<DataModel::GenericJob*>& DataModel::currentJob()
{
    static boost::thread_specific_ptr<GenericJob*> job;
    return job;
}
}
