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
	template<>
	std::string StringConverter<BrickColor>::convertToString(const BrickColor& value)
	{
		return value.name();
	}

	template<>
	std::string StringConverter<G3D::CoordinateFrame>::convertToString(const G3D::CoordinateFrame& value)
	{
		const G3D::Matrix3& r = value.rotation;
		char text[512];
		_snprintf(text, sizeof(text), "%g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g",
				  value.translation.x, value.translation.y, value.translation.z,
				  r[0][0], r[0][1], r[0][2], r[1][0], r[1][1], r[1][2], r[2][0], r[2][1], r[2][2]);
		return text;
	}

	namespace Reflection
	{
		template<>
		std::string TypedPropertyDescriptor<BrickColor>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<BrickColor>::convertToString(getValue(instance));
		}

		template<>
		bool TypedPropertyDescriptor<BrickColor>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			setValue(instance, BrickColor::parse(text.c_str()));
			return true;
		}

		template<>
		std::string TypedPropertyDescriptor<G3D::CoordinateFrame>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<G3D::CoordinateFrame>::convertToString(getValue(instance));
		}

		template<>
		bool TypedPropertyDescriptor<G3D::CoordinateFrame>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			float v[12];
			if (sscanf(text.c_str(), "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f",
					   &v[0], &v[1], &v[2], &v[3], &v[4], &v[5], &v[6], &v[7], &v[8], &v[9], &v[10], &v[11]) != 12)
				return false;
			setValue(instance, G3D::CoordinateFrame(G3D::Matrix3(v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11]),
													 G3D::Vector3(v[0], v[1], v[2])));
			return true;
		}

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
		RBX_REBUILD_CONTENT_STRINGS(MeshId)
		RBX_REBUILD_CONTENT_STRINGS(TextureId)
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
