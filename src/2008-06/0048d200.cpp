// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_008b0497e9ea3b3b.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
namespace RBX { class RunService; class DataModel; }
typedef boost::shared_ptr<RBX::RunService> SA;
typedef boost::shared_ptr<RBX::DataModel> SB;
typedef void (*Fn)(SA, SB, int, int);
template boost::_bi::bind_t<void, Fn, boost::_bi::list_av_4<SA, SB, boost::arg<1>, boost::arg<2> >::type>
boost::bind<void, SA, SB, int, int, SA, SB, boost::arg<1>, boost::arg<2> >(Fn, SA, SB, boost::arg<1>, boost::arg<2>);
