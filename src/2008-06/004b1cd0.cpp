// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_markerownedvector_dc349ce740ba952e.cpp

// Candidate translation unit (score above; library headers required).
#include <vector>
#include <boost/shared_ptr.hpp>
typedef std::vector<boost::shared_ptr<void> > Temporary;
struct Receiver {virtual ~Receiver();virtual void invoke(Temporary*);};
struct S {Receiver* receiver;void f();};
void S::f() {Receiver* p=receiver;Temporary temporary;p->invoke(&temporary);}
