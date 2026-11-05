// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs roc_unit_6d53eb90d22581ff.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("util/IRenderable.h", "roc_unit_b8671ae8d3010f90.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_unit_b34763c2f3d3f398.cpp")
#include "humanoid/Humanoid.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
extern Reflection::PropDescriptor<Humanoid,G3D::Vector3> propWalkDirection;
extern Reflection::PropDescriptor<Humanoid,G3D::Vector3> propWalkToPoint;
extern Reflection::PropDescriptor<Humanoid,float> propWalkRotationalVelocity;
extern Reflection::RefPropDescriptor<Humanoid,PartInstance> propWalkToPart;
	void Humanoid::setWalkDirection(const G3D::Vector3& value)
	{
		if ((*reinterpret_cast<G3D::Vector3*>(reinterpret_cast<char*>(this)+0x1d0)) != value)
		{
			if (value == G3D::Vector3::zero())
			{
				(*reinterpret_cast<G3D::Vector3*>(reinterpret_cast<char*>(this)+0x1d0)) = value;
			}
			else
			{
				(*reinterpret_cast<G3D::Vector3*>(reinterpret_cast<char*>(this)+0x1d0)) = G3D::Vector3(value.x, 0.0f, value.z).direction();
				(*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) = DIRECTION_MOVE;
			}

			raisePropertyChanged(propWalkDirection);
		}
	}

	void Humanoid::setWalkRotationalVelocity(const float& value)
	{
		if ((*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1b0)) != value)
		{
			(*reinterpret_cast<float*>(reinterpret_cast<char*>(this)+0x1b0)) = value;
			raisePropertyChanged(propWalkRotationalVelocity);
		}
	}

	void Humanoid::setWalkToPoint(const G3D::Vector3& value)
	{
		if ((*reinterpret_cast<G3D::Vector3*>(reinterpret_cast<char*>(this)+0x1c4)) != value)
		{
			(*reinterpret_cast<G3D::Vector3*>(reinterpret_cast<char*>(this)+0x1c4)) = value;
			raisePropertyChanged(propWalkToPoint);
		}

		(*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) = ((*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) == HAS_PART) ? CLICK_TO_MOVE : HAS_POINT;
		(*reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x1b4)) = ((*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) == CLICK_TO_MOVE) ? 240 : 0;
	}

	void Humanoid::setWalkToPart(PartInstance* value)
	{
		if ((*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x1bc)).get() != value)
		{
			(*reinterpret_cast<boost::shared_ptr<PartInstance>*>(reinterpret_cast<char*>(this)+0x1bc)) = shared_from(value);
			raisePropertyChanged(propWalkToPart);
		}

		(*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) = ((*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) == HAS_POINT) ? CLICK_TO_MOVE : HAS_PART;
		(*reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x1b4)) = ((*reinterpret_cast<WalkMode*>(reinterpret_cast<char*>(this)+0x1b8)) == CLICK_TO_MOVE) ? 240 : 0;
	}

}
