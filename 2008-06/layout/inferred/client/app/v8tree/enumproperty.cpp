#include "reflection/type.h"
#include "G3D/g3dmath.h"
#include "G3D/Vector3.h"
#include "G3D/Vector2int16.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include "util/ContentProvider.h"

namespace RBX
{
	namespace Reflection
	{
		template<>
		int& Value::convert<int>()
		{
			if (isType<float>())
			{
				value = G3D::iRound(boost::any_cast<float>(value));
				_type = &Type::singleton<int>();
			}
			if (isType<double>())
			{
				value = G3D::iRound(boost::any_cast<double>(value));
				_type = &Type::singleton<int>();
			}
			if (isType<bool>())
			{
				value = (int)(boost::any_cast<bool>(value) != 0);
				_type = &Type::singleton<int>();
			}
			return genericConvert<int>();
		}

		template<>
		bool& Value::convert<bool>()
		{
			if (isType<int>())
			{
				value = boost::any_cast<int>(value) != 0;
				_type = &Type::singleton<bool>();
			}
			if (isType<float>())
			{
				value = boost::any_cast<float>(value) != 0.0f;
				_type = &Type::singleton<bool>();
			}
			if (isType<double>())
			{
				value = boost::any_cast<double>(value) != 0.0;
				_type = &Type::singleton<bool>();
			}
			return genericConvert<bool>();
		}

		template<>
		double& Value::convert<double>()
		{
			if (isType<int>())
			{
				value = (double)boost::any_cast<int>(value);
				_type = &Type::singleton<double>();
			}
			if (isType<bool>())
			{
				value = (double)(int)(boost::any_cast<bool>(value) != 0);
				_type = &Type::singleton<double>();
			}
			if (isType<float>())
			{
				value = (double)boost::any_cast<float>(value);
				_type = &Type::singleton<double>();
			}
			return genericConvert<double>();
		}
		template<>
		G3D::Vector3& Value::convert<G3D::Vector3>()
		{
			return genericConvert<G3D::Vector3>();
		}

		template<>
		G3D::CoordinateFrame& Value::convert<G3D::CoordinateFrame>()
		{
			return genericConvert<G3D::CoordinateFrame>();
		}

		template<>
		G3D::Vector2int16& Value::convert<G3D::Vector2int16>()
		{
			return genericConvert<G3D::Vector2int16>();
		}

		template<>
		G3D::Color3& Value::convert<G3D::Color3>()
		{
			return genericConvert<G3D::Color3>();
		}

		template<>
		BrickColor& Value::convert<BrickColor>()
		{
			return genericConvert<BrickColor>();
		}

		template<>
		ContentId& Value::convert<ContentId>()
		{
			if (isType<std::string>())
			{
				value = ContentId(boost::any_cast<std::string>(value));
				_type = &Type::singleton<ContentId>();
			}
			return genericConvert<ContentId>();
		}
	}
}

#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include "util/Sound.h"

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<bool>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (!element->isXsiNil())
    {
        bool value;
        if (element->getValue(value))
            getset->setValue(instance, value);
    }
}

}
}

namespace RBX {
namespace Reflection {

template<>
std::string TypedPropertyDescriptor<G3D::Vector3>::getStringValue(const DescribedBase* instance) const
{
    return StringConverter<G3D::Vector3>::convertToString(getValue(instance));
}

} // namespace Reflection
} // namespace RBX

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<RBX::Soundscape::SoundId>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (!element->isXsiNil())
    {
        RBX::Soundscape::SoundId value;
        if (element->getValue(value))
        {
            RBX::Soundscape::SoundId copy(value);
            setValue(instance, copy);
        }
    }
}

}
}

namespace RBX {
namespace Reflection {

template<>
bool TypedPropertyDescriptor<float>::setStringValue(DescribedBase* instance, const std::string& text) const
{
    float value;
    if (StringConverter<float>::convertToValue(text, value))
    {
        getset->setValue(instance, value);
        return true;
    }
    return false;
}

}
}

