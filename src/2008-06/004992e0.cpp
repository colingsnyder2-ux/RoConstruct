// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_f705deee62b6bd19.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <list>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance;
class Context;
void visit(const boost::shared_ptr<Instance>& item, Context* context);
}
typedef boost::_bi::bind_t<void, void (*)(const boost::shared_ptr<RBX::Instance>&, RBX::Context*),
	boost::_bi::list2<boost::arg<1>, boost::_bi::value<RBX::Context*> > > VisitFn;
template VisitFn std::for_each<std::list<boost::shared_ptr<RBX::Instance> >::iterator, VisitFn>(
	std::list<boost::shared_ptr<RBX::Instance> >::iterator, std::list<boost::shared_ptr<RBX::Instance> >::iterator, VisitFn);
