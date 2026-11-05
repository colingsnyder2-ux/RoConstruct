// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs v8datamodel/FaceInstance.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/FaceInstance.h"
#include "v8datamodel/PartInstance.h"
#include "util/NormalId.h"
#include "v8tree/Instance.h"
#include "reflection/reflection.h"
namespace RBX 
{
	const char* sFaceInstance = "FaceInstance";
	const Reflection::EnumPropDescriptor<FaceInstance,NormalId> FaceInstance::prop_Face("Face", "Data", &FaceInstance::getFace, &FaceInstance::setFace, Reflection::PropertyDescriptor::STANDARD);

	FaceInstance::FaceInstance()
		:face(NORM_Z_NEG)
	{
	}

	void FaceInstance::setFace(NormalId value) 
	{
		if (face != value) 
		{
			face = value;
			raisePropertyChanged(prop_Face);
		}
	}


	NormalId FaceInstance::getFace() const 
	{
		return face;
	}

	bool FaceInstance::askSetParent(const Instance* instance) const 
	{
		return dynamic_cast<const PartInstance*>(instance) != NULL;
	}
}
