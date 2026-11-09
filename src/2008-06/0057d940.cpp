// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_sharedparentcallbackb4149b7636d9f1a5.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
class Instance;
void setParent(Instance*,bool);
void func(boost::shared_ptr<Instance> value){setParent(value.get(),true);}
