// 2008-06 native RBX::Teams (inactive); evidence in native-headers/v8datamodel/Teams.h.
#include "v8datamodel/Teams.h"
#include <algorithm>
#include "Network/Players.h" // native Network::Players (ServiceProvider::find<Players>, 00491d50)
#include "Network/Player.h"  // native Network::Player (getNeutral/getTeamColor, setTeamColor 00494600, setNeutral 00494620)
#include "v8datamodel/ModelInstance.h"
#include "humanoid/Humanoid.h"

namespace RBX
{
	const char sTeams[] = "Teams"; // 0083cd08 (constructor 005d6850, classDescriptor 005d6000)

	// Template members the shared headers only declare (same definitions as DecalBases.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	// Dynamic initializers 007f6270 (RebalanceTeams, 0097a1c8) and 007f62a0 (GetTeams, 0097a208).
	static Reflection::BoundFuncDesc<Teams, void(void), 0> teams_rebalanceTeamsFunction(&Teams::rebalanceTeams, "RebalanceTeams", Reflection::FunctionDescriptor::NeedTrustedCaller); // 2008 pushes security 0
	static Reflection::BoundFuncDesc<Teams, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(void), 0> func_teams(&Teams::getTeams, "GetTeams", Reflection::FunctionDescriptor::NeedTrustedCaller); // 2008 pushes security 0

	Teams::Teams()
		: teams(std::vector<boost::shared_ptr<Instance> >())
	{
		setName(sTeams);
	}

	Teams::~Teams()
	{
	}

	bool Teams::askAddChild(const Instance* instance) const
	{
		return dynamic_cast<const Team*>(instance) != 0;
	}

	bool Teams::teamExists(BrickColor brickColor)
	{
		return getTeamFromTeamColor(brickColor) != NULL;
	}

	Team* Teams::getTeamFromTeamColor(BrickColor brickColor)
	{
		for (size_t i = 0; i < numChildren(); i++)
		{
			Team* team = dynamic_cast<Team*>(getChild(i));
			if (team && team->getTeamColor() == brickColor)
				return team;
		}

		return NULL;
	}

	void Teams::onChildAdded(Instance* child)
	{
		if (dynamic_cast<Team*>(child))
		{
			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myTeams = teams.write();
			myTeams->push_back(shared_from(child));
		}
	}

	void Teams::onChildRemoving(Instance* child)
	{
		if (dynamic_cast<Team*>(child))
		{
			boost::shared_ptr<std::vector<boost::shared_ptr<Instance> > >& myTeams = teams.write();
			myTeams->erase(std::find(myTeams->begin(), myTeams->end(), shared_from(child)));
		}
	}

	void Teams::rebalanceTeams()
	{
		return;
	}

	int Teams::getNumPlayersInTeam(BrickColor brickColor)
	{
		int numOfPlayers = 0;

		Network::Players* players = ServiceProvider::find<Network::Players>(this);

		for (size_t i = 0; i < players->numChildren(); i++)
		{
			Network::Player* player = dynamic_cast<Network::Player*>(players->getChild(i));
			if (player)
			{
				if (!player->getNeutral() && player->getTeamColor() == brickColor)
					numOfPlayers++;
			}
		}

		return numOfPlayers;
	}

	bool Teams::isTeamGame()
	{
		Network::Players* players = ServiceProvider::find<Network::Players>(this);

		for (size_t i = 0; i < players->numChildren(); i++)
		{
			Network::Player* player = dynamic_cast<Network::Player*>(players->getChild(i));
			if (player && !player->getNeutral())
				return true;
		}

		return false;
	}

	Team* Teams::getTeamFromPlayer(Network::Player* player)
	{
		if (player->getNeutral())
			return NULL;

		return getTeamFromTeamColor(player->getTeamColor());
	}

	G3D::Color3 Teams::getTeamColorForHumanoid(Humanoid* humanoid)
	{
		Network::Players* players = ServiceProvider::find<Network::Players>(this);

		for (size_t i = 0; i < players->numChildren(); i++)
		{
			Network::Player* player = dynamic_cast<Network::Player*>(players->getChild(i));
			if (player)
			{
				if (!player->getNeutral() && player->getCharacter())
				{
					ModelInstance* character = player->getCharacter();
					if (character->findFirstChildOfType<Humanoid>() == humanoid)
					{
						return player->getTeamColor().color3();
					}
				}
			}
		}

		return G3D::Color3::white();
	}

	void Teams::assignNewPlayerToTeam(Network::Player* player)
	{
		BrickColor best = BrickColor::lego_28;
		int best_count = 10000;
		bool found = false;

		for (size_t i = 0; i < numChildren(); i++)
		{
			Team* team = dynamic_cast<Team*>(getChild(i));
			if (team && team->getAutoAssignable() == true)
			{
				int count = getNumPlayersInTeam(team->getTeamColor());

				if (count < best_count)
				{
					best = team->getTeamColor();
					best_count = count;
					found = true;
				}
			}
		}

		if (found)
		{
			player->setTeamColor(best);
			player->setNeutral(false);
		}
	}
}
