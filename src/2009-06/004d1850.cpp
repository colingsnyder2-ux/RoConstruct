// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std { template<class E> struct char_traits; template<class T> class allocator;
template<class E, class T, class A> class __declspec(dllimport) basic_string { public: basic_string(const basic_string&); ~basic_string(); char buf[0x1c]; };
typedef basic_string<char, char_traits<char>, allocator<char> > string; }
namespace boost {
template<int I> struct arg {};
namespace _bi {
template<class T> struct value { T t_; value(const T& t): t_(t) {} };
template<class A1, class A2> struct list2 { A1 a1_; A2 a2_; };
template<int I, class A2> struct list2<arg<I>, A2> { A2 a2_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; };
}
template<class R, class B1, class B2, class A1, class A2>
_bi::bind_t<R, R(*)(B1, B2), _bi::list2<A1, _bi::value<A2> > > bind(R (*f)(B1, B2), A1 a1, A2 a2);
}
namespace { boost::arg<1> _1; }
namespace RBX {
class Instance;
void handler(Instance*, std::string);
class Holder {
public:
    template<class F> void assign(F f);
    void set(std::string s);
};
void Holder::set(std::string s)
{
    assign(boost::bind(&handler, _1, s));
}
}
