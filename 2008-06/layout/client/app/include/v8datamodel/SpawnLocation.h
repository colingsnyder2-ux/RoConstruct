// =============================================================================
// SpawnLocation.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/SpawnLocation.h
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
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
	};
}
