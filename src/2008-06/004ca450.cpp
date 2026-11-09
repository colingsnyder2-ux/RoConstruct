// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_2684aee361fc9664.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
namespace RBX { class Instance; }
typedef boost::shared_ptr<RBX::Instance> (*Fn)(RBX::Instance*);
typedef boost::shared_ptr<const RBX::Instance> R;
template R boost::_bi::list1<boost::arg<1> >::operator()<R, Fn, boost::_bi::list1<RBX::Instance*&> >(boost::_bi::type<R>, Fn&, boost::_bi::list1<RBX::Instance*&>&, long);
