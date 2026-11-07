#pragma once
// >>> native-status (generated) -- do not edit >>>
// FlagStand | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 7fb96acf | roc native-status --write
// 2008-06 native RBX::FlagStand (inactive). Shape after the donor tools/rbxgs FlagStand.h; every base, field and
// descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 0084657c .?AVFlagStand@RBX@@ -> DescribedCreatable<FlagStand, PartInstance, sFlagStand>
//              (name mangled $1?sFlagStand@2@3PADA: a char array in .data at 0095be6c, pushed by doDeclare 005bf8e0,
//              classDescriptor 005c38f0 and the constructor's setName), PartInstance's virtual bases through the
//              vbptr at +0x134.
//   size       0x41c: Creatable<Instance>::create<FlagStand> 005c1040 allocates 0x41c and calls 0062c9c0 with the
//              most-derived flag. PartInstance's non-virtual part ends at +0x3e8; FlagStand's fields fill
//              +0x3e8..+0x400 and the virtual bases (with vtordisp) follow from +0x400 (vtordisp thunks 0062bbe0
//              sub 0x3fc, 0062cba0 sub 0x414).
//   fields     constructor 0062c9c0: scoped_connection +0x3e8 (connection words +0x3ec/+0x3f0, controlling +0x3f4,
//              released +0x3f8; ~scoped_connection 005954b0 on +0x3e8 in ~FlagStand 0062cc50), teamColor +0x3fc =
//              0xc2 (BrickColor 194), then PartInstance::setName 00598c20 with sFlagStand. getTeamColor 0062b8f0 and
//              setTeamColor 0062cdc0 read/write +0x3fc.
//   descriptors (dynamic initializers 007f7e90, 007f7ef0; atexit 00800450, 00800470):
//              prop_Color 0097c094 PropDescriptor<FlagStand, BrickColor> "TeamColor"/"Data" (getTeamColor 0062b8f0,
//              setTeamColor 0062cdc0, Functionality 5; ctor 0062c4c0), event_FlagCaptured 0097c060
//              SignalDesc<FlagStand, void(shared_ptr<Instance>)> "FlagCaptured"/"Player" (ctor 0062c8f0).
//              setTeamColor raises PartInstance::prop_Color (0097610c), not the FlagStand descriptor.
//   vtable     only slot 12 onServiceProvider 0062cf40 differs from PartInstance's vtable 00832d4c; the destructor
//              0062cc50 does not reset vtables (implicit).
// Blocked: native-headers/v8datamodel/PartInstance.h currently compiles to sizeof 0x2ec (vbases included), not the
// 2008 non-virtual size 0x3e8, so every row that depends on these field offsets or on PartInstance's layout is
// recorded as non-exact by tests/record_native_flag_family.py (see the receipt).
#include "v8datamodel/PartInstance.h"
#include <boost/signals/connection.hpp>

struct NativeFlagFamilyLayout;

namespace RBX
{
	class Flag;

	extern char sFlagStand[];

	class FlagStand : public DescribedCreatable<FlagStand, PartInstance, sFlagStand>
	{
		friend struct ::NativeFlagFamilyLayout; // tests/NativeFlagFamilyLayout.cpp offset asserts (pending PartInstance)

	private:
		boost::signals::scoped_connection standTouched;     // +0x3e8

	public:
		BrickColor teamColor;                               // +0x3fc

	private:
		// 0062cde0 (bound into the Touched connection by onServiceProvider 0062cf40). Not defined here.
		void onEvent_standTouched(boost::shared_ptr<Instance>);

	public:
		FlagStand();                                        // 0062c9c0

		// 0062cf40: registers with FlagStandService (ServiceProvider::create<FlagStandService> 00619360) and
		// connects PartInstance::event_Touched to onEvent_standTouched. Not defined here: see the receipt.
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);

		void AffixFlag(Flag* flag);                         // 0062bdc0 (calls Tool::getHandle 005fd760)
		Flag* GetFlag();                                    // 0062b900 (embedded Primitive +0x228, dynamic_cast<Flag*>)
		BrickColor getTeamColor() const;                    // 0062b8f0
		void setTeamColor(BrickColor color);                // 0062cdc0
	};
}
