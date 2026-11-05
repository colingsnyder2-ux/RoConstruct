// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_soundsharedstatsc127ce5793e59fd7.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <string>
#include "util/ContentProvider.h"
struct Value { char padding[8]; int count; };
typedef std::map<RBX::ContentId,boost::shared_ptr<Value> > Container;
void func(const Container* container,int* total,int* empty) {
 for(Container::const_iterator it=container->begin();it!=container->end();++it) {
  ++*total;
  if(it->second->count==0) ++*empty;
 }
}
