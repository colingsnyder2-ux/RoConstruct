// =============================================================================
// Flag.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Flag.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "v8datamodel/Tool.h"
#include "v8datamodel/BrickColor.h"
#include <boost/signals/connection.hpp>

struct NativeFlagFamilyLayout;

namespace RBX
{
	class TimerService;

	namespace Network
	{
		class Player;
	}

	extern const char sFlag[];

	class Flag : public DescribedCreatable<Flag, Tool, sFlag>
	{
		friend struct ::NativeFlagFamilyLayout;

		enum FlagState
		{
			NOTHING,
			LOOSE,
			IN_STAND,
			EQUIPPED
		};

	private:
		boost::shared_ptr<Instance> evilClone;              // +0x268
		FlagState state;                                    // +0x270 (donor; not accessed in 2008-06)
		boost::signals::scoped_connection flagTouched;      // +0x274
		TimerService* timer;                                // +0x288

	public:
		BrickColor teamColor;                               // +0x28c

	private:
		void onEvent_flagTouched(boost::shared_ptr<Instance>);
		void doUglyPeriodicCloneHack();                     // 00618f70

	protected:
		virtual bool canUnequip()
		{
			return false;
		}

		virtual bool canBePickedUpByPlayer(Network::Player* p); // 00618390

	public:
		BrickColor getTeamColor() const;                    // 00618380
		void setTeamColor(BrickColor color);                // 00619a60
		virtual void onServiceProvider(const ServiceProvider*, const ServiceProvider*); // 006194a0 (by body shape; not attempted)
		Flag();                                             // 00619820
		virtual ~Flag();                                    // 00618670
		virtual void onChildAdded(Instance* instance);      // 00619970 (by body shape; not attempted)
	};
}
