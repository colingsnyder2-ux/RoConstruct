#pragma once
// >>> native-status (generated) -- do not edit >>>
// SpawnLocation | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2410712f | roc native-status --write
// 2008-06 native RBX::SpawnLocation (inactive). Shape after the donor tools/rbxgs SpawnLocation.h; every base,
// field and descriptor below is read from the 2008-06 binary:
//   RTTI       vtable 0083c0d4 .?AVSpawnLocation@RBX@@ -> DescribedCreatable<SpawnLocation, PartInstance, sSpawnLocation>
//              (37 bases; name mangled $1?sSpawnLocation@2@3PADA, a char array in .data at 009525cc), PartInstance's
//              virtual bases IPrimaryPart / ICameraSubject(ILocation) / ISelectable3d through the vbptr at +0x134.
//   size       0x424: Creatable<Instance>::create<SpawnLocation> 0048efb0 allocates 0x424 and calls 005d3490 with
//              the most-derived flag. PartInstance's non-virtual part ends at +0x3e8 (the PartInstance vbases start
//              at +0x3ec in Part's own vtables 00832c80...); SpawnLocation's fields fill +0x3e8..+0x408 and the
//              virtual bases (with vtordisp) follow from +0x408.
//   fields     constructor 005d3490: teamColor +0x3e8 = 0xc2 (BrickColor 194), scoped_connection +0x3ec
//              (connection: shared_ptr +0x3f0/+0x3f4, controlling +0x3f8; released +0x3fc; dtor 005954b0 in
//              ~SpawnLocation 005d3730), neutral +0x400 = 1, allowTeamChangeOnTouch +0x401 = 0, duration +0x404 = 10,
//              then setName("SpawnLocation") through PartInstance::setName 00598c20.
//   descriptors (dynamic initializers 007f5f20..007f5fb0, atexit 007feff0..007ff050):
//              prop_Duration 00979ea8 BoundProp<int,1> "Duration"/"Forcefield" member +0x404 (ctor 005d27d0),
//              prop_Neutral 00979e8c BoundProp<bool,1> "Neutral"/"Teams" member +0x400 (ctor 005d28b0),
//              prop_AllowTeamChangeOnTouch 00979e70 BoundProp<bool,1> "AllowTeamChangeOnTouch"/"Teams" +0x401,
//              prop_TeamColor 00979ec4 PropDescriptor<SpawnLocation, BrickColor> "TeamColor"/"Teams"
//              (getTeamColor 005d1ba0, setTeamColor 005d37b0; ctor 005d2990).
//   vtable     only slot 12 onServiceProvider 005d37d0 differs from PartInstance's vtable 00832d4c; the destructor
//              005d3730 does not reset vtables (implicit).
// Blocked: native-headers/v8datamodel/PartInstance.h currently compiles to sizeof 0x2ec (vbases included), not the
// 2008 non-virtual size 0x3e8, so every row that depends on these field offsets or on PartInstance's layout is
// recorded as non-exact by tests/record_native_spawn.py (see the receipt).
#include "v8datamodel/PartInstance.h"
#include <boost/signals/connection.hpp>

struct NativeSpawnLayout;

namespace RBX
{
	extern char sSpawnLocation[];

	class SpawnLocation : public DescribedCreatable<SpawnLocation, PartInstance, sSpawnLocation>
	{
		friend struct ::NativeSpawnLayout; // tests/NativeSpawnLayout.cpp offset asserts (pending PartInstance)

	private:
		BrickColor teamColor;                               // +0x3e8
		boost::signals::scoped_connection spawnerTouched;   // +0x3ec

	public:
		bool neutral;                                       // +0x400
		bool allowTeamChangeOnTouch;                        // +0x401
		int duration;                                       // +0x404 ("Duration", category "Forcefield")

	public:
		static Reflection::BoundProp<int, 1> prop_Duration;
		static Reflection::BoundProp<bool, 1> prop_Neutral;
		static Reflection::BoundProp<bool, 1> prop_AllowTeamChangeOnTouch;

	public:
		SpawnLocation();                                    // 005d3490

		BrickColor getTeamColor() const;                    // 005d1ba0
		void setTeamColor(BrickColor color);                // 005d37b0

	protected:
		// 005d37d0: connects PartInstance::event_Touched (SignalDesc connect 004a3340 with a third argument 10)
		// and registers with SpawnerService. Not defined here: see the receipt.
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};
}
