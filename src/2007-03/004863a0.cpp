// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Flag.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Flag.h"

#include "reflection/property.h"

namespace RBX {

const char sFlag[] = "Flag";

static Reflection::PropDescriptor<Flag, BrickColor> prop_Color(
	"TeamColor",
	"Data",
	&RBX::Flag::getTeamColor,
	&RBX::Flag::setTeamColor
);

// FUNCTION: WEBSERVICE 0x100cef60
void Flag::setTeamColor(BrickColor color)
{
	teamColor = color;
	raisePropertyChanged(prop_Color);
}

} // namespace RBX
