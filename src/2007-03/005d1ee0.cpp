// from server: 100% by colin
// roc-cl: 50727
// roc-lang: cpp
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_boundpropertyvirtual7ef855fee181828f.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"
#include "reflection/property.h"
struct VirtualBase{virtual ~VirtualBase();};
class Subject:public RBX::Instance,public virtual VirtualBase{};
void build(void* out,const char* name,const char* category,int Subject::*member,RBX::Reflection::PropertyDescriptor::Functionality flags){new(out) RBX::Reflection::BoundProp<int,0>(name,category,member,flags);}
