// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/Clothing.h"

namespace RBX
{
	// INFERRED: the DescribedCreatable<Clothing, CharacterAppearance, sClothing> base constructor (0x5d5270),
	// the vtable stores and the default construction of outfit1 / outfit2 (std::string plus Name::getNullName())
	// are all emitted implicitly by the compiler. Only the body is explicit:
	// a temporary std::string("Clothing") is passed to Instance::setName (0x55af90).
	Clothing::Clothing()
	{
		setName(std::string("Clothing"));
	}
}
