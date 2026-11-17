// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native TypedPropertyDescriptor<T> explicit specializations (readValue / writeValue / getStringValue /
// setStringValue) for bool, int, float, std::string, Vector2int16, Vector3 and SoundId (inactive). Names from the
// identity registry; bodies byte-proved by the named lane (native_placeholder_llm.py --named).
#include "reflection/property.h"
#include "v8xml/XmlElement.h"
#include "util/Sound.h"

// 0056e6e0
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

// 0056e310
namespace RBX {
namespace Reflection {

template<>
std::string TypedPropertyDescriptor<G3D::Vector3>::getStringValue(const DescribedBase* instance) const
{
    return StringConverter<G3D::Vector3>::convertToString(getValue(instance));
}

} // namespace Reflection
} // namespace RBX

// 005b8150
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

// 0056e1c0
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

// 0056e550
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

// 0056e3a0
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

// 0056e0c0
namespace RBX {
namespace Reflection {

template<>
std::string TypedPropertyDescriptor<std::string>::getStringValue(const DescribedBase* object) const
{
	return getValue(object);
}

}
}

// 0056e430
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

// 0056e7e0
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
