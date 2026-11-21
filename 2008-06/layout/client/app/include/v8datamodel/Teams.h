#pragma once
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/Team.h"
#include <vector>

namespace RBX
{
	namespace Network
	{
		class Player;
	}
	class Humanoid;

	extern const char sTeams[];

	class Teams : public DescribedCreatable<Teams, Instance, sTeams>, public Service
	{
		friend struct ::NativeTeamLayout; // tests/NativeTeamLayout.cpp offset asserts
	private:
		CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > teams; // +0x130

	public:
		Teams();                   // 005d6850
		virtual ~Teams();          // 005d5c90 (deleting 005d5f00)

	public:
		virtual bool askAddChild(const Instance* instance) const; // 005d5d60

		void assignNewPlayerToTeam(Network::Player* player); // 005d6250
		int getNumPlayersInTeam(BrickColor brickColor);      // 005d60f0
		bool teamExists(BrickColor brickColor);              // 005d5f20
		bool isTeamGame();                                   // 005d6070
		void rebalanceTeams();
		Team* getTeamFromTeamColor(BrickColor brickColor);   // 005d5e10
		Team* getTeamFromPlayer(Network::Player* player);    // 005d5ea0

		boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getTeams() // 005d5ed0
		{
			return teams.read();
		}

		G3D::Color3 getTeamColorForHumanoid(Humanoid* humanoid); // 005d6180

	protected:
		virtual void onChildAdded(Instance* child);    // 005d6340
		virtual void onChildRemoving(Instance* child); // 005d6400
	};
}
