#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {
char sFaceInstance[] = "FaceInstance";
FaceInstance::FaceInstance() : face(NORM_Z_NEG) {}
bool FaceInstance::askSetParent(const Instance* instance) const {
    return dynamic_cast<const PartInstance*>(instance) != NULL;
}
}

#include "AppDraw/DrawAdorn.h"
#include <G3D/Color4.h>

namespace RBX
{

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
