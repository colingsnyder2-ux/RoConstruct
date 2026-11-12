// from server: 68% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client Network/Player.cpp

// Candidate translation unit (score above; library headers required).
#include "network/Player.h"

#include "humanoid/Humanoid.h"
#include "network/Players.h"
#include "reflection/property.h"
#include "security/SecurityContext.h"
#include "util/ContentProvider.h"
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/CharacterAppearance.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"

#include <G3D/System.h>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/bind.hpp>
#include <stdexcept>

namespace RBX {
namespace Network {

char sPlayer[] = "Player";

static Reflection::BoundFuncDesc<Player, void(), 0> loadCharacterFunction(
	&Player::loadCharacter, "LoadCharacter", Reflection::FunctionDescriptor::NeedTrustedCaller
);

static Reflection::BoundFuncDesc<Player, void(), 0> removeCharacterFunction(
	&Player::removeCharacter, "RemoveCharacter", Reflection::FunctionDescriptor::NeedTrustedCaller
);

static Reflection::BoundFuncDesc<Player, void(bool), 1> func_SetUnder13(
	&Player::setUnder13, "SetUnder13", "value", Reflection::FunctionDescriptor::NeedTrustedCaller
);

static Reflection::BoundFuncDesc<Player, void(bool), 1> func_SetSuperSafeChat(
	&Player::setSuperSafeChat, "SetSuperSafeChat", "value", Reflection::FunctionDescriptor::NeedTrustedCaller
);

static Reflection::RefPropDescriptor<Player, ModelInstance> prop_Character(
	"Character", "Data", &Player::getCharacter, &Player::setCharacter
);

static Reflection::PropDescriptor<Player, std::string> prop_characterAppearance(
	"CharacterAppearance", "Data", &Player::getCharacterAppearance, &Player::setCharacterAppearance
);

Reflection::BoundProp<int, 1> Player::prop_userId("userId", "Data", &Player::userId);
Reflection::BoundProp<bool, 1> Player::prop_Under13(
	"Under13", "Data", &Player::under13, Reflection::PropertyDescriptor::STREAMING
);

Reflection::BoundProp<bool, 1> Player::prop_SuperSafeChat(
	"SuperSafeChat", "Data", &Player::superSafeChat, Reflection::PropertyDescriptor::STREAMING
);

Reflection::SignalDesc<Player, void(std::string, boost::shared_ptr<Instance>)> Player::event_Chatted(
	"Chatted", "message", "recipient"
);

static Reflection::PropDescriptor<Player, BrickColor> prop_teamColor(
	"TeamColor", "Team", &Player::getTeamColor, &Player::setTeamColor
);

static Reflection::PropDescriptor<Player, bool> prop_neutral(
	"Neutral", "Team", &Player::getNeutral, &Player::setNeutral
);

static Reflection::SignalDesc<Player, void(float)> event_Idled("Idled", "time");

// FUNCTION: WEBSERVICE 0x1018c3b0
// FUNCTION: ROBLOX 0x004a4da0
std::string Player::getCharacterAppearance() const
{
	return characterAppearance;
}

// FUNCTION: WEBSERVICE 0x1018c3e0
// FUNCTION: ROBLOX 0x004a4ea0
static void setAppearanceParentNull(Instance* instance)
{
	if (dynamic_cast<CharacterAppearance*>(instance)) {
		instance->setParent(NULL);
	}
}

// FUNCTION: WEBSERVICE 0x1018c520
// FUNCTION: ROBLOX 0x004a5a50
static void addChild(const boost::shared_ptr<ModelInstance>& parent, const boost::shared_ptr<Instance>& child)
{
	child->setParent(parent.get());
}

// FUNCTION: WEBSERVICE 0x1018c540
// FUNCTION: ROBLOX 0x004a5a70
static void setAppearanceParent(boost::shared_ptr<Instance> parent, boost::shared_ptr<Instance> instance)
{
	if (dynamic_cast<CharacterAppearance*>(instance.get())) {
		instance->setParent(parent.get());
	}
	else if (dynamic_cast<Accoutrement*>(instance.get())) {
		instance->setParent(parent.get());
	}
	else {
		throw std::runtime_error("Attempt to add a non-CharacterAppearance/Accoutrement object to a character");
	}
}

// FUNCTION: WEBSERVICE 0x1018cec0
void Player::setUnder13(bool value)
{
	prop_Under13.setValue(this, value);
}

// FUNCTION: WEBSERVICE 0x1018cef0
void Player::setSuperSafeChat(bool value)
{
	prop_SuperSafeChat.setValue(this, value);
}

// FUNCTION: WEBSERVICE 0x1018cf20
// FUNCTION: ROBLOX 0x004a6a90
void Player::removeCharacterAppearance()
{
	if (!Players::backendProcessing(this, true)) {
		throw std::runtime_error("RemoveCharacterAppearance can only be called by the backend server");
	}

	if (character) {
		character->for_eachChild(setAppearanceParentNull);
	}
}

// FUNCTION: WEBSERVICE 0x1018cfb0
// FUNCTION: ROBLOX 0x004a6b20
Backpack* Player::getPlayerBackpack() const
{
	return findFirstChildOfType<Backpack>();
}

// FUNCTION: ROBLOX 0x004ac2b0
void Player::onLocalPlayerNotIdle(ServiceProvider* serviceProvider)
{
	Players* players = serviceProvider->find<Players>();
	if (players) {
		Player* player = players->getLocalPlayer();
		if (player && ServiceProvider::findServiceProvider(player)) {
			player->lastActivityTime = G3D::System::getLocalTime();
		}
	}
}

// FUNCTION: WEBSERVICE 0x1018eae0
// FUNCTION: ROBLOX 0x004ac2f0
void Player::onCharacterChangedFrontend()
{
	if (this == Players::findLocalPlayer(this)) {
		Workspace* workspace = ServiceProvider::find<Workspace>(this);

		if (!character) {
			workspace->getCamera()->setCameraType(Camera::FIXED_CAMERA);
			workspace->getCamera()->setDistanceFromTarget(0.0f);
			workspace->getCamera()->zoom(-1.0f);
		}
		else {
			workspace->getCamera()->setCameraSubject(Humanoid::modelIsCharacter(character.get()));
			workspace->getCamera()->setCameraType(Camera::CUSTOM_CAMERA);
			workspace->getCamera()->setDistanceFromTarget(13.0f);
			workspace->getCamera()->zoom(-1.0f);
			workspace->setDefaultMouseCommand();
		}
	}
}

// FUNCTION: WEBSERVICE 0x1018ebc0
// FUNCTION: ROBLOX 0x004ac3d0
void Player::rebuildBackpack()
{
	if (!Players::backendProcessing(this, true)) {
		throw std::runtime_error("rebuildBackpack can only be called by the backend server");
	}

	while (Backpack* oldBackpack = findFirstChildOfType<Backpack>()) {
		oldBackpack->setParent(NULL);
	}

	boost::shared_ptr<Instance> backpack = Creatable<Instance>::create<Backpack>();
	backpack->setParent(this);

	if (StarterPackService* starterPack = ServiceProvider::find<StarterPackService>(this)) {
		for (unsigned int i = 0; i < starterPack->numChildren(); ++i) {
			Instance* child = starterPack->getChild(i);
			boost::shared_ptr<Instance> copy = child->clone();
			copy->setParent(backpack.get());
		}
	}
}

// FUNCTION: WEBSERVICE 0x1018f870
// FUNCTION: ROBLOX 0x004ada20
void Player::setCharacter(ModelInstance* value)
{
	if (value != character.get()) {
		if (character) {
			characterDiedConnection.disconnect();
			Notifier<Player, CharacterRemoving>::raise(CharacterRemoving(character.get()));
			if (Players::backendProcessing(this, false)) {
				character->setParent(NULL);
			}
			character.reset();
		}

		if (value) {
			character = shared_from(value);
			Notifier<Player, CharacterAdded>::raise(CharacterAdded(character.get()));
			if (Players::frontendProcessing(this, false)) {
				onCharacterChangedFrontend();
			}
		}

		raisePropertyChanged(prop_Character);
	}
}

// FUNCTION: WEBSERVICE 0x1018f9c0
// FUNCTION: ROBLOX 0x004adb70
void Player::setTeamColor(BrickColor value)
{
	if (value.number != teamColor.number) {
		teamColor = value;
		raisePropertyChanged(prop_teamColor);
	}
}

// FUNCTION: WEBSERVICE 0x1018f9f0
// FUNCTION: ROBLOX 0x004adba0
void Player::setNeutral(bool value)
{
	if (value != neutral) {
		neutral = value;
		raisePropertyChanged(prop_neutral);
	}
}

// FUNCTION: WEBSERVICE 0x1018fa20
// FUNCTION: ROBLOX 0x004adbd0
void Player::doPeriodicIdleCheck()
{
	if (!ServiceProvider::findServiceProvider(this)) {
		return;
	}

	if (lastActivityTime != 0.0) {
		double idleTime = G3D::System::getLocalTime() - lastActivityTime;

		if (idleTime > 120.0) {
			Players* players = ServiceProvider::find<Players>(this);

			if (players && players->getLocalPlayer() && Players::clientIsPresent(this, true)) {
				event_Idled.fire(this, idleTime);
			}
		}
	}

	TimerService* timer = ServiceProvider::create<TimerService>(this);

	if (timer) {
		timer->delay(boost::bind(&Player::doPeriodicIdleCheck, shared_from(this)), 30.0);
	}
}

// FUNCTION: WEBSERVICE 0x1018fb20
// FUNCTION: ROBLOX 0x004adcd0
void Player::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
	if (oldProvider && Players::backendProcessing(oldProvider, true)) {
		setCharacter(NULL);
	}

