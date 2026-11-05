// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_unit_fcd0b457f199c469.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_cc3dd87ed7e7c246.cpp")
#pragma include_alias("v8datamodel/JointInstance.h", "roc_unit_ffc89e90dbae649c.cpp")
#pragma include_alias("v8datamodel/Gyro.h", "roc_unit_49d5cd98eaed3b87.cpp")
#include "v8datamodel/Tool.h"
namespace RBX {
Tool::~Tool()
	{
		RBXASSERT(!handleTouched.connected());
		RBXASSERT(!characterChildAdded.connected());
		RBXASSERT(!characterChildRemoved.connected());
		RBXASSERT(!torsoChildAdded.connected());
		RBXASSERT(!torsoChildRemoved.connected());
	}
}
