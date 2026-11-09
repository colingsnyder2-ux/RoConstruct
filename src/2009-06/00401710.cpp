// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: boost-1.40.0 roc_espclaude_103e0396f72331de.cpp

// Candidate translation unit (score above; library headers required).
#define NDEBUG
#include <boost/thread/once.hpp>
template void boost::call_once<void(*)()>(boost::once_flag&, void(*)());
