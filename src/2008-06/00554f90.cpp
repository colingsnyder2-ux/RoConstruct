// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1 function_b.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
struct T;
#include <boost/function.hpp>
template class boost::function<void (bool)>;
