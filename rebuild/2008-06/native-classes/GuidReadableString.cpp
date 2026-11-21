// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
// 2008-06 native RBX::Guid::readableString (inactive). Flags copied from Guid.cpp (the other util/Guid.cpp rows).
// Identity: registry ?readableString@Guid@RBX@@QBE?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z
// 004aadd0 (thiscall, ret 8); its row sits in the Network settings range, so the 2008 copy was emitted by a Network
// object. Callers: the Replicator print paths (NetworkReplicator2008Items.cpp).
#define _CRT_SECURE_NO_DEPRECATE
#include "util/Guid.h"
#include <algorithm>
#include <stdio.h>

namespace RBX
{
	// 004aadd0: forwards this (data at +0x00) to Guid::Data::readableString 005a8440 with the constant 4; the
	// scopeLength argument is never read. Donor body: util/Guid.cpp.
	std::string Guid::readableString(int scopeLength) const
	{
		return this->data.readableString(4);
	}

	// 005a8210 ??MData@Guid@RBX@@QBE_NABU012@@Z (thiscall, ret 4). Identity: registry decorated name; the row sits
	// in the util/Guid.cpp object (generateGUID 005a8140, initLocalScope 005a8260, Guid() 005a8300). Asm: scopes
	// differ -> this->scope->name.compare(other.scope->name) (msvcp90 compare); -1 -> true, 0 -> index compare
	// (setl), anything else -> false. Donor body: util/Guid.cpp (its RBXASSERT on != 1 compiles out).
	// NEAR MISS (parked after 3 hypotheses, batch 35): 70 B and loads match, but the target places the
	// 'case -1 -> mov al,1' tail after the shared index compare; this source emits it right after the false return.
	bool Guid::Data::operator <(const Data& other) const
	{
		const Name* otherScope = other.scope;
		if (this->scope != otherScope)
		{
			switch (this->scope->name.compare(otherScope->name))
			{
			case 0:
				break;
			case -1:
				return true;
			default:
				return false;
			}
		}
		return this->index < other.index;
	}

	// 005a8440 ?readableString@Data@Guid@RBX@@QBE?AV?$basic_string@...@H@Z (thiscall, ret 8). Same util/Guid.cpp
	// object. Asm: char[64] at +0x44 of the frame; scopeLength > 0 -> copy scope->name, substr(min<size_t>(3, size)
	// (unsigned jb), min(scopeLength, 32) (signed jg)), sprintf "%s_%d" 00834348; else sprintf "%d" 008135d0;
	// return std::string(result). The donor body (util/Guid.cpp) passes only one substr argument; the 2008 call
	// pushes the min(scopeLength, 32) count.
	std::string Guid::Data::readableString(int scopeLength) const
	{
		char result[64];

		if (scopeLength > 0)
		{
			std::string scopeName = this->scope->name;
			scopeName = scopeName.substr(std::min<size_t>(3, scopeName.size()), std::min(scopeLength, 32));
			sprintf(result, "%s_%d", scopeName.c_str(), this->index);
		}
		else
		{
			sprintf(result, "%d", this->index);
		}

		return result;
	}
}
