// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class shared_ptr { public: T* px; void* pn; };
namespace _mfi {
template<class R, class T, class A1, class A2, class A3> class mf3 {
public:
    typedef R (T::*F)(A1, A2, A3);
private:
    F f_;
    template<class U, class B1, class B2, class B3>
    R call(U& u, T const*, B1& b1, B2& b2, B3& b3) const;
    template<class U, class B1, class B2, class B3>
    R call(U& u, void const*, B1& b1, B2& b2, B3& b3) const;
public:
    template<class U> R operator()(U& u, A1 a1, A2 a2, A3 a3) const
    {
        return call(u, &u, a1, a2, a3);
    }
};
}
}
namespace RBX {
class A { public: virtual ~A(); };
class B { public: virtual ~B(); };
class C : public A, public B { public: void f(std::string, int, std::string); };
}
template void boost::_mfi::mf3<void, RBX::C, std::string, int, std::string>::operator()(boost::shared_ptr<RBX::C>&, std::string, int, std::string) const;