namespace RBX {
namespace Reflection {

bool TypedPropertyDescriptor<G3D::Vector2int16>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	G3D::Vector2int16 value(0, 0);
	if (StringConverter<G3D::Vector2int16>::convertToValue(text, value))
	{
		getset->setValue(instance, value);
		return true;
	}
	return false;
}

}
}

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<G3D::Vector2int16>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		const XmlElement* xElement = element->findFirstChildByTag(tag_X);
		const XmlElement* yElement = element->findFirstChildByTag(tag_Y);
		int x;
		int y;
		xElement->getValue(x);
		yElement->getValue(y);
		setValue(instance, G3D::Vector2int16((G3D::int16)x, (G3D::int16)y));
	}
}

}
}

namespace RBX {
namespace Reflection {

template<>
std::string TypedPropertyDescriptor<std::string>::getStringValue(const DescribedBase* object) const
{
	return getValue(object);
}

}
}

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<G3D::Vector2int16>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	XmlElement* x = element->addChild(tag_X);
	XmlElement* y = element->addChild(tag_Y);
	G3D::Vector2int16 value = getValue(instance);
	x->setValue((int)value.x);
	y->setValue((int)value.y);
}

}
}

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<int>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (!element->isXsiNil())
    {
        int value;
        if (element->getValue(value))
            getset->setValue(instance, value);
    }
}

}
}

#include "util/Utilities.h"
#include "util/Name.h"

namespace boost { template<> G3D::Vector3 any_cast<G3D::Vector3>(const any&); }

namespace RBX { namespace Reflection {

template<> std::string& Value::convert<std::string>() {
	if (isType<bool>()) {
		value = StringConverter<bool>::convertToString(cast<bool>());
		_type = &Type::singleton<bool>();
	}
	if (isType<int>()) {
		value = StringConverter<int>::convertToString(cast<int>());
		_type = &Type::singleton<int>();
	}
	if (isType<float>()) {
		value = StringConverter<float>::convertToString(cast<float>());
		_type = &Type::singleton<float>();
	}
	if (isType<double>()) {
		value = StringConverter<double>::convertToString(cast<double>());
		_type = &Type::singleton<double>();
	}
	if (isType<G3D::Vector3>()) {
		value = StringConverter<G3D::Vector3>::convertToString(boost::any_cast<G3D::Vector3>(static_cast<const boost::any&>(value)));
		_type = &Type::singleton<G3D::Vector3>();
	}
	std::string* result = boost::any_cast<std::string>(&value);
	if (!result) throw std::runtime_error("Unable to cast value to std::string");
	return *result;
}

} }

#include "v8tree/Instance.h"

namespace RBX { namespace Reflection {

template<>
boost::shared_ptr<Instance>& Value::convert<boost::shared_ptr<Instance> >()
{
	if (isType<void>())
	{
		value = boost::shared_ptr<Instance>();
		_type = &Type::singleton<boost::shared_ptr<Instance> >();
	}
	if (isType<boost::shared_ptr<DescribedBase> >())
	{
		boost::shared_ptr<DescribedBase>* base = boost::any_cast<boost::shared_ptr<DescribedBase> >(&value);
		if (base)
		{
			Instance* instance = dynamic_cast<Instance*>(base->get());
			if (!instance)
				throw std::runtime_error("Unable to cast value to Object");

			value = shared_from(instance);
		}
		else
		{
			value = boost::shared_ptr<Instance>();
		}

		_type = &Type::singleton<boost::shared_ptr<Instance> >();
	}

	boost::shared_ptr<Instance>* val = boost::any_cast<boost::shared_ptr<Instance> >(&value);
	if (!val)
		throw std::runtime_error("Unable to cast value to Object");

	return *val;
}

}}

namespace RBX { namespace Reflection {
template<> float& Value::convert<float>() {
 if (isType<int>()) { value = (float)boost::any_cast<int>(value); _type = &Type::singleton<float>(); }
 if (isType<double>()) { value = (float)boost::any_cast<double>(value); _type = &Type::singleton<float>(); }
 if (isType<bool>()) { value = (float)(int)(boost::any_cast<bool>(value) != 0); _type = &Type::singleton<float>(); }
 return genericConvert<float>();
}
}}
