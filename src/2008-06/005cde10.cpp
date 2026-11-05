// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_unit_1a769b8435068ad9.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Camera.h"
#include "util/ICameraSubject.h"
#include "v8datamodel/ICameraOwner.h"
namespace RBX {
	static Reflection::RefPropDescriptor<Camera, Instance> cameraSubjectProp("CameraSubject", "Camera", &Camera::getCameraSubjectInstance, &Camera::setCameraSubject, Reflection::PropertyDescriptor::STANDARD);
void Camera::tellCameraMoved()
	{
		if (ICameraOwner* owner = getCameraOwner())
		{
			owner->cameraMoved();
		}
	}
Instance* Camera::getCameraSubjectInstance() const
	{
		return reinterpret_cast<const boost::shared_ptr<Instance>*>(reinterpret_cast<const char*>(this) + 0x1dc)->get();
	}
void Camera::setCameraSubject(Instance* newSubject)
	{
		if (newSubject != getCameraSubjectInstance())
		{
			if (dynamic_cast<ICameraSubject*>(newSubject))
			{
				*reinterpret_cast<boost::shared_ptr<Instance>*>(reinterpret_cast<char*>(this) + 0x1dc) = shared_from(newSubject);
				raisePropertyChanged(cameraSubjectProp);

				tellCameraMoved();
			}
		}
	}

	
}
