// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::Network::Player character/backpack methods (inactive; Network/Player.cpp unit). Not in any
// build list. Layout and the other Player rows: native-headers/Network/Player.h, native-classes/NetworkPlayer.cpp and
// AppUnit480_2008Player*.cpp. Player::getTeamColor 00445260 is the Network/Player.h in-class inline (ICF), not here.
//
// Evidence (2008-06 Roblox.exe):
// - rebuildBackpack 004925c0: Players::backendProcessing 00495eb0 (this, true), else std::runtime_error 00409d50
//   with the literal 00821cac "rebuildBackpack can only be called by the backend server"; Instance::
//   findFirstChildOfType<Backpack> 0048bb80 out of line, setParent 0055a8f0 (NULL); Creatable<Instance>::
//   create<Backpack> 0048bc20 copied into a shared_ptr<Instance>; setParent(this); ServiceProvider::
//   find<StarterPackService>(const Instance*) 00491ef0 (tail jump to find<StarterPackService>() const 00490d70;
//   create<StarterPackService>() const 004b3960 calls 00490d70 first); Instance::numChildren 0048ae20 (out of line) and the
//   children vector (+0x108, checked operator[]); Instance::clone 00559350; setParent(backpack).
#include "Network/Player.h"
#include "Network/Players.h"
#include "v8tree/Service.h"
#include "v8datamodel/Backpack.h"
#include "v8datamodel/Hopper.h"
#include <stdexcept>

namespace RBX
{
	namespace Network
	{
		// 004925c0
		void Player::rebuildBackpack()
		{
			if (!Players::backendProcessing(this, true))
				throw std::runtime_error("rebuildBackpack can only be called by the backend server");

			while (Backpack* r = findFirstChildOfType<Backpack>())
			{
				r->setParent(NULL);
			}

			boost::shared_ptr<Instance> backpack = Creatable<Instance>::create<Backpack>();
			backpack->setParent(this);

			if (StarterPackService* starterPack = ServiceProvider::find<StarterPackService>(this))
			{
				for (size_t i = 0; i < starterPack->numChildren(); i++)
				{
					boost::shared_ptr<Instance> copy = starterPack->getChild(i)->clone();
					copy->setParent(backpack.get());
				}
			}
		}

