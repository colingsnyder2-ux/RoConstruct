// Rebuild glue: PartInstance statics and overrides rbxgs declares (v8datamodel/PartInstance.h) but
// never defines. Property names are the 2008-06 Roblox.exe strings that follow "Shape" and "GetMass"
// ("Transparency", "Reflectance", "Locked", "Anchored", "CanCollide", "RenderImportance", "Size",
// "size", ..., "Touched"); categories follow rbxgs PartInstance.cpp. Not byte-verified.
#include "v8datamodel/PartInstance.h"
#include "reflection/type.h"

namespace RBX
{
	extern const char* category_Part;
	static const char* category_Appearance = "Appearance";
	static const char* category_Behavior = "Behavior";
	static const char* category_Data = "Data";

	bool PartInstance::highlightSleepParts = false;
	bool PartInstance::highlightAwakeParts = false;

	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_RenderImportance("RenderImportance", category_Appearance,
		&PartInstance::getRenderImportance, &PartInstance::setRenderImportance, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::EnumPropDescriptor<PartInstance, Part::PartType> PartInstance::prop_shapeXml("shape", category_Part,
		&PartInstance::getPartType, &PartInstance::setPartTypeXml, Reflection::PropertyDescriptor::STREAMING);
	const Reflection::PropDescriptor<PartInstance, G3D::Color3> PartInstance::prop_Color("Color", category_Appearance,
		&PartInstance::getColor3, &PartInstance::setColor3, Reflection::PropertyDescriptor::UI);
	const Reflection::PropDescriptor<PartInstance, BrickColor> PartInstance::prop_BrickColor("BrickColor", category_Appearance,
		&PartInstance::getColor, &PartInstance::setColor, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Transparency("Transparency", category_Appearance,
		&PartInstance::getTransparencyXml, &PartInstance::setTransparency, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, float> PartInstance::prop_Reflectance("Reflectance", category_Appearance,
		&PartInstance::getReflectance, &PartInstance::setReflectance, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Locked("Locked", category_Behavior,
		&PartInstance::getPartLocked, &PartInstance::setPartLocked, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_CanCollide("CanCollide", category_Behavior,
		&PartInstance::getCanCollide, &PartInstance::setCanCollide, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, bool> PartInstance::prop_Anchored("Anchored", category_Behavior,
		&PartInstance::getAnchored, &PartInstance::setAnchored, Reflection::PropertyDescriptor::STANDARD);
	const Reflection::PropDescriptor<PartInstance, G3D::Vector3> PartInstance::prop_Size("size", category_Part,
		&PartInstance::getPartSizeXml, &PartInstance::setPartSizeXml, Reflection::PropertyDescriptor::STREAMING);
	const Reflection::PropDescriptor<PartInstance, G3D::CoordinateFrame> PartInstance::prop_CFrame("CFrame", category_Data,
		&PartInstance::getCoordinateFrame, &PartInstance::setCoordinateFrame, Reflection::PropertyDescriptor::STREAMING);
	Reflection::SignalDesc<PartInstance, void(boost::shared_ptr<Instance>)> PartInstance::event_Touched("Touched", "otherPart");

	// a part may live anywhere in the tree
	bool PartInstance::askSetParent(const Instance* instance) const
	{
		return true;
	}
}
