// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs security/SecurityContext.cpp

// Candidate translation unit (score above; library headers required).
#include "security/SecurityContext.h"

namespace RBX
{
	namespace Security
	{
		bool Context::isInRole(Identities identity, Permissions permission)
		{
			switch (identity)
			{
			case Anonymous:
			case GameScript:
				return permission == None;

			case LocalGUI:
			case CmdLine:
			case TrustedCOM:
			case TrustedWebService:
			case Replicator:
				return true;

			default:
				return false;
			}
		}
	}
}
