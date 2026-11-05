// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) { destroy(); } }
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::sp_counted_base* pn;
    shared_ptr(const shared_ptr& o);
    ~shared_ptr() { if (pn != 0) pn->release(); }
};
template<class T> T* get_pointer(T* p) { return p; }
namespace _mfi {
template<class R, class T, class A1, class A2> class mf2 {
public:
    typedef R (T::*F)(A1, A2);
private:
    F f_;
    template<class U, class B1, class B2> R call(U& u, void const*, B1& b1, B2& b2) const;
public:
    template<class U> R operator()(U& u, A1 a1, A2 a2) const { return call(u, &u, a1, a2); }
};
}
}
namespace RBX {
class Instance;
class BaseA { public: virtual ~BaseA(); };
class BaseB { public: virtual ~BaseB(); };
class Owner : public BaseA, public BaseB { public: void onEvent(std::string, boost::shared_ptr<Instance>); };
class Derived : public Owner {};
}
template void boost::_mfi::mf2<void, RBX::Owner, std::string, boost::shared_ptr<RBX::Instance> >::operator()<RBX::Derived*>(RBX::Derived*&, std::string, boost::shared_ptr<RBX::Instance>) const;
