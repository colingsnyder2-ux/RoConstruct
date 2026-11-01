// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" long __cdecl _InterlockedDecrement(long volatile*);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)
#pragma intrinsic(_InterlockedIncrement)
namespace boost { namespace detail {
class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    sp_counted_base(): use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_add_ref() { _InterlockedIncrement(&weak_count_); }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(): pi_(0) {}
    shared_count(const shared_count& r): pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
class weak_count {
public:
    sp_counted_base* pi_;
    weak_count(): pi_(0) {}
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};
}
template<class T> class shared_ptr { public: T* px; detail::shared_count pn; };
template<class T> class weak_ptr { public: T* px; detail::weak_count pn; };
}
namespace std { template<class E> struct char_traits; template<class T> class allocator;
template<class E, class T, class A> class __declspec(dllimport) basic_string { public: ~basic_string(); char buf[0x1c]; };
typedef basic_string<char, char_traits<char>, allocator<char> > string; }
namespace RBX {
class Y;
class X { public: char d[0x18]; ~X(); };
class Holder {
public:
    int a;
    std::string name;
    X x;
    boost::shared_ptr<Y> b;
    ~Holder();
};
Holder::~Holder() {}
}
