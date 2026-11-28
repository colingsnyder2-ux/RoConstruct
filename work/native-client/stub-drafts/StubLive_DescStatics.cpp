// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
// Reflection statics our link left as zero stub data (event_Touched, prop_Size/Anchored/CanCollide/shapeXml, Stepped):
// parenting a Part from a script crashed (the view connects to Part signals), Part properties were missing. Definitions
// copied from the donor tools/rbxgs v8datamodel/PartInstance.cpp (same strings, accessors and flags; 2008 header
// util/RunStateOwner.h declares event_Stepped).
#include "v8datamodel/PartInstance.h"
#include "util/RunStateOwner.h"
#include "reflection/reflection.h"
namespace RBX {
	static const char* category_Part_ds = "Part";
	const Reflection::EnumPropDescriptor<PartInstance, Part::PartType> PartInstance::prop_shapeXml("shape", category_Part_ds, &PartInstance::getPartType, &PartInstance::setPartTypeXml, Reflection::PropertyDescriptor::STREAMING);
	const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_CanCollide("CanCollide", "Behavior", &PartInstance::getCanCollide, &PartInstance::setCanCollide, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Anchored("Anchored", "Behavior", &PartInstance::getAnchored, &PartInstance::setAnchored, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, G3D::Vector3> PartInstance::prop_Size("Size", category_Part_ds, &PartInstance::getPartSizeXml, &PartInstance::setPartSizeXml, Reflection::PropertyDescriptor::STREAMING);
	Reflection::SignalDesc<PartInstance, void(boost::shared_ptr<Instance>)> PartInstance::event_Touched("Touched", "part");
	Reflection::SignalDesc<RunService, void(float, float)> RunService::event_Stepped("Stepped", "time", "step");
	// Instance events (definitions as in AutoRecover_007f2b10 / 007f2b30 / 007f2bb0, which the link excludes as
	// static-initializer drafts): without them parenting a Part from a script dereferenced a zero SignalDesc
	// event_propertyChanged (AutoRecover_007f2bb0) is not declared in the native v8tree/Instance.h: left out
}
