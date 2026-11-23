// =============================================================================
// SecurityContext.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/security/SecurityContext.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "security/SecurityContext.h"

namespace RBX
{
	namespace Security
	{
		static const Permissions kPermission1 = static_cast<Permissions>(1);
		static const Permissions kPermission3 = static_cast<Permissions>(3);

		bool Context::isInRole(Identities identity, Permissions permission)
		{
			switch (identity)
			{
			case Anonymous:
			case GameScript:
				return permission == None;
			case LocalGUI:
			case CmdLine:
				return permission == None || permission == kPermission1;
			case Replicator:
				return permission == None || permission == kPermission3;
			case TrustedCOM:
			case TrustedWebService:
				return true;
			default:
				return false;
			}
		}
	}
}
