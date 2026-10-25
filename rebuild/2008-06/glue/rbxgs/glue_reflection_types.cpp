// Rebuild glue for the rbxgs Client tree: reflection type singletons and XML property readers/writers
// that rbxgs references but never defines. Written in the style of rbxgs v8tree/EnumProperty.cpp.
// Behavioural reconstructions: not byte-verified against 2008-06 (ownership counts only byte-identical code).
#include "reflection/type.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include "util/MeshId.h"
#include "util/TextureId.h"
#include "util/Debug.h"
#include "v8datamodel/DebugSettings.h"
#include "v8datamodel/PartInstance.h"
#include <g3d/coordinateframe.h>

namespace RBX
{
	namespace Reflection
	{
		template<>
		const Type& Type::singleton<MeshId>()
		{
			static Type type("Content", typeid(MeshId));
			return type;
		}

		template<>
		const Type& Type::singleton<TextureId>()
		{
			static Type type("Content", typeid(TextureId));
			return type;
		}

		template<>
		const Type& Type::singleton<PartInstance*>()
		{
			static Type type("Object", typeid(PartInstance*));
			return type;
		}

		template<>
		const Type& Type::singleton<const boost::shared_ptr<Instance> >()
		{
			static Type type("Object", typeid(const boost::shared_ptr<Instance>));
			return type;
		}

		template<>
		const Type& Type::singleton<Debugable::AssertAction>()
		{
			static Type type("AssertAction", typeid(Debugable::AssertAction));
			return type;
		}

		template<>
		const Type& Type::singleton<DebugSettings::ErrorReporting>()
		{
			static Type type("ErrorReporting", typeid(DebugSettings::ErrorReporting));
			return type;
		}

		template<>
		const Type& Type::singleton<PartInstance::FormFactor>()
		{
			static Type type("FormFactor", typeid(PartInstance::FormFactor));
			return type;
		}

		// Content ids are stored as their string form, as ContentId is.
		template<>
		void TypedPropertyDescriptor<MeshId>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				ContentId value;
				if (element->getValue(value))
					setValue(instance, MeshId(value.toString()));
			}
		}

		template<>
		void TypedPropertyDescriptor<MeshId>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			element->setValue(ContentId(getValue(instance).toString()));
		}

		template<>
		void TypedPropertyDescriptor<TextureId>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				ContentId value;
				if (element->getValue(value))
					setValue(instance, TextureId(value.toString()));
			}
		}

		template<>
		void TypedPropertyDescriptor<TextureId>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			element->setValue(ContentId(getValue(instance).toString()));
		}

		// Enums are stored as their integer token.
#define RBX_REBUILD_ENUM_XML(E) \
		template<> \
		void TypedPropertyDescriptor<E>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const \
		{ \
			if (!element->isXsiNil()) \
			{ \
				int value; \
				if (element->getValue(value)) \
					setValue(instance, static_cast<E>(value)); \
			} \
		} \
		template<> \
		void TypedPropertyDescriptor<E>::writeValue(const DescribedBase* instance, XmlElement* element) const \
		{ \
			element->setValue(static_cast<int>(getValue(instance))); \
		}

		RBX_REBUILD_ENUM_XML(Debugable::AssertAction)
		RBX_REBUILD_ENUM_XML(DebugSettings::ErrorReporting)
		RBX_REBUILD_ENUM_XML(PartInstance::FormFactor)
#undef RBX_REBUILD_ENUM_XML

		// A coordinate frame is X, Y, Z then the rotation rows R00..R22 (the tags XmlElement.cpp declares).
		template<>
		void TypedPropertyDescriptor<G3D::CoordinateFrame>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (element->isXsiNil())
				return;
			const Name* tags[12] = { &tag_X, &tag_Y, &tag_Z, &tag_R00, &tag_R01, &tag_R02,
									 &tag_R10, &tag_R11, &tag_R12, &tag_R20, &tag_R21, &tag_R22 };
			float v[12];
			for (int i = 0; i < 12; ++i)
			{
				const XmlElement* child = element->findFirstChildByTag(*tags[i]);
				if (!child || !child->getValue(v[i]))
					return;
			}
			G3D::CoordinateFrame value;
			value.translation = G3D::Vector3(v[0], v[1], v[2]);
			value.rotation = G3D::Matrix3(v[3], v[4], v[5], v[6], v[7], v[8], v[9], v[10], v[11]);
			setValue(instance, value);
		}

		template<>
		void TypedPropertyDescriptor<G3D::CoordinateFrame>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			G3D::CoordinateFrame value = getValue(instance);
			const Name* tags[12] = { &tag_X, &tag_Y, &tag_Z, &tag_R00, &tag_R01, &tag_R02,
									 &tag_R10, &tag_R11, &tag_R12, &tag_R20, &tag_R21, &tag_R22 };
			float v[12] = { value.translation.x, value.translation.y, value.translation.z,
							value.rotation[0][0], value.rotation[0][1], value.rotation[0][2],
							value.rotation[1][0], value.rotation[1][1], value.rotation[1][2],
							value.rotation[2][0], value.rotation[2][1], value.rotation[2][2] };
			for (int i = 0; i < 12; ++i)
				element->addChild(*tags[i])->setValue(v[i]);
		}

		// Part references are bound through IReferenceBinder by the serializer, not stored inline.
		template<>
		void TypedPropertyDescriptor<PartInstance*>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
		}

		template<>
		void TypedPropertyDescriptor<PartInstance*>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
		}
	}
}
