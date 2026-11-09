// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_13a81cd5a5b48c1c.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#define NDEBUG
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
namespace RBX { class Instance; class PartInstance; }
typedef void (*Fn)(boost::weak_ptr<RBX::Instance>, boost::weak_ptr<RBX::PartInstance>);
typedef boost::_bi::list2<boost::_bi::value<boost::weak_ptr<RBX::Instance> >, boost::_bi::value<boost::weak_ptr<RBX::PartInstance> > > L;
typedef boost::_bi::bind_t<void, Fn, L> B;
template bool boost::detail::function::basic_vtable0<void>::assign_to<B>(B, boost::detail::function::function_buffer&);
