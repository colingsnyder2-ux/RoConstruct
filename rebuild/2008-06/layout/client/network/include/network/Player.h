// =============================================================================
// Player.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/network/include/network/Player.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8tree/Instance.h"
#include "v8datamodel/BrickColor.h"
#include "util/Events.h"
#include <boost/signals/connection.hpp>
#include <G3D/Vector2int16.h>
#include <G3D/G3DGameUnits.h>
#include <string>

struct NativeNetworkPlayerLayout;

namespace RBX
{
	class ModelInstance;
	class Backpack;

	namespace Network
	{
		struct CharacterAdded
		{
		public:
			const boost::shared_ptr<Instance> character;

		public:
			CharacterAdded(Instance* character)
				: character(shared_from(character))
			{
			}
		};

		struct CharacterRemoving
		{
		public:
			const boost::shared_ptr<Instance> character;

		public:
			CharacterRemoving(Instance* character)
				: character(shared_from(character))
			{
			}
		};

		extern char sPlayer[];

		class Player : public DescribedCreatable<Player, Instance, sPlayer>,
					   public Notifier<Player, CharacterAdded>,
					   public Notifier<Player, CharacterRemoving>
		{
			friend struct ::NativeNetworkPlayerLayout; // tests/NativeNetworkPlayerLayout.cpp offset asserts
		private:
			boost::shared_ptr<ModelInstance> character;               // +0x170
			BrickColor teamColor;                                     // +0x178
			bool neutral;                                             // +0x17c
			boost::signals::scoped_connection characterDiedConnection; // +0x180
			std::string characterAppearance;                          // +0x194
			bool under13;                                             // +0x1b0
			bool superSafeChat;                                       // +0x1b1
			int userId;                                               // +0x1b4
			G3D::Vector2int16 serverRequestLow;                       // +0x1b8
			G3D::Vector2int16 serverRequestHigh;                      // +0x1bc
			G3D::Vector2int16 serverDemandLow;                        // +0x1c0
			G3D::Vector2int16 serverDemandHigh;                       // +0x1c4
			G3D::Vector2int16 clientSimulateLow;                      // +0x1c8
			G3D::Vector2int16 clientSimulateHigh;                     // +0x1cc
			G3D::RealTime lastActivityTime;                           // +0x1d0

		public:
			static Reflection::BoundProp<bool, 1> prop_Under13;                    // 0096fee4
			static Reflection::BoundProp<bool, 1> prop_SuperSafeChat;              // 0096fcd4
			static Reflection::BoundProp<G3D::Vector2int16, 1> prop_ServerRequestLow;   // 0096fe08
			static Reflection::BoundProp<G3D::Vector2int16, 1> prop_ServerRequestHigh;  // 0096fdec
			static Reflection::BoundProp<G3D::Vector2int16, 1> prop_ServerDemandLow;    // 0096fd0c
			static Reflection::BoundProp<G3D::Vector2int16, 1> prop_ServerDemandHigh;   // 0096feac
			static Reflection::BoundProp<G3D::Vector2int16, 1> prop_ClientSimulateLow;  // 0096fdd0
			static Reflection::BoundProp<G3D::Vector2int16, 1> prop_ClientSimulateHigh; // 0096fcf0

		private:
			virtual bool askAddChild(const Instance*) const
			{
				return true;                                          // 00565ff0 (ICF)
			}
			virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 00494740
			void onCharacterChangedFrontend();                        // 004924e0
			void doPeriodicIdleCheck();                               // 00494650
			void loadCharacterAppearance(bool);                       // 00495380 (argument meaning not derived)
			void removeCharacterAppearance();

		public:
			Player();                                                 // 00493da0
			virtual ~Player();                                        // 00494c60 (deleting 00494f60)

		public:
			virtual void setName(const std::string& value);           // 004937c0
			ModelInstance* getCharacter() const                       // 005b6590 (ICF)
			{
				return character.get();
			}
			void setCharacter(ModelInstance* value);                  // 004944b0
			BrickColor getTeamColor() const                           // 00445260 (ICF)
			{
				return teamColor;
			}
			void setTeamColor(BrickColor value);                      // 00494600
			bool getNeutral() const                                   // 00489960 (ICF)
			{
				return neutral;
			}
			void setNeutral(bool value);                              // 00494620
			std::string getCharacterAppearance() const                // 00489970
			{
				return characterAppearance;
			}
			void setCharacterAppearance(const std::string& value);    // 00495d00
			int getUserID() const                                     // 004899a0 (ICF)
			{
				return userId;
			}
			void setUserID(int value);                                // 00494830
			static void onLocalPlayerNotIdle(ServiceProvider* serviceProvider); // 00492320; INFERRED: name from the 2007 donor Player.h declaration (body: find<Players>, local player, lastActivityTime = getLocalTime)
			void setUnder13(bool value)                               // 0048b910 (folded copy outside the unit)
			{
				prop_Under13.setValue(this, value);
			}
			bool getSuperSafeChat() const { return superSafeChat; }
			void setSuperSafeChat(bool value)                         // 0048b940
			{
				prop_SuperSafeChat.setValue(this, value);
			}
			Backpack* getPlayerBackpack() const;                      // donor declaration (used by native ClearBackpack.cpp); 2008 body not located
			void loadCharacter(bool inGame);                          // 004957a0
			void removeCharacter();                                   // 004947b0
			void rebuildBackpack();                                   // 004925c0
		};
	}
}
