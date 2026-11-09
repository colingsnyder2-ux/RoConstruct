// from server: 68% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Teams.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Teams.h"

namespace RBX {

const char sTeams[] = "Teams";

// STUB: WEBSERVICE 0x100dad30
G3D::Color3 Teams::getTeamColorForHumanoid(Humanoid* humanoid)
{
	STUB(0x100dad30);

	return G3D::Color3();
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>;
template class RBX::Reflection::
	Described<RBX::Teams, RBX::sTeams, RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams> >;
template class RBX::DescribedCreatable<RBX::Teams, RBX::Instance, RBX::sTeams>;
