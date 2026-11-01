// from server: 87% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_08c6e637860fd1ee.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/bind.hpp>
#include <boost/function.hpp>
struct Ev { short a, b; };
class T { public: void m(Ev); };
typedef boost::_bi::bind_t<void, boost::_mfi::mf1<void, T, Ev>, boost::_bi::list2<boost::_bi::value<T*>, boost::_bi::value<Ev> > > B;
template struct boost::detail::function::void_function_obj_invoker0<B, void>;
