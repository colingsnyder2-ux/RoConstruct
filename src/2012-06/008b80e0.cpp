// from server: 96% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 signal_b.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
struct T;
#include <boost/signal.hpp>
template class boost::signal<void (bool)>;
