// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <vector>
#include <string>
namespace boost {
namespace program_options {
template<class charT> class basic_option { public: std::string string_key; int position_key; std::vector<std::string> value; std::vector<std::string> original_tokens; bool unregistered; bool case_insensitive; };
namespace detail {
struct cmdline_base1 { virtual ~cmdline_base1(); };
struct cmdline_base2 { virtual ~cmdline_base2(); };
class cmdline : public cmdline_base1, public cmdline_base2 { public: int x; };
}
}
template<class T> class type {};
namespace _mfi {
template<class R, class T, class A1> class mf1 {
public:
    typedef R (T::*F)(A1);
    F f_;
};
}
namespace _bi {
template<class T> class value { public: T t_; };
template<class A1> class list1 { public: A1 a1_; explicit list1(A1 a1) : a1_(a1) {} };
template<class A1, class A2> class list2 {
public:
    A1 a1_;
    template<class R, class F, class A> R operator()(type<R>, F & f, A & a, long);
};
template<class R, class F, class L> class bind_t {
public:
    typedef R result_type;
    template<class A1> result_type operator()(A1 & a1) {
        list1<A1 &> a(a1);
        return l_(type<result_type>(), f_, a, 0);
    }
    F f_;
    L l_;
};
}
template<int I> class arg {};
}
typedef std::vector<boost::program_options::basic_option<char> > RV;
typedef std::vector<std::string> SV;
typedef boost::_bi::bind_t<RV, boost::_mfi::mf1<RV, boost::program_options::detail::cmdline, SV&>, boost::_bi::list2<boost::_bi::value<boost::program_options::detail::cmdline*>, boost::arg<1> > > BT;
template RV BT::operator()<SV>(SV&);