// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/FlagStand.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/FlagStand.h"

#include "v8datamodel/PartInstance.h"

namespace RBX {

const char sFlagStandService[] = "FlagStandService";

char sFlagStand[] = "FlagStand";

// FUNCTION: WEBSERVICE 0x100e8fa0
void FlagStand::setTeamColor(BrickColor color)
{
	teamColor = color;
	raisePropertyChanged(PartInstance::prop_Color);
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService>;
template class RBX::Reflection::Described<
	RBX::FlagStandService,
	RBX::sFlagStandService,
	RBX::FactoryProduct<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService> >;
template class RBX::DescribedCreatable<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService>;
