// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_765aa60e7fe58bd2.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/bind.hpp>
namespace RBX { struct Humanoid_006f5140; }
void cb_006f5140(RBX::Humanoid_006f5140* h, int a, int b, int v);
typedef boost::_bi::bind_t<void, void (*)(RBX::Humanoid_006f5140*, int, int, int),
    boost::_bi::list4<boost::_bi::value<RBX::Humanoid_006f5140*>, boost::arg<1>, boost::arg<2>, boost::_bi::value<int> > > B_006f5140;
template B_006f5140 boost::bind<void, RBX::Humanoid_006f5140*, int, int, int, RBX::Humanoid_006f5140*, boost::arg<1>, boost::arg<2>, int>(
    void (*)(RBX::Humanoid_006f5140*, int, int, int), RBX::Humanoid_006f5140*, boost::arg<1>, boost::arg<2>, int);
