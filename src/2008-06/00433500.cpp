// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_browsernativerank2bfe991969ba303c.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias(<xstring>, <roc_espeon_browserimportedcstr3da8e64d105bf835.cpp>)
#include <reflection/object.h>
#include <reflection/enumconverter.h>
#include <reflection/signal.h>
#include <reflection/property.h>
#include <reflection/function.h>
#include <string.h>
using namespace RBX::Reflection;
static __declspec(noinline) int classifyDescriptor(const Descriptor* descriptor) {
 if(dynamic_cast<const EnumDescriptor::Item*>(descriptor)) return 5;
 if(dynamic_cast<const EnumDescriptor*>(descriptor)) return 4;
 if(dynamic_cast<const SignalDescriptor*>(descriptor)) return 3;
 if(dynamic_cast<const PropertyDescriptor*>(descriptor)) return 2;
 if(dynamic_cast<const FunctionDescriptor*>(descriptor)) return 1;
 return dynamic_cast<const ClassDescriptor*>(descriptor)?0:100;
}
int __stdcall compareDescriptors(const Descriptor* first,const Descriptor* second,long) {
 int a=classifyDescriptor(first); int b=classifyDescriptor(second);
 if(a!=b) return a-b;
 return strcmp(first->name.toString().c_str(),second->name.toString().c_str());
}
