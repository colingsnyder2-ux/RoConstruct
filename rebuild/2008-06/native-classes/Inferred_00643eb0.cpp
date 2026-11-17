// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// INFERRED: RBX::HUMAN::HumanoidState::sub_00643eb0 (placeholder name for 00643eb0 from the identity tier): whether the humanoid's character has a PartInstance child; body byte-proved
#include "humanoid/HumanoidState.h"
#include "v8datamodel/PartInstance.h"
#include "humanoid/Humanoid.h"
#include "v8datamodel/ModelInstance.h"

bool RBX::HUMAN::HumanoidState::sub_00643eb0() const
{
	return RBX::Humanoid::getCharacterFromHumanoid(humanoid)->findFirstChildOfType<RBX::PartInstance>() != NULL;
}
