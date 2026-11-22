// 2008-06 native RBX::FaceInstance rows of the FaceInstance.cpp unit 005ef400..005ef79f (inactive), application range
// 005e8000..005f4000, against the committed native v8datamodel/FaceInstance.h (read-only). The constructor is defined
// only so this unit emits the FaceInstance vtables, ??_G and its ??_E adjustor thunks; the constructor row 005ef530 and
// ~FaceInstance 00597500 are counted by work/2008-06/shared-layouts/face-instance-lifetime.json (FaceInstanceLifetime.cpp),
// not here. setFace: face +0x140 (constructor store `mov [esi+0x140], 5`), then raisePropertyChanged(prop_Face 0097b57c).
// Verified by tests/record_native_app_unit5e8_2008.py.
#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"
#include "AppDraw/DrawAdorn.h"
#include <G3D/Color4.h>

namespace RBX
{
	char sFaceInstance[] = "FaceInstance";

	FaceInstance::FaceInstance() : face(NORM_Z_NEG) {}

	// 005ef400 (108 bytes, ret 8; IRenderable subobject +0x130, so getParent() is [this-0x2c] and face [this+0x10]):
	// __RTDynamicCast Instance (0092907c) -> PartInstance (0092dd50), then G3D::Color3::orange 005149b0 widened to a
	// Color4 with alpha 1 (fld1), PartInstance::getPart 0059aa90 and DrawAdorn::partSurface 00677630(part, face,
	// adorn, color). selectState is unused.
	void FaceInstance::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		if (PartInstance* part = dynamic_cast<PartInstance*>(getParent()))
		{
			DrawAdorn::partSurface(part->getPart(), face, adorn, G3D::Color4(G3D::Color3::orange()));
		}
	}

	void FaceInstance::setFace(NormalId value)
	{
		if (face != value)
		{
			face = value;
			raisePropertyChanged(prop_Face);
		}
	}
}
