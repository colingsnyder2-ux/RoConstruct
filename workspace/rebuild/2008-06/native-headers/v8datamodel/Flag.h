#pragma once
// >>> native-status (generated) -- do not edit >>>
// Flag | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src daf0cb3e | roc native-status --write
// 2008-06 native RBX::Flag (inactive). Shape after the donor tools/rbxgs Flag.h; every base, field and descriptor
// below is read from the 2008-06 binary:
//   RTTI       vtable 00843eb4 .?AVFlag@RBX@@ -> DescribedCreatable<Flag, Tool, sFlag> -> Tool ->
//              DescribedCreatable<Tool, BackpackItem, sTool> -> BackpackItem -> DescribedNonCreatable<BackpackItem,
//              Widget, sBackpackItem> -> Widget -> GuiItem -> Instance (+ GuiTarget +0x130, IEquipable +0x1a0,
//              IRenderable +0x1b0, virtual ILocation / ISelectable3d through the vbptr at +0x1c0). The name is mangled
//              $1?sFlag@2@3QBDB: a const char array in .rdata at 00843c90 (doDeclare 005a0320, classDescriptor
//              005c3880, constructor setName).
//   size       0x298: Creatable<Instance>::create<Flag> 005a31b0 allocates 0x298 and calls 00619820 with the
//              most-derived flag. Tool's non-virtual part ends at +0x268; Flag's fields fill +0x268..+0x290, the
//              vtordisp of the virtual bases is at +0x290 (constructor: [vbase - 4] at +0x1bc + displacement).
//   fields     constructor 00619820: evilClone shared_ptr<Instance> +0x268/+0x26c (= 0; assigned by
//              doUglyPeriodicCloneHack 00618f70, released by ~Flag 00618670), scoped_connection flagTouched +0x274
//              (words +0x278/+0x27c, controlling +0x280, released +0x284; ~scoped_connection 005954b0 on +0x274 in
//              ~Flag), timer +0x288 (= 0; tested in 00618f70, set in 006194a0), teamColor +0x28c =
//              0xc2 (BrickColor 194; getTeamColor 00618380, setTeamColor 00619a60, canBePickedUpByPlayer 00618390),
//              then Instance::setName 0055af90 with sFlag. The word at +0x270 is never written by the constructor
//              nor read by any Flag body; the donor declares FlagState state between evilClone and flagTouched.
//   descriptors prop_Color 0097bf20 PropDescriptor<Flag, BrickColor> "TeamColor"/"Data" (getTeamColor 00618380,
//              setTeamColor 00619a60; dynamic initializer 007f7cc0, atexit 00800310, ctor 006191c0).
//   destructor ~Flag 00618670 is user-declared (it rewrites the Flag vtables before the member destructors).
// Base classes come from the native v8datamodel/Tool.h and Hopper.h (Tool / BackpackItem with the 2008
// const-char-array DescribedCreatable; Tool non-virtual size 0x268, recovered in tests/record_native_hopper.py).
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
