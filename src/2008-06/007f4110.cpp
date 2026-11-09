// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail {
class sp_counted_base;
class shared_count {
public:
    sp_counted_base* pi_;
    template<class Y> explicit shared_count(Y* p);
    ~shared_count();
};
template<class T, class Y> void sp_enable_shared_from_this(const shared_count& pn, T* pe, Y* px) throw();
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    template<class Y> explicit shared_ptr(Y* p) : px(p), pn(p)
    {
        detail::sp_enable_shared_from_this(pn, p, p);
    }
};
}
namespace RBX {
class Registry {
public:
    char pad[8];
    Registry();
};
boost::shared_ptr<Registry> registry(new Registry());
}
