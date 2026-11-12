// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8tree/enumproperty.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/enumconverter.h"
#include "reflection/property.h"
#include "util/ContentProvider.h"
#include "util/NormalId.h"
#include "util/Utilities.h"
#include "v8datamodel/BrickColor.h"
#include "v8tree/Instance.h"
#include "v8xml/XmlElement.h"

#include <G3D/Color3.h>
#include <G3D/Vector2int16.h>
#include <G3D/Vector3.h>
#include <G3D/g3dmath.h>
#include <string>
#include <vector>

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x1003ef60
// FUNCTION: ROBLOX 0x005a5a90
template <>
const Type& Type::singleton<boost::shared_ptr<DescribedBase> >()
{
	static Type type("Object", typeid(boost::shared_ptr<DescribedBase>));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003efd0
// FUNCTION: ROBLOX 0x005a5b00
template <>
const Type& Type::singleton<boost::shared_ptr<Instance> >()
{
	static Type type("Instance", typeid(boost::shared_ptr<Instance>));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f040
// FUNCTION: ROBLOX 0x005a5b70
template <>
const Type& Type::singleton<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
{
	static Type type("Objects", typeid(boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f0b0
// FUNCTION: ROBLOX 0x005a5be0
template <>
const Type& Type::singleton<int>()
{
	static Type type("int", typeid(int));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f120
// FUNCTION: ROBLOX 0x005a5c50
template <>
const Type& Type::singleton<bool>()
{
	static Type type("bool", typeid(bool));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f190
// FUNCTION: ROBLOX 0x005a5cc0
template <>
const Type& Type::singleton<float>()
{
	static Type type("float", typeid(float));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f200
// FUNCTION: ROBLOX 0x005a5d30
template <>
const Type& Type::singleton<double>()
{
	static Type type("double", typeid(double));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f270
// FUNCTION: ROBLOX 0x005a5da0
template <>
const Type& Type::singleton<ContentId>()
{
	static Type type("Content", typeid(ContentId));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f2e0
// FUNCTION: ROBLOX 0x005a5e10
template <>
const Type& Type::singleton<std::string>()
{
	static Type type("string", typeid(std::string));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f350
// FUNCTION: ROBLOX 0x005a5e80
template <>
const Type& Type::singleton<G3D::Vector3>()
{
	static Type type("Vector3", typeid(G3D::Vector3));

	return type;
}

// FUNCTION: ROBLOX 0x005a5ef0
template <>
const Type& Type::singleton<G3D::Vector2int16>()
{
	static Type type("Vector2int16", typeid(G3D::Vector2int16));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f3c0
// FUNCTION: ROBLOX 0x005a5f60
template <>
const Type& Type::singleton<G3D::Color3>()
{
	static Type type("Color3", typeid(G3D::Color3));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f430
// FUNCTION: ROBLOX 0x005a5fd0
template <>
const Type& Type::singleton<std::vector<Value> >()
{
	static Type type("Table", typeid(std::vector<Value>));

	return type;
}

// FUNCTION: WEBSERVICE 0x1003f4a0
// FUNCTION: ROBLOX 0x005a6040
template <>
boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >& Value::convert<
	boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >()
{
	if (boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > >* objects =
			boost::any_cast<boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > >(&value)) {
		return *objects;
	}

	throw std::runtime_error("Unable to cast value to Objects");
}

// FUNCTION: WEBSERVICE 0x1003f530
template <>
std::vector<Value>& Value::convert<std::vector<Value> >()
{
	if (std::vector<Value>* values = boost::any_cast<std::vector<Value> >(&value)) {
		return *values;
	}

	throw std::runtime_error("Unable to cast value to ValueCollection");
}

// FUNCTION: WEBSERVICE 0x1003f5c0
// FUNCTION: ROBLOX 0x005a60d0
template <>
const Type& Type::singleton<BrickColor>()
{
	static Type type("BrickColor", typeid(BrickColor), "int");

	return type;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<std::string>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x10040410
// FUNCTION: ROBLOX 0x005a6cf0
template <>
std::string TypedPropertyDescriptor<std::string>::getStringValue(const DescribedBase* instance) const
{
	return getValue(instance);
}

// FUNCTION: WEBSERVICE 0x10040430
// FUNCTION: ROBLOX 0x005a6d10
template <>
bool TypedPropertyDescriptor<std::string>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	setValue(instance, text);
	return true;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<bool>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x10040450
// FUNCTION: ROBLOX 0x005a6d30
template <>
std::string TypedPropertyDescriptor<bool>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<bool>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10040490
// FUNCTION: ROBLOX 0x005a6d70
template <>
bool TypedPropertyDescriptor<bool>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	bool value;
	if (StringConverter<bool>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<float>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100404d0
// FUNCTION: ROBLOX 0x005a6db0
template <>
std::string TypedPropertyDescriptor<float>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<float>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10040510
// FUNCTION: ROBLOX 0x005a6df0
template <>
bool TypedPropertyDescriptor<float>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	float value;
	if (StringConverter<float>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<double>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x10040550
// FUNCTION: ROBLOX 0x005a6e30
template <>
std::string TypedPropertyDescriptor<double>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<double>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10040590
// FUNCTION: ROBLOX 0x005a6e70
template <>
bool TypedPropertyDescriptor<double>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	double value;
	if (StringConverter<double>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<int>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100405e0
// FUNCTION: ROBLOX 0x005a6ec0
template <>
std::string TypedPropertyDescriptor<int>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<int>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10040620
// FUNCTION: ROBLOX 0x005a6f00
template <>
bool TypedPropertyDescriptor<int>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	int value;
	if (StringConverter<int>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<G3D::Vector3>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x10040660
// FUNCTION: ROBLOX 0x005a6f40
template <>
std::string TypedPropertyDescriptor<G3D::Vector3>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<G3D::Vector3>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x100406a0
// FUNCTION: ROBLOX 0x005a6f80
template <>
bool TypedPropertyDescriptor<G3D::Vector3>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	G3D::Vector3 value;
	if (StringConverter<G3D::Vector3>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<G3D::Vector2int16>::hasStringValue() const
{
	return true;
}

// FUNCTION: ROBLOX 0x005a6fd0
template <>
void TypedPropertyDescriptor<G3D::Vector2int16>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		const XmlElement* x = element->findFirstChildByTag(tag_X);
		const XmlElement* y = element->findFirstChildByTag(tag_Y);

		int xValue;
		int yValue;
		x->getValue(xValue);
		y->getValue(yValue);
		setValue(instance, G3D::Vector2int16(xValue, yValue));
	}
}

// FUNCTION: ROBLOX 0x005a7060
template <>
void TypedPropertyDescriptor<G3D::Vector2int16>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	XmlElement* x = element->addChild(tag_X);
	XmlElement* y = element->addChild(tag_Y);

	G3D::Vector2int16 v = getValue(instance);
	x->setValue(v.x);
	y->setValue(v.y);
}

// FUNCTION: ROBLOX 0x005a7140
template <>
std::string TypedPropertyDescriptor<G3D::Vector2int16>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<G3D::Vector2int16>::convertToString(getValue(instance));
}

// FUNCTION: ROBLOX 0x005a7180
template <>
bool TypedPropertyDescriptor<G3D::Vector2int16>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	G3D::Vector2int16 value;
	if (StringConverter<G3D::Vector2int16>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100406f0
// FUNCTION: ROBLOX 0x005a71d0
template <>
void TypedPropertyDescriptor<std::string>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		std::string value;
		if (element->getValue(value)) {
			setValue(instance, value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10040780
// FUNCTION: ROBLOX 0x005a7260
template <>
void TypedPropertyDescriptor<std::string>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x100407b0
// FUNCTION: ROBLOX 0x005a7290
template <>
void TypedPropertyDescriptor<float>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		float value;
		if (element->getValue(value)) {
			setValue(instance, value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100407f0
// FUNCTION: ROBLOX 0x005a72d0
template <>
void TypedPropertyDescriptor<float>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10040830
// FUNCTION: ROBLOX 0x005a7310
template <>
void TypedPropertyDescriptor<bool>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		bool value;
		if (element->getValue(value)) {
			setValue(instance, value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10040870
// FUNCTION: ROBLOX 0x005a7350
template <>
void TypedPropertyDescriptor<double>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x100408b0
// FUNCTION: ROBLOX 0x005a7390
template <>
void TypedPropertyDescriptor<double>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		double value;
		if (element->getValue(value)) {
			setValue(instance, value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10040900
// FUNCTION: ROBLOX 0x005a73e0
template <>
void TypedPropertyDescriptor<bool>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10040930
// FUNCTION: ROBLOX 0x005a7410
template <>
void TypedPropertyDescriptor<int>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		int value;
		if (element->getValue(value)) {
			setValue(instance, value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10040970
// FUNCTION: ROBLOX 0x005a7450
template <>
void TypedPropertyDescriptor<int>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x100409a0
// FUNCTION: ROBLOX 0x005a7480
template <>
void TypedPropertyDescriptor<G3D::Vector3>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		const XmlElement* x = element->findFirstChildByTag(tag_X);
		if (x) {
			const XmlElement* y = element->findFirstChildByTag(tag_Y);
			const XmlElement* z = element->findFirstChildByTag(tag_Z);

			G3D::Vector3 v;
			x->getValue(v.x);
			y->getValue(v.y);
			z->getValue(v.z);
			setValue(instance, v);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10040a50
// FUNCTION: ROBLOX 0x005a7530
template <>
void TypedPropertyDescriptor<G3D::Vector3>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	XmlElement* x = element->addChild(tag_X);
	XmlElement* y = element->addChild(tag_Y);
	XmlElement* z = element->addChild(tag_Z);

	G3D::Vector3 v = getValue(instance);
	x->setValue(v.x);
	y->setValue(v.y);
	z->setValue(v.z);
}

// FUNCTION: WEBSERVICE 0x10040bb0
// FUNCTION: ROBLOX 0x005a7690
template <>
int& Value::convert<int>()
{
	if (isType<float>()) {
		value = G3D::iRound(boost::any_cast<float>(value));
		_type = &Type::singleton<int>();
	}

	if (isType<double>()) {
		value = G3D::iRound(boost::any_cast<double>(value));
		_type = &Type::singleton<int>();
	}

	if (isType<bool>()) {
		value = boost::any_cast<bool>(value) ? 1 : 0;
		_type = &Type::singleton<int>();
	}

	return genericConvert<int>();
}

// FUNCTION: WEBSERVICE 0x10040ce0
// FUNCTION: ROBLOX 0x005a77c0
template <>
bool& Value::convert<bool>()
{
	if (isType<int>()) {
		value = boost::any_cast<int>(value) != 0;
		_type = &Type::singleton<bool>();
	}

	if (isType<float>()) {
		value = boost::any_cast<float>(value) != 0.0f;
		_type = &Type::singleton<bool>();
	}

	if (isType<double>()) {
		value = boost::any_cast<double>(value) != 0.0;
		_type = &Type::singleton<bool>();
	}

	return genericConvert<bool>();
}

// FUNCTION: WEBSERVICE 0x10040e10
// FUNCTION: ROBLOX 0x005a78f0
template <>
float& Value::convert<float>()
{
	if (isType<int>()) {
		value = (float) boost::any_cast<int>(value);
		_type = &Type::singleton<float>();
	}

	if (isType<double>()) {
		value = (float) boost::any_cast<double>(value);
		_type = &Type::singleton<float>();
	}

	if (isType<bool>()) {
		value = (float) (boost::any_cast<bool>(value) ? 1 : 0);
		_type = &Type::singleton<float>();
	}

	return genericConvert<float>();
}

// FUNCTION: WEBSERVICE 0x10040f40
// FUNCTION: ROBLOX 0x005a7a20
template <>
double& Value::convert<double>()
{
	if (isType<int>()) {
		value = (double) boost::any_cast<int>(value);
		_type = &Type::singleton<double>();
	}

	if (isType<bool>()) {
		value = (double) (boost::any_cast<bool>(value) ? 1 : 0);
		_type = &Type::singleton<double>();
	}

	if (isType<float>()) {
		value = (double) boost::any_cast<float>(value);
		_type = &Type::singleton<double>();
	}

	return genericConvert<double>();
}

// FUNCTION: WEBSERVICE 0x10041070
// FUNCTION: ROBLOX 0x005a7b50
template <>
G3D::Vector3& Value::convert<G3D::Vector3>()
{
	return genericConvert<G3D::Vector3>();
}

// FUNCTION: WEBSERVICE 0x10041080
// FUNCTION: ROBLOX 0x005a7b60
template <>
ContentId& Value::convert<ContentId>()
{
	if (isType<std::string>()) {
		value = ContentId(boost::any_cast<std::string>(value));
		_type = &Type::singleton<ContentId>();
	}

	return genericConvert<ContentId>();
}

// FUNCTION: WEBSERVICE 0x10041140
// FUNCTION: ROBLOX 0x005a7c20
template <>
std::string& Value::convert<std::string>()
{
	if (isType<bool>()) {
		value = StringConverter<bool>::convertToString(boost::any_cast<bool>(value));
		_type = &Type::singleton<bool>();
	}

	if (isType<int>()) {
		value = StringConverter<int>::convertToString(boost::any_cast<int>(value));
		_type = &Type::singleton<int>();
	}

	if (isType<float>()) {
		value = StringConverter<float>::convertToString(boost::any_cast<float>(value));
		_type = &Type::singleton<float>();
	}

	if (isType<double>()) {
		value = StringConverter<double>::convertToString(boost::any_cast<double>(value));
		_type = &Type::singleton<double>();
	}

	if (isType<G3D::Vector3>()) {
		value = StringConverter<G3D::Vector3>::convertToString(boost::any_cast<G3D::Vector3>(value));
		_type = &Type::singleton<G3D::Vector3>();
	}

	if (std::string* s = boost::any_cast<std::string>(&value)) {
		return *s;
	}

	throw std::runtime_error("Unable to cast value to std::string");
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<G3D::Color3>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x10041430
// FUNCTION: ROBLOX 0x005a7f10
template <>
std::string TypedPropertyDescriptor<G3D::Color3>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<G3D::Color3>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10041470
// FUNCTION: ROBLOX 0x005a7f50
template <>
bool TypedPropertyDescriptor<G3D::Color3>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	G3D::Color3 value;
	if (StringConverter<G3D::Color3>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

// FUNCTION: WEBSERVICE 0x100414c0
// FUNCTION: ROBLOX 0x005a7fa0
template <>
void TypedPropertyDescriptor<G3D::Color3>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		unsigned int argb;
		if (element->getValue(argb)) {
			G3D::Color3 v(G3D::Color3uint8::fromARGB(argb));
			setValue(instance, v);
		}
		else {
			const XmlElement* r = element->findFirstChildByTag(tag_R);
			const XmlElement* g = element->findFirstChildByTag(tag_G);
			const XmlElement* b = element->findFirstChildByTag(tag_B);

			G3D::Color3 v;
			r->getValue(v.r);
			g->getValue(v.g);
			b->getValue(v.b);
			setValue(instance, v);
		}
	}
}

// FUNCTION: WEBSERVICE 0x100415b0
// FUNCTION: ROBLOX 0x005a8090
template <>
void TypedPropertyDescriptor<G3D::Color3>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	G3D::Color3uint8 v(getValue(instance));
	element->setValue(v.asUInt32());
}

// FUNCTION: WEBSERVICE 0x100eb790 FOLDED
template <>
bool TypedPropertyDescriptor<BrickColor>::hasStringValue() const
{
	return false;
}

// FUNCTION: WEBSERVICE 0x10101910 FOLDED
// FUNCTION: ROBLOX 0x005defb0 FOLDED
template <>
std::string TypedPropertyDescriptor<BrickColor>::getStringValue(const DescribedBase* instance) const
{
	return PropertyDescriptor::getStringValue(instance);
}

// FUNCTION: WEBSERVICE 0x1003ea80 FOLDED
// FUNCTION: ROBLOX 0x004ab720 FOLDED
template <>
bool TypedPropertyDescriptor<BrickColor>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	return PropertyDescriptor::setStringValue(instance, text);
}

// FUNCTION: WEBSERVICE 0x10041620
// FUNCTION: ROBLOX 0x005a8100
template <>
void TypedPropertyDescriptor<BrickColor>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		int number;
		if (element->getValue(number)) {
			setValue(instance, BrickColor(number));
		}
	}
}

// FUNCTION: WEBSERVICE 0x10041670
// FUNCTION: ROBLOX 0x005a8150
template <>
void TypedPropertyDescriptor<BrickColor>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(getValue(instance).asInt());
}

// FUNCTION: WEBSERVICE 0x100416b0
// FUNCTION: ROBLOX 0x005a8190
template <>
void TypedPropertyDescriptor<ContentId>::readValue(
	DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
) const
{
	if (!element->isXsiNil()) {
		ContentId value;
		if (element->getValue(value)) {
			setValue(instance, value);
		}
	}
}

// FUNCTION: WEBSERVICE 0x10041750 FOLDED
// FUNCTION: ROBLOX 0x00620390 FOLDED
template <>
void TypedPropertyDescriptor<ContentId>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	element->setValue(ContentId(getValue(instance)));
}

// FUNCTION: WEBSERVICE 0x100e6150 FOLDED
// FUNCTION: ROBLOX 0x005df250 FOLDED
template <>
bool TypedPropertyDescriptor<ContentId>::hasStringValue() const
{
	return true;
}

// FUNCTION: WEBSERVICE 0x100417d0 FOLDED
// FUNCTION: ROBLOX 0x005a8230 FOLDED
template <>
std::string TypedPropertyDescriptor<ContentId>::getStringValue(const DescribedBase* instance) const
{
	return StringConverter<ContentId>::convertToString(getValue(instance));
}

// FUNCTION: WEBSERVICE 0x10041850
// FUNCTION: ROBLOX 0x005a8580
template <>
boost::shared_ptr<Instance>& Value::convert<boost::shared_ptr<Instance> >()
{
	if (isType<void>()) {
		value = boost::shared_ptr<Instance>();
		_type = &Type::singleton<boost::shared_ptr<Instance> >();
	}

	if (isType<boost::shared_ptr<DescribedBase> >()) {
		boost::shared_ptr<DescribedBase>* described = boost::any_cast<boost::shared_ptr<DescribedBase> >(&value);
		if (described) {
			Instance* instance = dynamic_cast<Instance*>(described->get());
			if (instance == NULL) {
				throw std::runtime_error("Unable to cast value to Object");
			}

			value = shared_from(instance);
		}
		else {
			value = boost::shared_ptr<Instance>();
		}

		_type = &Type::singleton<boost::shared_ptr<Instance> >();
	}

	if (boost::shared_ptr<Instance>* instance = boost::any_cast<boost::shared_ptr<Instance> >(&value)) {
		return *instance;
	}

	throw std::runtime_error("Unable to cast value to Object");
}

// FUNCTION: WEBSERVICE 0x100421f0
// FUNCTION: ROBLOX 0x005a8890
template <>
EnumDesc<NormalId>::EnumDesc() : EnumDescriptor("NormalId", typeid(NormalId))
{
	addPair(NORM_Y, "Top");
	addPair(NORM_Y_NEG, "Bottom");
	addPair(NORM_Z, "Back");
	addPair(NORM_Z_NEG, "Front");
	addPair(NORM_X, "Right");
	addPair(NORM_X_NEG, "Left");
}

// FUNCTION: WEBSERVICE 0x100ff960 FOLDED
// FUNCTION: ROBLOX 0x005ac440 FOLDED
template <>
bool TypedPropertyDescriptor<ContentId>::setStringValue(DescribedBase* instance, const std::string& text) const
{
	ContentId value;
	if (StringConverter<ContentId>::convertToValue(text, value)) {
		setValue(instance, value);
		return true;
	}

	return false;
}

} // namespace Reflection
} // namespace RBX
