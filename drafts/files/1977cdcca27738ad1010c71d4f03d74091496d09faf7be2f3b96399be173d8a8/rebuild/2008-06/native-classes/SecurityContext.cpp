// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// 2008-06 native RBX::Security::Context (inactive).
// Context::requirePermission 00489810 is already defined inline in security/SecurityContext.h; not repeated here.
#include "security/SecurityContext.h"

namespace RBX
{
	namespace Security
	{
		// The 2008 binary tests permission values 1 and 3 (jump table 005cf0b8); the header enum only names
		// None = 0 and Administrator = 1. Value 3 is the 2008 Administrator pushed by requirePermission callers
		// (see NetworkPlayer.cpp kAdministrator2008).
		static const Permissions kPermission1 = static_cast<Permissions>(1);
		static const Permissions kPermission3 = static_cast<Permissions>(3);

		// 005cf070 ?isInRole@Context@Security@RBX@@SA_NW4Identities@23@W4Permissions@23@@Z
		// Jump table 005cf0b8: Anonymous/GameScript -> None only; LocalGUI/CmdLine -> None or 1;
		// Replicator -> None or 3; TrustedCOM/TrustedWebService -> any; others false
		// (block order in the binary follows this case order).
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
