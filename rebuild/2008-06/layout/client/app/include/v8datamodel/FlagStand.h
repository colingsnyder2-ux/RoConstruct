// =============================================================================
// FlagStand.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/FlagStand.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
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
		void onEvent_standTouched(boost::shared_ptr<Instance>);

	public:
		FlagStand();                                        // 0062c9c0

		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);

		void AffixFlag(Flag* flag);                         // 0062bdc0 (calls Tool::getHandle 005fd760)
		Flag* GetFlag();                                    // 0062b900 (embedded Primitive +0x228, dynamic_cast<Flag*>)
		BrickColor getTeamColor() const;                    // 0062b8f0
		void setTeamColor(BrickColor color);                // 0062cdc0
	};
}
