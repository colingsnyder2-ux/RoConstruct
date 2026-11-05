// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_player_loadappearance_genuine_d68f705aae6a1ff2.cpp

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

static void setAppearanceParent(boost::shared_ptr<RBX::Instance> parent, boost::shared_ptr<RBX::Instance> instance)
{
	if (dynamic_cast<RBX::CharacterAppearance*>(instance.get()))
		instance->setParent(parent.get());
	else if (dynamic_cast<RBX::Accoutrement*>(instance.get()))
		instance->setParent(parent.get());
	else
		throw std::runtime_error("Attempt to add a non-CharacterAppearance/Accoutrement object to a character");
}

namespace RBX { namespace Network {
void Player::loadCharacterAppearance()
{
	if (!Players::backendProcessing(this, true))
		throw std::runtime_error("LoadCharacterAppearance can only be called by the backend server");

	removeCharacterAppearance();

	if (character && !characterAppearance.empty())
	{
		std::vector<boost::shared_ptr<Instance>> characterApperance;
		{
			std::vector<std::string> strings;
			boost::algorithm::split(strings, this->characterAppearance, boost::algorithm::is_any_of(";"));
			for (size_t i = 0; i < strings.size(); i++)
				ContentProvider::singleton().load(ContentId(strings[i]), characterApperance);
		}
		std::for_each(characterApperance.begin(), characterApperance.end(), boost::bind(&setAppearanceParent, character, _1));
		if (Workspace* workspace = ServiceProvider::find<Workspace>(this))
			workspace->getWorld()->update();
	}
}
}}
