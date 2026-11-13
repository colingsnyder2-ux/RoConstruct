#include "v8datamodel/Flag.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/FlagStand.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/TimerService.h"

#include <boost/bind.hpp>

namespace RBX {

// PORT: match 2008 reflection name pointer storage.
const char* const sFlag = "Flag";

// PORT: 2008 registration requires explicit functionality flags.
static Reflection::PropDescriptor<Flag, BrickColor> prop_Color(
	"TeamColor", "Data", &Flag::getTeamColor, &Flag::setTeamColor
, RBX::Reflection::PropertyDescriptor::STANDARD);

// FUNCTION: WEBSERVICE 0x100cd0a0
// FUNCTION: ROBLOX 0x00622c40
BrickColor Flag::getTeamColor() const
{
	return teamColor;
}

// FUNCTION: WEBSERVICE 0x100cd0b0
// FUNCTION: ROBLOX 0x00622c50
bool Flag::canBePickedUpByPlayer(Network::Player* p)
{
	if (p->getNeutral()) {
		return false;
	}

	return p->getTeamColor() == getTeamColor() ? false : true;
}

// FUNCTION: WEBSERVICE 0x100cd520
// FUNCTION: ROBLOX 0x00622fc0
Flag::~Flag()
{
}

// FUNCTION: WEBSERVICE 0x100ce8a0
// FUNCTION: ROBLOX 0x006241d0
void Flag::doUglyPeriodicCloneHack()
{
	evilClone = clone();

	if (timer && numChildren() == 0) {
		timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
	}
}

// FUNCTION: WEBSERVICE 0x100ce9c0
// FUNCTION: ROBLOX 0x006242f0
void Flag::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	Instance::onServiceProvider(oldProvider, newProvider);

	if (oldProvider == NULL) {
		timer = newProvider ? newProvider->create<TimerService>() : NULL;
		timer->delay(boost::bind(&Flag::doUglyPeriodicCloneHack, shared_from(this)), 2.0);
	}

	if (newProvider == NULL) {
		flagTouched.disconnect();

		RunService* runService = oldProvider ? oldProvider->create<RunService>() : NULL;
		if (runService->getRunState() == RS_RUNNING && evilClone) {
			Flag* flag = dynamic_cast<Flag*>(evilClone.get());
			flag->getHandle();

			FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
			if (!flagStandService->FindStandWithFlag(flag)) {
				if (FlagStand* stand = flagStandService->FindClosestEmptyStandForFlag(flag)) {
					stand->AffixFlag(flag);
				}
			}
		}
	}
}

// FUNCTION: WEBSERVICE 0x100ceae0
// FUNCTION: ROBLOX 0x00624410
void Flag::onEvent_flagTouched(boost::shared_ptr<Instance> other)
{
	Instance* character = other->getParent();
	if (!Humanoid::modelIsCharacter(character)) {
		return;
	}

	Network::Player* player = Network::Players::getPlayerFromCharacter(character);
	if (!player) {
		return;
	}
	if (player->getNeutral()) {
		return;
	}
	if (player->getTeamColor() != getTeamColor()) {
		return;
	}

	FlagStandService* flagStandService = ServiceProvider::create<FlagStandService>(this);
	if (flagStandService->FindStandWithFlag(this)) {
		return;
	}

	FlagStand* stand = flagStandService->FindClosestEmptyStandForFlag(this);
	if (stand) {
		stand->AffixFlag(this);
	}
}

// FUNCTION: WEBSERVICE 0x100cebe0
// FUNCTION: ROBLOX 0x00624510
void Flag::onChildAdded(Instance* instance)
{
	if (dynamic_cast<PartInstance*>(instance)) {
		if (PartInstance* handle = getHandle()) {
			flagTouched =
				PartInstance::event_Touched.connect(handle, boost::bind(&Flag::onEvent_flagTouched, this, _1), 10);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100cee10
// FUNCTION: ROBLOX 0x00624720
Flag::Flag() : timer(NULL)
{
	setName(sFlag);
}

// FUNCTION: WEBSERVICE 0x100cef60
void Flag::setTeamColor(BrickColor color)
{
	teamColor = color;
	raisePropertyChanged(prop_Color);
}

} // namespace RBX

// PORT: 2008 reflection templates take name-pointer variable addresses.
template class RBX::FactoryProduct<RBX::Flag, RBX::Tool, &RBX::sFlag>;
template class RBX::Reflection::
	Described<RBX::Flag, &RBX::sFlag, RBX::FactoryProduct<RBX::Flag, RBX::Tool, &RBX::sFlag> >;
template class RBX::DescribedCreatable<RBX::Flag, RBX::Tool, &RBX::sFlag>;
