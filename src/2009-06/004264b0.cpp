// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace boost {
namespace detail {
class shared_count {
    void* pi_;
public:
    template<class P, class D> shared_count(P p, D d);
    ~shared_count();
};
void sp_enable_shared_from_this(const shared_count&, ...) throw();
}
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    template<class Y, class D> __forceinline shared_ptr(Y* p, D d) : px(p), pn(p, d)
    {
        detail::sp_enable_shared_from_this(pn, p, p);
    }
};
}
struct Heap { virtual ~Heap(); };
struct HeapDeleter { void operator()(Heap*); };
Heap* createHeap();
boost::shared_ptr<Heap>& getHeap() { static boost::shared_ptr<Heap> theHeap(createHeap(), HeapDeleter()); return theHeap; }