		// 004957a0 loadCharacter(bool inGame): PARKED (header proposals; not compiled).
		// Evidence: ServiceProvider::find<Workspace>(this) 00491e50, else runtime_error 008223f4; backendProcessing
		// (this, true), else 008223bc; ContentId::fromAssets(const char*) 0055bd80 "fonts\\character.rbxm" 008223a4,
		// ServiceProvider::create<ContentProvider>(this) 00465210, ContentProvider::load 005628e0; size != 1 and a
		// failed shared_dynamic_cast<ModelInstance> 0048b150 of front() 0048b970 both throw 00822374;
		// Humanoid::modelIsCharacter 005d9a20 else 00822348; then "fonts\\humanoidSound.rbxm" 0082232c,
		// "fonts\\humanoidHealth.rbxm" 00822310 and "fonts\\humanoidAnimate.rbxm" 008222f4, each loaded into its own
		// vector and std::for_each 0048d370 with boost::bind(&addChild 0048a670, model, _1) 0048cc00. Then
		// model->setName(getName()) through Instance vtable slot 1, `if (inGame) humanoid->buildJoints()` 005d9340,
		// Instance::propArchivable (00973e8c GetSet slot 3) set false, setCharacter 004944b0, model->setParent(workspace),
		// loadCharacterAppearance(!inGame) 00495380, then find<SpawnerService>(this) 00491ea0: when found it calls the
		// SpawnerService spawn routine 005d2b80 (thiscall: shared_ptr<ModelInstance> copy, Player*) and skips the drop;
		// otherwise RootInstance::moveToPoint 005909e0 (model, Vector3(0, 20 [008222f0], 25 [008222ec])).
		// Blocked: v8datamodel/SpawnerService.h does not declare 005d2b80, and humanoid/Humanoid2008.h does not
		// declare buildJoints 005d9340 (the donor humanoid/Humanoid.h does).
#if 0
		void Player::loadCharacter(bool inGame)
		{
			Workspace* workspace = ServiceProvider::find<Workspace>(this);
			if (!workspace)
				throw std::runtime_error("LoadCharacter can only be called when Player is in the world");

			if (!Players::backendProcessing(this, true))
				throw std::runtime_error("LoadCharacter can only be called by the backend server");

			std::vector<boost::shared_ptr<Instance> > instances;
			ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\character.rbxm"), instances);

			if (instances.size() != 1)
				throw std::runtime_error("character.rbxm should contain a Character model");

			boost::shared_ptr<ModelInstance> model = boost::shared_dynamic_cast<ModelInstance>(instances.front());
			if (!model)
				throw std::runtime_error("character.rbxm should contain a Character model");

			Humanoid* humanoid = Humanoid::modelIsCharacter(model.get());
			if (!humanoid)
				throw std::runtime_error("character.rbxm should contain a humanoid");

			{
				std::vector<boost::shared_ptr<Instance> > extraSound;
				ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\humanoidSound.rbxm"), extraSound);
				std::for_each(extraSound.begin(), extraSound.end(), boost::bind(&addChild, model, _1));
			}
			{
				std::vector<boost::shared_ptr<Instance> > extraHealth;
				ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\humanoidHealth.rbxm"), extraHealth);
				std::for_each(extraHealth.begin(), extraHealth.end(), boost::bind(&addChild, model, _1));
			}
			{
				std::vector<boost::shared_ptr<Instance> > extraAnimate;
				ServiceProvider::create<ContentProvider>(this)->load(ContentId::fromAssets("fonts\\humanoidAnimate.rbxm"), extraAnimate);
				std::for_each(extraAnimate.begin(), extraAnimate.end(), boost::bind(&addChild, model, _1));
			}

			model->setName(getName());
			if (inGame)
				humanoid->buildJoints();
			Instance::propArchivable.setValue(model.get(), false);
			setCharacter(model.get());
			model->setParent(workspace);
			loadCharacterAppearance(!inGame);

			if (SpawnerService* spawnerService = ServiceProvider::find<SpawnerService>(this))
				spawnerService->spawnPlayer(model, this);   // 005d2b80 (analog name, pending declaration)
			else
				workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 20.0f, 25.0f));
		}
#endif

		// 00495380 loadCharacterAppearance(bool blocking): PARKED (not compiled; 1041 bytes).
		// Evidence: backendProcessing(this, true) else runtime_error 008222a8; removeCharacterAppearance 0048c3e0 (not
		// declared in Network/Player.h; backendProcessing else 008216d0, then character->for_eachChild(
		// &setAppearanceParentNull 004899b0) 0045c470); `character (+0x170) && !characterAppearance.empty() (+0x1a8)`;
		// an outer vector<string> split on ";" 008212ac (is_any_of 0048e620, split 004952f0). With the argument set:
		// the donor block (its own vector<shared_ptr<Instance>> and an inner re-split vector<string>, per string
		// ContentId(const std::string&) 00615440 + create<ContentProvider>(this) 00465210 ->load 005628e0), then
		// std::for_each 0048d0f0 with boost::bind(&setAppearanceParent 0048a690, character, _1) 0048cc00 and
		// ~vector 005a2fe0. Without it: per outer string an asynchronous ContentProvider request 00562f70 whose
		// boost::function 00493210 binds the file-local callback 00492360 (bind 0048d200) to the character and a
		// shared_from<> 00618a40 of an object built by 004651c0 (this, _1, _2). Needs the
		// removeCharacterAppearance declaration and identities for 00492360 / 004651c0 / 00562f70 first.
	}
}
