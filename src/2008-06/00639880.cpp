// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8datamodel/DebrisService.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/DebrisService.h"

namespace RBX {

char sDebrisService[] = "Debris";

} // namespace RBX

template class RBX::FactoryProduct<RBX::DebrisService, RBX::Instance, RBX::sDebrisService>;
template class RBX::Reflection::Described<
	RBX::DebrisService,
	RBX::sDebrisService,
	RBX::FactoryProduct<RBX::DebrisService, RBX::Instance, RBX::sDebrisService> >;
template class RBX::DescribedCreatable<RBX::DebrisService, RBX::Instance, RBX::sDebrisService>;
