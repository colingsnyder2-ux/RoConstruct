// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
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
