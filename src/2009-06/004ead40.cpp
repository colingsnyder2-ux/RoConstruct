// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; T* get() const { return px; } };
template<class T> inline T* get_pointer(shared_ptr<T> const& p) { return p.get(); }
namespace _mfi {
template<class R, class T, class A1, class A2> class mf2 {
public:
    typedef R (T::*F)(A1, A2);
private:
    template<class U, class B1, class B2> R call(U& u, void const*, B1& b1, B2& b2) const
    { return (get_pointer(u)->*f_)(b1, b2); }
    F f_;
public:
    template<class U> R operator()(U& u, A1 a1, A2 a2) const
    { U const* p = 0; return call(u, p, a1, a2); }
};
}
}
namespace RBX {
struct A1x { virtual ~A1x(); };
struct A2x { virtual ~A2x(); };
struct Target : A1x, A2x { void handler(std::string, int); };
}
template void boost::_mfi::mf2<void, RBX::Target, std::string, int>::operator()(boost::shared_ptr<RBX::Target>&, std::string, int) const;