	Instance::onServiceProvider(oldProvider, newProvider);

	if (newProvider && Players::frontendProcessing(newProvider, true)) {
		onCharacterChangedFrontend();
	}

	if (!oldProvider && Players::frontendProcessing(newProvider, true)) {
		lastActivityTime = G3D::System::getLocalTime();
		doPeriodicIdleCheck();
	}
}

// FUNCTION: WEBSERVICE 0x1018fba0
// FUNCTION: ROBLOX 0x004add50
void Player::removeCharacter()
{
	if (!Players::backendProcessing(this, true)) {
		throw std::runtime_error("RemoveCharacter can only be called by the backend server");
	}

	setCharacter(NULL);
}

// FUNCTION: WEBSERVICE 0x1018fce0
// FUNCTION: ROBLOX 0x004ae180
Player::~Player()
{
	setCharacter(NULL);
}

// FUNCTION: WEBSERVICE 0x1018fef0
// FUNCTION: ROBLOX 0x004ae390
void Player::setName(const std::string& value)
{
	Security::Context::current().requirePermission(Security::Administrator, "set a Player's name");
	Instance::setName(value);
}

// FUNCTION: WEBSERVICE 0x1018ffd0
// FUNCTION: ROBLOX 0x004ae6a0
Player::Player()
	: teamColor(BrickColor::legoWhite()), neutral(true), under13(false), superSafeChat(false), userId(0),
	  lastActivityTime(0.0)
{
	Security::Context::current().requirePermission(Security::Administrator, "create a Player");
	setName(sPlayer);
}

// FUNCTION: WEBSERVICE 0x10190340
// FUNCTION: ROBLOX 0x004af070
void Player::loadCharacterAppearance()
{
	if (!Players::backendProcessing(this, true)) {
		throw std::runtime_error("LoadCharacterAppearance can only be called by the backend server");
	}

	removeCharacterAppearance();

	if (character && !characterAppearance.empty()) {
		std::vector<boost::shared_ptr<Instance> > characterApperance;

		{
			std::vector<std::string> strings;
			boost::algorithm::split(strings, characterAppearance, boost::algorithm::is_any_of(";"));

			for (unsigned int i = 0; i < strings.size(); ++i) {
				ContentProvider::singleton().load(ContentId(strings[i]), characterApperance);
			}
		}

		std::for_each(
			characterApperance.begin(), characterApperance.end(), boost::bind(&setAppearanceParent, character, _1)
		);

		Workspace* workspace = ServiceProvider::find<Workspace>(this);

		if (workspace) {
			workspace->getWorld()->update();
		}
	}
}

// FUNCTION: WEBSERVICE 0x101905d0
// FUNCTION: ROBLOX 0x004af300
void Player::loadCharacter()
{
	Workspace* workspace = ServiceProvider::find<Workspace>(this);
	if (!workspace) {
		throw std::runtime_error("LoadCharacter can only be called when Player is in the world");
	}

	if (!Players::backendProcessing(this, true)) {
		throw std::runtime_error("LoadCharacter can only be called by the backend server");
	}

	std::vector<boost::shared_ptr<Instance> > instances;
	ContentProvider::singleton().load(ContentId::fromAssets("fonts\\character.rbxm"), instances);

	if (instances.size() != 1) {
		throw std::runtime_error("character.rbxm should contain a Character model");
	}

	boost::shared_ptr<ModelInstance> model = boost::shared_dynamic_cast<ModelInstance>(instances.front());
	if (!model) {
		throw std::runtime_error("character.rbxm should contain a Character model");
	}

	Humanoid* humanoid = Humanoid::modelIsCharacter(model.get());
	if (!humanoid) {
		throw std::runtime_error("character.rbxm should contain a humanoid");
	}

	{
		std::vector<boost::shared_ptr<Instance> > extraSound;
		ContentProvider::singleton().load(ContentId::fromAssets("fonts\\humanoidSound.rbxm"), extraSound);
		std::for_each(extraSound.begin(), extraSound.end(), boost::bind(&addChild, model, _1));
	}

	{
		std::vector<boost::shared_ptr<Instance> > extraHealth;
		ContentProvider::singleton().load(ContentId::fromAssets("fonts\\humanoidHealth.rbxm"), extraHealth);
		std::for_each(extraHealth.begin(), extraHealth.end(), boost::bind(&addChild, model, _1));
	}

	{
		std::vector<boost::shared_ptr<Instance> > extraAnimate;
		ContentProvider::singleton().load(ContentId::fromAssets("fonts\\humanoidAnimate.rbxm"), extraAnimate);
		std::for_each(extraAnimate.begin(), extraAnimate.end(), boost::bind(&addChild, model, _1));
	}

	model->setName(getName());

	humanoid->buildJoints();

	Instance::propArchivable.setValue(model.get(), false);

	setCharacter(model.get());

	model->setParent(workspace);

	loadCharacterAppearance();

	if (SpawnerService* spawner = ServiceProvider::find<SpawnerService>(this)) {
		spawner->SpawnPlayer(model, this);
	}
	else {
		workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 20.0f, 25.0f));
	}
}

