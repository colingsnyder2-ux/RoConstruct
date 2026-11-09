// Layout probe for the inactive native FlagStand header; tests/record_native_flag_family.py checks each function
// body is `mov eax, imm32; ret` with the value from the binary:
//   FlagStand fields: scoped_connection standTouched +0x3e8 and teamColor +0x3fc (constructor 0062c9c0,
//   ~FlagStand 0062cc50, getTeamColor 0062b8f0, setTeamColor 0062cdc0), so teamColor follows the connection by 0x14
//   and the class's own fields end 0x18 after the PartInstance base (virtual bases from +0x400 of 0x41c).
// The absolute offsets are not asserted: the current native PartInstance.h does not have the 2008 non-virtual
// size 0x3e8, so those asserts stay behind NATIVE_FLAGSTAND_LAYOUT until it does.
#include <stddef.h>
#include "v8datamodel/FlagStand.h"

struct NativeFlagFamilyLayout
{
	static size_t teamColorAfterConnection()
	{
		return offsetof(RBX::FlagStand, teamColor) - offsetof(RBX::FlagStand, standTouched);
	}
	static size_t connectionSize() { return sizeof(boost::signals::scoped_connection); }
#ifdef NATIVE_FLAGSTAND_LAYOUT
	typedef char StandTouched[offsetof(RBX::FlagStand, standTouched) == 0x3e8 ? 1 : -1];
	typedef char TeamColor[offsetof(RBX::FlagStand, teamColor) == 0x3fc ? 1 : -1];
	typedef char Size[sizeof(RBX::FlagStand) == 0x41c ? 1 : -1];
#endif
};

size_t nativeFlagStandTeamColorAfterConnection() { return NativeFlagFamilyLayout::teamColorAfterConnection(); }
size_t nativeFlagStandConnectionSize() { return NativeFlagFamilyLayout::connectionSize(); }
size_t nativeFlagStandBrickColorSize() { return sizeof(RBX::BrickColor); }
