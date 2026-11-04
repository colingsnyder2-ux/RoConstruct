#pragma once
// Declaration-only overlay used by tests/record_native_team.py to verify the Player-dependent
// Teams bodies (NATIVE_TEAMS_PENDING). Copied as out/native-team-pending/Network/Player.h.
// Not a recovery of Player: only the bases and leading fields the Teams bodies touch.
//   Player RTTI (vtable 0082220c, 23 bases): DescribedCreatable<Player, Instance, sPlayer>
//     (name mangled 3PADA: char array), Notifier<Player, CharacterAdded> mdisp 0x130,
//     Notifier<Player, CharacterRemoving> mdisp 0x150.
//   Fields read by Teams 005d60f0/005d6070/005d6180/005d5ea0: character +0x170 (shared_ptr
//     pointer), teamColor +0x178, neutral +0x17c; setters setTeamColor 00494600 / setNeutral
//     00494620 compare and store the same offsets.
//   Players RTTI (vtable 008227bc): Notifier<Players, ChatMessage> 0x130,
//     Notifier<Players, SuperSafeChanged> 0x150, Listener<Player, CharacterAdded> 0x170,
//     Service 0x174; Teams only needs it as an Instance.
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	class ModelInstance;
	namespace Network
	{
		struct CharacterAdded { const boost::shared_ptr<Instance> character; };
		struct CharacterRemoving { const boost::shared_ptr<Instance> character; };

		extern char sPlayer[];
		class Player : public DescribedCreatable<Player, Instance, sPlayer>,
					   public Notifier<Player, CharacterAdded>,
					   public Notifier<Player, CharacterRemoving>
		{
		private:
			boost::shared_ptr<ModelInstance> character; // +0x170
			BrickColor teamColor;                       // +0x178
			bool neutral;                               // +0x17c
		public:
			ModelInstance* getCharacter() const { return character.get(); }
			BrickColor getTeamColor() const { return teamColor; }
			void setTeamColor(BrickColor value);        // 00494600
			bool getNeutral() const { return neutral; }
			void setNeutral(bool value);                // 00494620
		};

		extern char sPlayers[];
		class Players : public DescribedCreatable<Players, Instance, sPlayers>, public Service
		{
		};
	}
}
