// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/ForceField.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/ForceField.h"

namespace RBX {

char sForceField[] = "ForceField";

} // namespace RBX

template class RBX::FactoryProduct<RBX::ForceField, RBX::Instance, RBX::sForceField>;
template class RBX::Reflection::Described<
	RBX::ForceField,
	RBX::sForceField,
	RBX::FactoryProduct<RBX::ForceField, RBX::Instance, RBX::sForceField> >;
template class RBX::DescribedCreatable<RBX::ForceField, RBX::Instance, RBX::sForceField>;
