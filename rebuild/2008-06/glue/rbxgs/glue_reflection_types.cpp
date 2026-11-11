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
