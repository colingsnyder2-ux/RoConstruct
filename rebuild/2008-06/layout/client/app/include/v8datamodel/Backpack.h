// =============================================================================
// Backpack.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Backpack.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "script/Script.h"
#include "v8datamodel/Hopper.h"

namespace RBX
{
	extern const char sBackpack[];
	class Backpack : public RBX::DescribedCreatable<Backpack, Hopper, sBackpack>,
					 public IScriptOwner
	{
	private:
		virtual IScriptOwner* scriptShouldRun(Script* script);   // 005d18e0 (not attempted)
	public:
		Backpack();                                               // 005d1a80
	};
}
