// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_d6cab88ba07e13d4.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#include "humanoid/Humanoid.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
extern Reflection::RefPropDescriptor<Humanoid,PartInstance> propTorso;
extern Reflection::RefPropDescriptor<Humanoid,PartInstance> propLeftLeg;
extern Reflection::RefPropDescriptor<Humanoid,PartInstance> propRightLeg;
	void Humanoid::setLeftLeg(PartInstance* value)
	{
		if ((*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x1fc)).get() != value)
		{
			(*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x1fc)) = shared_from(value);
			raisePropertyChanged(propLeftLeg);
		}
	}

	void Humanoid::setRightLeg(PartInstance* value)
	{
		if ((*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x204)).get() != value)
		{
			(*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x204)) = shared_from(value);
			raisePropertyChanged(propRightLeg);
		}
	}

	void Humanoid::setTorso(PartInstance* value)
	{
		if ((*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x1f4)).get() != value)
		{
			(*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x1f4)) = shared_from(value);
			raisePropertyChanged(propTorso);
		}
	}

}
