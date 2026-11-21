// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 2008-06 native RBX::Guid::readableString (inactive). Flags copied from Guid.cpp (the other util/Guid.cpp rows).
// Identity: registry ?readableString@Guid@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
// 004aadd0 (thiscall, ret 8); its row sits in the Network settings range, so the 2008 copy was emitted by a Network
// object. Callers: the Replicator print paths (NetworkReplicator2008Items.cpp).
#include "util/Guid.h"

namespace RBX
{
	// 004aadd0: forwards this (data at +0x00) to Guid::Data::readableString 005a8440 with the constant 4; the
	// scopeLength argument is never read. Donor body: util/Guid.cpp.
	std::string Guid::readableString(int scopeLength) const
	{
		return this->data.readableString(4);
	}
}
