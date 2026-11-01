// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_a51f937aff3e4593.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX { class Instance; }
void handler(int a, int b, std::string s, boost::shared_ptr<RBX::Instance> p);
typedef boost::_bi::bind_t<void, void (*)(int, int, std::string, boost::shared_ptr<RBX::Instance>),
    boost::_bi::list4<boost::arg<1>, boost::arg<2>, boost::_bi::value<std::string>, boost::_bi::value<boost::shared_ptr<RBX::Instance> > > > B;
template struct boost::detail::function::void_function_obj_invoker2<B, void, int, int>;
