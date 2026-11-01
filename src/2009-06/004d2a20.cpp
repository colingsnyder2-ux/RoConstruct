// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<class T> class shared_ptr {
public:
	T* px;
	void* pn;
	T* get() const { return px; }
};
template<class T> T* get_pointer(const shared_ptr<T>& p) { return p.get(); }
namespace _mfi {
template<class R, class T, class A1, class A2, class A3> class mf3 {
public:
	typedef R (T::*F)(A1, A2, A3);
	F f_;
	template<class U, class B1, class B2, class B3> R call(U& u, const void*, B1& b1, B2& b2, B3& b3) const { return (get_pointer(u)->*f_)(b1, b2, b3); }
};
}
}
namespace RBX { class __multiple_inheritance Target; }
typedef boost::_mfi::mf3<void, RBX::Target, std::string, int, std::string> MF;
template void MF::call<boost::shared_ptr<RBX::Target>, std::string, int, std::string>(boost::shared_ptr<RBX::Target>&, const void*, std::string&, int&, std::string&) const;
