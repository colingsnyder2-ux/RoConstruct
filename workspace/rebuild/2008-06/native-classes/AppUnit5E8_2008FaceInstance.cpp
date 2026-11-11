// 2008-06 native RBX::FaceInstance rows of the FaceInstance.cpp unit 005ef400..005ef79f (inactive), application range
// 005e8000..005f4000, against the committed native v8datamodel/FaceInstance.h (read-only). The constructor is defined
// only so this unit emits the FaceInstance vtables, ??_G and its ??_E adjustor thunks; the constructor row 005ef530 and
// ~FaceInstance 00597500 are counted by work/2008-06/shared-layouts/face-instance-lifetime.json (FaceInstanceLifetime.cpp),
// not here. setFace: face +0x140 (constructor store `mov [esi+0x140], 5`), then raisePropertyChanged(prop_Face 0097b57c).
// Verified by tests/record_native_app_unit5e8_2008.py.
// >>> native-status (generated) -- do not edit >>>
// AppUnit5E8_2008FaceInstance | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src 89856234 | roc native-status --write
#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	char sFaceInstance[] = "FaceInstance";

	FaceInstance::FaceInstance() : face(NORM_Z_NEG) {}

	void FaceInstance::setFace(NormalId value)
	{
		if (face != value)
		{
			face = value;
			raisePropertyChanged(prop_Face);
		}
	}
}
