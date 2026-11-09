// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_player_loadcharacter_genuine_c6a41e4db096fd36.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#define private public
#include "Client.h"
#include "Player.h"
#include "security/SecurityContext.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/CharacterAppearance.h"
#include "v8datamodel/Accoutrement.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8world/World.h"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#undef private

static void addChild(const boost::shared_ptr<RBX::ModelInstance>& parent, const boost::shared_ptr<RBX::Instance>& child)
{
	child->setParent(parent.get());
}

namespace RBX { namespace Network {
void Player::loadCharacter()
{
	Workspace* workspace = ServiceProvider::find<Workspace>(this);
	if (!workspace)
		throw std::runtime_error("LoadCharacter can only be called when Player is in the world");

	if (!Players::backendProcessing(this, true))
		throw std::runtime_error("LoadCharacter can only be called by the backend server");

	std::vector<boost::shared_ptr<Instance>> instances;
	ContentProvider::singleton().load(ContentId::fromAssets("fonts\\character.rbxm"), instances);

	if (instances.size() != 1)
		throw std::runtime_error("character.rbxm should contain a Character model");

	boost::shared_ptr<ModelInstance> model = boost::shared_dynamic_cast<ModelInstance>(instances.front());
	if (!model)
		throw std::runtime_error("character.rbxm should contain a Character model");

	Humanoid* humanoid = Humanoid::modelIsCharacter(model.get());
	if (!humanoid)
		throw std::runtime_error("character.rbxm should contain a humanoid");

	{
		std::vector<boost::shared_ptr<Instance>> extraSound;
		ContentProvider::singleton().load(ContentId::fromAssets("fonts\\humanoidSound.rbxm"), extraSound);
		std::for_each(extraSound.begin(), extraSound.end(), boost::bind(&addChild, model, _1));
	}

	{
		std::vector<boost::shared_ptr<Instance>> extraHealth;
		ContentProvider::singleton().load(ContentId::fromAssets("fonts\\humanoidHealth.rbxm"), extraHealth);
		std::for_each(extraHealth.begin(), extraHealth.end(), boost::bind(&addChild, model, _1));
	}

	{
		std::vector<boost::shared_ptr<Instance>> extraAnimate;
		ContentProvider::singleton().load(ContentId::fromAssets("fonts\\humanoidAnimate.rbxm"), extraAnimate);
		std::for_each(extraAnimate.begin(), extraAnimate.end(), boost::bind(&addChild, model, _1));
	}

	model->setName(getName());
	humanoid->buildJoints();
	Instance::propArchivable.setValue(model.get(), false);
	setCharacter(model.get());
	model->setParent(workspace);
	loadCharacterAppearance();
	SpawnerService* spawnerService = ServiceProvider::find<SpawnerService>(this);
	G3D::Vector3 dropPoint = spawnerService ? spawnerService->FindSpawnPositionForPlayer(this) : G3D::Vector3(0.0f, 20.0f, 25.0f);
	workspace->moveToPoint(model.get(), dropPoint);
}
}}
