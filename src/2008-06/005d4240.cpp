// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_dba2d63ed19752e5.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8tree/Instance.h","roc_unit_b34763c2f3d3f398.cpp")
#pragma include_alias("util/IRenderable.h","roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8datamodel/PartInstance.h","roc_unit_ea83e629b1338927.cpp")
#pragma include_alias("Network/Player.h","roc_unit_1cb1f788b2f04b82.cpp")
#include "v8datamodel/CharacterAppearance.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Decal.h"
namespace RBX {
void ShirtGraphic::apply(Humanoid* humanoid)
	{
		PartInstance* torso = humanoid->getTorso();
		if (torso)
		{
			Decal* decal = torso->findFirstChildOfType<Decal>();
			if (decal)
				decal->setTexture(*reinterpret_cast<const TextureId*>(reinterpret_cast<const char*>(this) + 0x134));
		}
	}
}
