// =============================================================================
// FaceInstance.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/FaceInstance.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"

namespace RBX
{
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
