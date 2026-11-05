// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_de8872eb54bea549.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/signal.hpp>
#include <boost/shared_ptr.hpp>
namespace RBX { class Instance; }
typedef boost::shared_ptr<RBX::Instance> P;
typedef boost::function2<void, P, int> F;
typedef boost::signals::detail::call_bound2<void>::caller<P, int, F> C;
template boost::signals::detail::unusable C::operator()(const boost::signals::detail::connection_slot_pair&) const;
