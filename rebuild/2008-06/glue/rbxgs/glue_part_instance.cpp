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



	// a part may live anywhere in the tree
}
