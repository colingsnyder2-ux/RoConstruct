// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_3b21515b2ad75bf8.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#define NDEBUG
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
namespace RBX { class Instance; }
typedef boost::_bi::list4<boost::arg<1>, boost::arg<2>, boost::_bi::value<std::string>, boost::_bi::value<boost::shared_ptr<RBX::Instance> > > L4;
L4* makeL4(void* p, boost::arg<1> a1, boost::arg<2> a2, boost::_bi::value<std::string> a3, boost::_bi::value<boost::shared_ptr<RBX::Instance> > a4)
{ return new (p) L4(a1, a2, a3, a4); }
template L4::list4(boost::arg<1>, boost::arg<2>, boost::_bi::value<std::string>, boost::_bi::value<boost::shared_ptr<RBX::Instance> >);
