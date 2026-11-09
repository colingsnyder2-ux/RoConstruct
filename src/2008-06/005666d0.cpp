// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/FaceInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/FaceInstance.h"

#include "reflection/property.h"

namespace RBX {

const char sFaceInstance[] = "FaceInstance";

// FUNCTION: WEBSERVICE 0x101219f0
FaceInstance::FaceInstance() : face(NORM_Z_NEG)
{
}

const Reflection::EnumPropDescriptor<FaceInstance, NormalId> FaceInstance::prop_Face(
	"Face",
	"Data",
	&RBX::FaceInstance::getFace,
	&RBX::FaceInstance::setFace
);

// FUNCTION: WEBSERVICE 0x10121d10
void FaceInstance::setFace(NormalId value)
{
	if (face != value) {
		face = value;
		raisePropertyChanged(prop_Face);
	}
}

} // namespace RBX
