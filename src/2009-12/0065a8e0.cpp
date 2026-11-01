// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Accoutrement.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Accoutrement.h"

#include "reflection/property.h"

namespace RBX {

const char sHat[] = "Hat";

const char sAccoutrement[] = "Accoutrement";

static Reflection::PropDescriptor<Accoutrement, int> prop_BackendAccoutrementState(
	"BackendAccoutrementState",
	"Appearance",
	&RBX::Accoutrement::getBackendAccoutrementState,
	&RBX::Accoutrement::setBackendAccoutrementState,
	Reflection::PropertyDescriptor::STREAMING
);

// FUNCTION: WEBSERVICE 0x100dcfb0
void Accoutrement::setBackendAccoutrementState(int value)
{
	if (value != backendAccoutrementState) {
		backendAccoutrementState = value;
		raisePropertyChanged(prop_BackendAccoutrementState);
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Accoutrement, RBX::Instance, RBX::sAccoutrement>;
template class RBX::Reflection::Described<
	RBX::Accoutrement,
	RBX::sAccoutrement,
	RBX::FactoryProduct<RBX::Accoutrement, RBX::Instance, RBX::sAccoutrement> >;
template class RBX::DescribedCreatable<RBX::Accoutrement, RBX::Instance, RBX::sAccoutrement>;

template class RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, RBX::sHat>;
template class RBX::Reflection::
	Described<RBX::Hat, RBX::sHat, RBX::FactoryProduct<RBX::Hat, RBX::Accoutrement, RBX::sHat> >;
template class RBX::DescribedCreatable<RBX::Hat, RBX::Accoutrement, RBX::sHat>;
