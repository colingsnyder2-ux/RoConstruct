// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_94bf03fd925cb760.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/bind.hpp>
#include <boost/function.hpp>
struct Ev { short a, b; }; class T { public: int m(Ev); };
typedef boost::_bi::bind_t<int, boost::_mfi::mf1<int, T, Ev>, boost::_bi::list2<boost::_bi::value<T*>, boost::_bi::value<Ev> > > B;
template struct boost::detail::function::function_obj_invoker0<B, int>;
