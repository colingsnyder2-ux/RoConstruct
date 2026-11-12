// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /Ob2 /Oy /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/FlagStand.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/FlagStand.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "reflection/signal.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Primitive.h"
#include "v8world/RigidJoint.h"

#include <boost/bind.hpp>
#include <stdlib.h>
#include <vector>

namespace RBX {

const char sFlagStandService[] = "FlagStandService";

char sFlagStand[] = "FlagStand";

static Reflection::PropDescriptor<FlagStand, BrickColor> prop_Color(
	"TeamColor", "Data", &FlagStand::getTeamColor, &FlagStand::setTeamColor
);

static Reflection::SignalDesc<FlagStand, void(boost::shared_ptr<Instance>)> event_FlagCaptured(
	"FlagCaptured", "Player"
);

// FUNCTION: WEBSERVICE 0x100e7ad0
BrickColor FlagStand::getTeamColor() const
{
	return teamColor;
}

// FUNCTION: WEBSERVICE 0x100e7dd0
// FUNCTION: ROBLOX 0x00627010
Flag* FlagStand::GetFlag()
{
	Primitive* primitive = getPrimitive();

	RigidJoint* joint = primitive->getFirstRigid();
	while (joint) {
		for (int i = 0; i < 2; i++) {
			const PartInstance* part = PartInstance::fromPrimitiveConst(joint->getPrimitive(i));
			Flag* flag = dynamic_cast<Flag*>(part->getParent());
			if (flag) {
				return flag;
			}
		}

		joint = primitive->getNextRigid(joint);
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100e81d0
// FUNCTION: ROBLOX 0x00627360
void FlagStand::AffixFlag(Flag* flag)
{
	if (!HasFlag()) {
		flag->setParent(getParent());

		PartInstance* handle = flag->getHandle();

		handle->setCoordinateFrame(CoordinateFrame());

		G3D::Vector3 pos = getLocation().translation;

		pos += G3D::Vector3(0, 0.5f, 0);

		handle->moveToPoint(pos);
		handle->join();
	}
}

// FUNCTION: WEBSERVICE 0x100e8270
// FUNCTION: ROBLOX 0x00627400
FlagStand* FlagStandService::FindStandWithFlag(Flag* f)
{
	if (flagStands.size() == 0) {
		return NULL;
	}

	for (std::list<FlagStand*>::const_iterator iter = flagStands.begin(); iter != flagStands.end(); ++iter) {
		if ((*iter)->GetFlag() == f) {
			return *iter;
		}
	}

	return NULL;
}

// FUNCTION: WEBSERVICE 0x100e83d0
// FUNCTION: ROBLOX 0x00627560
FlagStandService::~FlagStandService()
{
}

// FUNCTION: WEBSERVICE 0x100e84e0
// FUNCTION: ROBLOX 0x00627670
FlagStand* FlagStandService::FindClosestEmptyStandForFlag(Flag* f)
{
	if (flagStands.empty()) {
		return NULL;
	}

	std::vector<FlagStand*> possibleLocations;

	for (std::list<FlagStand*>::const_iterator iter = flagStands.begin(); iter != flagStands.end(); ++iter) {
		if ((*iter)->getTeamColor() == f->getTeamColor() && !(*iter)->HasFlag()) {
			possibleLocations.push_back(*iter);
		}
	}

	if (possibleLocations.size() == 0) {
		return NULL;
	}

	int index = rand() % possibleLocations.size();

	return possibleLocations[index];
}

// FUNCTION: WEBSERVICE 0x100e8b90
// FUNCTION: ROBLOX 0x00627d40
FlagStand::FlagStand()
{
	setName(sFlagStand);
}

// FUNCTION: WEBSERVICE 0x100e8ea0
// FUNCTION: ROBLOX 0x00628050
FlagStandService::FlagStandService()
{
	setName(sFlagStandService);
	propArchivable.setValue(this, false);
}

// FUNCTION: WEBSERVICE 0x100e8fa0
void FlagStand::setTeamColor(BrickColor color)
{
	teamColor = color;
	raisePropertyChanged(PartInstance::prop_Color);
}

// FUNCTION: WEBSERVICE 0x100e8fc0
// FUNCTION: ROBLOX 0x00628170
void FlagStand::onEvent_standTouched(boost::shared_ptr<Instance> other)
{
	Instance* character = other->getParent();
	if (!Humanoid::modelIsCharacter(character)) {
		return;
	}

	Flag* flag = character->findFirstChildOfType<Flag>();
	if (!flag) {
		return;
	}

	Network::Player* player = Network::Players::getPlayerFromCharacter(character);
	if (!player) {
		return;
	}
	if (player->getNeutral()) {
		return;
	}

	if (player->getTeamColor() == getTeamColor() && flag->getTeamColor() != getTeamColor()) {
		event_FlagCaptured.fire(this, shared_from(player));

		FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
		FlagStand* stand = flagStandService->FindClosestEmptyStandForFlag(flag);
		if (stand) {
			stand->AffixFlag(flag);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100e9120
// FUNCTION: ROBLOX 0x006282d0
void FlagStand::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Instance::onServiceProvider(oldProvider, newProvider);

	if (oldProvider == NULL) {
		FlagStandService* flagStandService = newProvider ? newProvider->create<FlagStandService>() : NULL;
		flagStandService->RegisterFlagStand(this);

		standTouched =
			PartInstance::event_Touched.connect(this, boost::bind(&FlagStand::onEvent_standTouched, this, _1), 10);
	}

	if (newProvider == NULL) {
		FlagStandService* flagStandService = oldProvider ? oldProvider->create<FlagStandService>() : NULL;
		flagStandService->UnregisterFlagStand(this);

		standTouched.disconnect();
	}
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService>;
template class RBX::Reflection::Described<
	RBX::FlagStandService,
	RBX::sFlagStandService,
	RBX::FactoryProduct<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService> >;
template class RBX::DescribedCreatable<RBX::FlagStandService, RBX::Instance, RBX::sFlagStandService>;

template class RBX::FactoryProduct<RBX::FlagStand, RBX::PartInstance, RBX::sFlagStand>;
template class RBX::Reflection::Described<
	RBX::FlagStand,
	RBX::sFlagStand,
	RBX::FactoryProduct<RBX::FlagStand, RBX::PartInstance, RBX::sFlagStand> >;
template class RBX::DescribedCreatable<RBX::FlagStand, RBX::PartInstance, RBX::sFlagStand>;
