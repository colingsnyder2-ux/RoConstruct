// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_7b0de2a235279c1c.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"
#include "reflection/reflection.h"
typedef void (RBX::Instance::*Setter)(const std::string&);
std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<std::string>::GetSet> (__cdecl *factory)(int, Setter) = &RBX::Reflection::PropDescriptor<RBX::Instance, std::string>::getset<Setter>;

template RBX::Reflection::PropDescriptor<RBX::Instance, std::string>::PropDescriptor(const char*, const char*, int, Setter, RBX::Reflection::PropertyDescriptor::Functionality);
