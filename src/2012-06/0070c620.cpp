// roc-cl: 30729
// roc-lang: cpp
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_unit_97da6effdad7f4e6.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"
#include "reflection/reflection.h"
typedef void (RBX::Instance::*Setter)(const std::string&);
std::auto_ptr<RBX::Reflection::TypedPropertyDescriptor<std::string>::GetSet> (__cdecl *factory)(int, Setter) = &RBX::Reflection::PropDescriptor<RBX::Instance, std::string>::getset<Setter>;
