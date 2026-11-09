// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_sharedcounterctor45a2a036f7e2eee5.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Owner {boost::shared_ptr<int> counter;bool active;Owner(const boost::shared_ptr<int>*);};
Owner::Owner(const boost::shared_ptr<int>* other):active(false){if(other){counter=*other;++*counter;}else counter.reset(new int(1));}
