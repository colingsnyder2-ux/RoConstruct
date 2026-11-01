// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace boost {
template<int I> struct arg {};
namespace _bi {
template<class T> class value { public: value(T const& t) : t_(t) {} T t_; };
template<class A1> struct storage1 { explicit storage1(A1 a1) : a1_(a1) {} A1 a1_; };
template<class A1, class A2> struct storage2 : public storage1<A1> { storage2(A1 a1, A2 a2) : storage1<A1>(a1), a2_(a2) {} A2 a2_; };
template<class A1, int I> struct storage2<A1, boost::arg<I> > : public storage1<A1> { storage2(A1 a1, boost::arg<I>) : storage1<A1>(a1) {} };
template<class A1, class A2, class A3> struct storage3 : public storage2<A1, A2> { storage3(A1 a1, A2 a2, A3 a3); A3 a3_; };
template<class A1, class A2, class A3, class A4> struct storage4 : public storage3<A1, A2, A3> { storage4(A1 a1, A2 a2, A3 a3, A4 a4); A4 a4_; };
template<class A1, class A2, class A3, class A4, class A5> struct storage5 : public storage4<A1, A2, A3, A4> { storage5(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5); A5 a5_; };
template<class A1, class A2, class A3, class A4, class A5> class list5 : private storage5<A1, A2, A3, A4, A5> {
	typedef storage5<A1, A2, A3, A4, A5> base_type;
public:
	list5(A1 a1, A2 a2, A3 a3, A4 a4, A5 a5) : base_type(a1, a2, a3, a4, a5) {}
};
}
}
namespace RBX { class Instance; }
template class boost::_bi::list5<boost::_bi::value<RBX::Instance*>, boost::arg<1>, boost::_bi::value<std::string>, boost::_bi::value<double>, boost::_bi::value<int> >;
