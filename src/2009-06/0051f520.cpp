// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> inline void checked_delete(T* x) { typedef char type_must_be_complete[sizeof(T) ? 1 : -1]; (void)sizeof(type_must_be_complete); delete x; }
template<class T> class scoped_ptr {
    T* px;
    typedef scoped_ptr<T> this_type;
public:
    explicit scoped_ptr(T* p = 0) : px(p) {}
    ~scoped_ptr() { boost::checked_delete(px); }
    void reset(T* p = 0) { this_type(p).swap(*this); }
    T* get() const { return px; }
    bool operator!() const { return px == 0; }
    void swap(scoped_ptr& b) { T* tmp = b.px; b.px = px; px = tmp; }
};
namespace detail {
class lightweight_mutex {
public:
    long l_;
    class scoped_lock {
        lightweight_mutex& m_;
    public:
        explicit scoped_lock(lightweight_mutex& m);
        ~scoped_lock();
    };
};
}
}
namespace RBX {
class Dictionary { public: char data[0x34]; Dictionary(); ~Dictionary(); };
template<int N> class Holder {
    boost::scoped_ptr<Dictionary> p;
    static boost::detail::lightweight_mutex mutex;
public:
    Dictionary* get();
};
template<int N> Dictionary* Holder<N>::get()
{
    if (!p) {
        boost::detail::lightweight_mutex::scoped_lock lock(mutex);
        if (!p)
            p.reset(new Dictionary());
    }
    return p.get();
}
template class Holder<0>;
}
