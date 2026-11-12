// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: openrbx-client-dll App/v8datamodel/Teams.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Teams.h"

#include "humanoid/Humanoid.h"
#include "network/Player.h"
#include "network/Players.h"
#include "reflection/reflection.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/Team.h"

#include <algorithm>

namespace RBX {

const char sTeams[] = "Teams";

static Reflection::BoundFuncDesc<Teams, void(), 0> teams_rebalanceTeamsFunction(
	&Teams::rebalanceTeams, "RebalanceTeams", Reflection::FunctionDescriptor::AnyCaller
);

static Reflection::BoundFuncDesc<Teams, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(), 0>
	func_teams(&Teams::getTeams, "GetTeams", Reflection::FunctionDescriptor::AnyCaller);

// FUNCTION: WEBSERVICE 0x100da970
// FUNCTION: ROBLOX 0x005e7730
Teams::~Teams()
{
}

// FUNCTION: WEBSERVICE 0x100daac0
// FUNCTION: ROBLOX 0x005e7880
Team* Teams::getTeamFromTeamColor(BrickColor c)
{
	for (unsigned int i = 0; i < numChildren(); i++) {
		if (Team* team = dynamic_cast<Team*>(getChild(i))) {
			if (team->getTeamColor() == c) {
				return team;
			}
		}
	}

	return NULL;
}

// FUNCTION: ROBLOX 0x005e7910
Team* Teams::getTeamFromPlayer(Network::Player* p)
{
	if (p->getNeutral()) {
		return NULL;
	}

	return getTeamFromTeamColor(p->getTeamColor());
}

// FUNCTION: WEBSERVICE 0x100dab50
// FUNCTION: ROBLOX 0x005e7940
boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Teams::getTeams()
{
	return teams.read();
}

// FUNCTION: WEBSERVICE 0x100daba0
// FUNCTION: ROBLOX 0x005e7990
bool Teams::teamExists(BrickColor color)
{
	return getTeamFromTeamColor(color) != NULL;
}

// FUNCTION: ROBLOX 0x005e7a40
bool Teams::isTeamGame()
{
	Network::Players* players = ServiceProvider::find<Network::Players>(this);

	for (unsigned int i = 0; i < players->numChildren(); i++) {
		if (Network::Player* player = dynamic_cast<Network::Player*>(players->getChild(i))) {
			if (!player->getNeutral()) {
				return true;
			}
		}
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100daca0
// FUNCTION: ROBLOX 0x005e7ad0
int Teams::getNumPlayersInTeam(BrickColor color)
{
	int count = 0;
	Network::Players* players = ServiceProvider::find<Network::Players>(this);

	for (unsigned int i = 0; i < players->numChildren(); i++) {
		if (Network::Player* player = dynamic_cast<Network::Player*>(players->getChild(i))) {
			if (!player->getNeutral() && player->getTeamColor() == color) {
				count++;
			}
		}
	}

	return count;
}

// FUNCTION: WEBSERVICE 0x100dad30
// FUNCTION: ROBLOX 0x005e7b60
G3D::Color3 Teams::getTeamColorForHumanoid(Humanoid* h)
{
	Network::Players* players = ServiceProvider::find<Network::Players>(this);

	for (unsigned int i = 0; i < players->numChildren(); i++) {
		if (Network::Player* player = dynamic_cast<Network::Player*>(players->getChild(i))) {
			if (!player->getNeutral()) {
				if (player->getCharacter()) {
					if (player->getCharacter()->findFirstChildOfType<Humanoid>() == h) {
						return player->getTeamColor().color3();
					}
				}
			}
		}
	}

	return G3D::Color3::white();
}

// FUNCTION: WEBSERVICE 0x100dae00
// FUNCTION: ROBLOX 0x005e7c30
void Teams::assignNewPlayerToTeam(Network::Player* p)
{
	BrickColor best = BrickColor(BrickColor::lego_28);
	int best_count = 10000;
	bool found = false;

	for (unsigned int i = 0; i < numChildren(); i++) {
		if (Team* team = dynamic_cast<Team*>(getChild(i))) {
			if (team->getAutoAssignable() == true) {
				int count = getNumPlayersInTeam(team->getTeamColor());
				if (count < best_count) {
					best = team->getTeamColor();
					best_count = count;
					found = true;
				}
			}
		}
	}

	if (found) {
		p->setTeamColor(best);
		p->setNeutral(false);
	}
}

// FUNCTION: WEBSERVICE 0x100daf00
// FUNCTION: ROBLOX 0x005e7d30
void Teams::onChildAdded(Instance* child)
{
	if (dynamic_cast<Team*>(child)) {
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& t = teams.write();
		t->push_back(shared_from(child));
	}
}

// FUNCTION: WEBSERVICE 0x100dafc0
// FUNCTION: ROBLOX 0x005e7df0
void Teams::onChildRemoving(Instance* child)
{
	if (dynamic_cast<Team*>(child)) {
		boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& t = teams.write();
		t->erase(std::find(t->begin(), t->end(), shared_from(child)));
	}
}

// FUNCTION: WEBSERVICE 0x100db320
// FUNCTION: ROBLOX 0x005e8160
Teams::Teams() : teams(std::vector<boost::shared_ptr<Instance> >())
{
	setName(sTeams);
}

// FUNCTION: WEBSERVICE 0x1015b610 FOLDED
// FUNCTION: ROBLOX 0x00751160 FOLDED
void Teams::rebalanceTeams()
{
}

} // namespace RBX

template class RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams>;
template class RBX::Reflection::
	Described<RBX::Teams, RBX::sTeams, RBX::FactoryProduct<RBX::Teams, RBX::Instance, RBX::sTeams> >;
template class RBX::DescribedCreatable<RBX::Teams, RBX::Instance, RBX::sTeams>;