// FUNCTION: WEBSERVICE 0x10190bf0
// FUNCTION: ROBLOX 0x004af920
void Player::setCharacterAppearance(const std::string& value)
{
	if (value != characterAppearance) {
		characterAppearance = value;

		if (Players::backendProcessing(this, false)) {
			loadCharacterAppearance();
		}

		raisePropertyChanged(prop_characterAppearance);
	}
}

} // namespace Network
} // namespace RBX

template class RBX::Reflection::Described<
	RBX::Network::Player,
	RBX::Network::sPlayer,
	RBX::FactoryProduct<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer> >;
template class RBX::DescribedCreatable<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer>;

template const RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>::Creator
	RBX::FactoryProduct<RBX::HopperBin, RBX::BackpackItem, RBX::sHopperBin>::creator;

template const RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>::Creator
	RBX::FactoryProduct<RBX::StarterPackService, RBX::Hopper, RBX::sStarterPackService>::creator;

template const RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>::Creator
	RBX::FactoryProduct<RBX::LegacyHopperService, RBX::Hopper, RBX::sLegacyHopperService>::creator;

template const RBX::FactoryProduct<RBX::Backpack, RBX::Hopper, RBX::sBackpack>::Creator
	RBX::FactoryProduct<RBX::Backpack, RBX::Hopper, RBX::sBackpack>::creator;

template const RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>::Creator
	RBX::FactoryProduct<RBX::SpawnLocation, RBX::PartInstance, RBX::sSpawnLocation>::creator;

template const RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>::Creator
	RBX::FactoryProduct<RBX::SpawnerService, RBX::Instance, RBX::sSpawnerService>::creator;

template const RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>::Creator
	RBX::FactoryProduct<RBX::ShirtGraphic, RBX::CharacterAppearance, RBX::sShirtGraphic>::creator;

template const RBX::FactoryProduct<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt>::Creator
	RBX::FactoryProduct<RBX::Shirt, RBX::ShirtGraphic, RBX::sShirt>::creator;

template const RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>::Creator
	RBX::FactoryProduct<RBX::BodyColors, RBX::CharacterAppearance, RBX::sBodyColors>::creator;

template const RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>::Creator
	RBX::FactoryProduct<RBX::Skin, RBX::CharacterAppearance, RBX::sSkin>::creator;

template const RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>::Creator
	RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>::creator;

template const RBX::FactoryProduct<RBX::TimerService, RBX::Instance, RBX::sTimerService>::Creator
	RBX::FactoryProduct<RBX::TimerService, RBX::Instance, RBX::sTimerService>::creator;

template const RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>::Creator
	RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>::creator;
