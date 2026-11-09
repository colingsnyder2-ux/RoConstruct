// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
namespace detail {
class shared_count {
    void* pi_;
public:
    template<class Y> explicit shared_count(Y* p);
    ~shared_count();
};
inline void sp_enable_shared_from_this(shared_count const&, ...) {}
}
template<class T> class shared_ptr {
public:
    template<class Y> explicit shared_ptr(Y* p) : px(p), pn(p) { detail::sp_enable_shared_from_this(pn, p, p); }
    T* px;
    detail::shared_count pn;
};
}
struct Item { int x; Item() : x(0) {} };
boost::shared_ptr<Item> gItem(new Item);
