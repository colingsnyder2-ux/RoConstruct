// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/SpawnLocation.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/SpawnLocation.h"

#include "reflection/property.h"

namespace RBX {

const char sSpawnerService[] = "SpawnerService";

char sSpawnLocation[] = "SpawnLocation";

static Reflection::PropDescriptor<SpawnLocation, BrickColor> prop_TeamColor(
	"TeamColor",
	"Teams",
	&RBX::SpawnLocation::getTeamColor,
	&RBX::SpawnLocation::setTeamColor
);

// FUNCTION: WEBSERVICE 0x100ff2b0
void SpawnLocation::setTeamColor(BrickColor color)
{
	teamColor = color;
	raisePropertyChanged(prop_TeamColor);
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>;
template class RBX::Reflection::Described<
	RBX::SpawnerService,
	RBX::sSpawnerService,
	RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService> >;
template class RBX::DescribedCreatable<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>;
