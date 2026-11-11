// Rebuild glue: text forms of typed properties for the types rbxgs never specialises (it does bool,
// int, float, string, Vector3, Color3 and ContentId in v8tree/EnumProperty.cpp, in this same style).
// BrickColor uses its name, CoordinateFrame twelve comma-separated numbers (position then rotation
// rows), content ids their url; enums and part references have no text form here.
// Behavioural reconstruction, not byte-verified.
#include "reflection/property.h"
#include "util/Utilities.h"
#include "util/MeshId.h"
#include "util/TextureId.h"
#include "util/Debug.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/PartInstance.h"
#include <g3d/coordinateframe.h>
#include <stdio.h>

namespace RBX
{
	namespace Reflection
	{




#define RBX_REBUILD_CONTENT_STRINGS(T) \
		template<> \
		std::string TypedPropertyDescriptor<T>::getStringValue(const DescribedBase* instance) const \
		{ \
			return getValue(instance).toString(); \
		} \
		template<> \
		bool TypedPropertyDescriptor<T>::setStringValue(DescribedBase* instance, const std::string& text) const \
		{ \
			setValue(instance, T(text)); \
			return true; \
		}
#undef RBX_REBUILD_CONTENT_STRINGS

#define RBX_REBUILD_NO_STRINGS(T) \
		template<> \
		std::string TypedPropertyDescriptor<T>::getStringValue(const DescribedBase*) const \
		{ \
			return std::string(); \
		} \
		template<> \
		bool TypedPropertyDescriptor<T>::setStringValue(DescribedBase*, const std::string&) const \
		{ \
			return false; \
		}
		RBX_REBUILD_NO_STRINGS(PartInstance*)
		RBX_REBUILD_NO_STRINGS(Debugable::AssertAction)
		RBX_REBUILD_NO_STRINGS(DebugSettings::ErrorReporting)
		RBX_REBUILD_NO_STRINGS(PartInstance::FormFactor)
#undef RBX_REBUILD_NO_STRINGS
	}
}
