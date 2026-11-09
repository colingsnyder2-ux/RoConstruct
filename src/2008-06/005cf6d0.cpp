// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Hopper.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Hopper.h"

#include "util/Name.h"

namespace RBX {

// FUNCTION: WEBSERVICE 0x100c7120
bool Hopper::askAddChild(const Instance* instance) const
{
	return dynamic_cast<const BackpackItem*>(instance) != NULL;
}

// FUNCTION: WEBSERVICE 0x100c7870
Hopper::Hopper()
{
	yLocation = Rect::BOTTOM;
}

// FUNCTION: WEBSERVICE 0x100e44b0 FOLDED
bool Hopper::askSetParent(const Instance* instance) const
{
	return true;
}

const char sLegacyHopperService[] = "Hopper";

const char sStarterPackService[] = "StarterPack";

const char sHopperBin[] = "HopperBin";

const char sBackpackItem[] = "BackpackItem";

} // namespace RBX

template const RBX::Name& RBX::Name::doDeclare<RBX::sBackpackItem>();
template void RBX::Name::callDoDeclare<RBX::sBackpackItem>();
