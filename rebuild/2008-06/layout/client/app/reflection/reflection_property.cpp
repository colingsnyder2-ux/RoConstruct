#include "reflection/reflection.h"
#include "v8tree/Instance.h"
#include "util/ContentProvider.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include "v8datamodel/BrickColor.h"
#include "reflection/property.h"
#include "v8xml/XmlElement.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		const Type& Type::singleton<boost::shared_ptr<DescribedBase> >()
		{
			static Type type("Object", typeid(boost::shared_ptr<DescribedBase>));
			return type;
		}

		template<>
		const Type& Type::singleton<boost::shared_ptr<Instance> >()
		{
			static Type type("Instance", typeid(boost::shared_ptr<Instance>));
			return type;
		}

		template<>
		const Type& Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
		{
			static Type type("Objects", typeid(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >));
			return type;
		}

		template<>
		const Type& Type::singleton<int>()
		{
			static Type type("int", typeid(int));
			return type;
		}

		template<>
		const Type& Type::singleton<bool>()
		{
			static Type type("bool", typeid(bool));
			return type;
		}

		template<>
		const Type& Type::singleton<float>()
		{
			static Type type("float", typeid(float));
			return type;
		}

		template<>
		const Type& Type::singleton<double>()
		{
			static Type type("double", typeid(double));
			return type;
		}

		template<>
		const Type& Type::singleton<ContentId>()
		{
			static Type type("Content", typeid(ContentId));
			return type;
		}

		template<>
		const Type& Type::singleton<std::string>()
		{
			static Type type("string", typeid(std::string));
			return type;
		}

		template<>
		const Type& Type::singleton<G3D::Vector3>()
		{
			static Type type("Vector3", typeid(G3D::Vector3));
			return type;
		}

		template<>
		const Type& Type::singleton<G3D::Vector2int16>()
		{
			static Type type("Vector2int16", typeid(G3D::Vector2int16));
			return type;
		}

		template<>
		const Type& Type::singleton<G3D::Color3>()
		{
			static Type type("Color3", typeid(G3D::Color3));
			return type;
		}

		template<>
		const Type& Type::singleton<ValueCollection>()
		{
			static Type type("Table", typeid(ValueCollection));
			return type;
		}
		template<>
		const Type& Type::singleton<BrickColor>()
		{
			static Type type("BrickColor", typeid(BrickColor), "int");
			return type;
		}

		XmlElement* PropertyDescriptor::write(const DescribedBase* instance, bool ignoreWriteProtection) const
		{
			if (!ignoreWriteProtection) {
				if (isReadOnly()) {
					return NULL;
				}

				if (!canStreamWrite()) {
					return NULL;
				}
			}

			XmlElement* element = new XmlElement(type.tag);

			element->addAttribute<const RBX::Name*>(name_name, &name);

			writeValue(instance, element);

			return element;
		}
	}
}
