// 2008-06 native rows of the v8datamodel/Workspace.cpp unit inside the application range 005a4000..005a8000
// (inactive). Verified by tests/record_native_app_unit5a4.py (receipt app-unit5a4-working.json). Built against the
// committed native v8datamodel/Workspace.h, v8datamodel/Camera.h and reflection/*.h, all read-only.
//
// Evidence: the static initializers 007f4d60 / 007f4da0 / 007f4de0 / 007f4e20 / 007f4e60 / 007f4ea0 of this unit
// construct one reflection descriptor each, in this order, with the member-function address as an immediate:
//   "InsertContent" (arg "url")      insertContent 005a39d0      BoundFuncDesc<..., 1> ctor 005a4420
//   "MakeJoints" (arg "objects")     makeJoints 005a2420         BoundFuncDesc<..., 1> ctor 005a46a0
//   "BreakJoints" (arg "objects")    breakJoints 005a24d0        (same instantiation)
//   "SetPhysicsThrottleEnabled"      (arg "value", ICF-folded pointer 0070bdf0) BoundFuncDesc<void(bool), 1> 005a4860
//   "ZoomToExtents"                  zoomToExtents 005a0240      BoundFuncDesc<void(), 0> ctor 005a4a00
//   "CurrentCamera" (category "Data") RefPropDescriptor<Workspace, Camera> ctor 005a3be0, object 009769d8
// Each BoundFuncDesc stores the 12-byte member pointer at +0x38..+0x40 (Workspace has virtual bases; the call adjusts
// through the vbtable at Workspace+0x134). setCamera 005a5200 compares with currentCamera (+0x3fc), assigns
// shared_from(value) and raises the CurrentCamera property (push 009769d8; Instance::raisePropertyChanged 0040db00);
// the 2008 body does not reparent the old camera (the donor does).
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"

namespace RBX
{
	// rows: ctor 005a4420, execute 005a45b0, call<shared_ptr<const Instances> > 005a44d0
	static Reflection::BoundFuncDesc<Workspace, boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >(ContentId), 1> func_insertContent(&Workspace::insertContent, "InsertContent", "url", Reflection::FunctionDescriptor::AnyCaller);
	// rows: ctor 005a46a0 (execute 005a4750 is a near miss, see the receipt)
	static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >), 1> func_makeJoints(&Workspace::makeJoints, "MakeJoints", "objects", Reflection::FunctionDescriptor::AnyCaller);
	static Reflection::BoundFuncDesc<Workspace, void(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >), 1> func_breakJoints(&Workspace::breakJoints, "BreakJoints", "objects", Reflection::FunctionDescriptor::AnyCaller);
	// rows: ctor 005a4860, execute 005a4910
	static Reflection::BoundFuncDesc<Workspace, void(bool), 1> func_setPhysicsThrottleEnabled(&Workspace::setThrottleEnabled, "SetPhysicsThrottleEnabled", "value", Reflection::FunctionDescriptor::AnyCaller);
	// rows: ctor 005a4a00, execute 005a4a80
	static Reflection::BoundFuncDesc<Workspace, void(), 0> func_zoomToExtents(&Workspace::zoomToExtents, "ZoomToExtents", Reflection::FunctionDescriptor::AnyCaller);

	// ctor 005a3be0 (app-unit5a0's range; support body here, not counted)
	static Reflection::RefPropDescriptor<Workspace, Camera> currentCameraProxyProp("CurrentCamera", "Data", &Workspace::getCamera, &Workspace::setCamera, Reflection::PropertyDescriptor::STANDARD);

	// @005a5200 ?setCamera@Workspace@RBX@@QAEXPAVCamera@2@@Z
	void Workspace::setCamera(Camera* value)
	{
		if (value != currentCamera.get())
		{
			currentCamera = shared_from(value);
			raisePropertyChanged(currentCameraProxyProp);
		}
	}
}
