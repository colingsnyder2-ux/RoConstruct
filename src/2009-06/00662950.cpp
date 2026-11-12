// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/v8datamodel/Surfaces.cpp

// Candidate translation unit (score above; library headers required).
#include "v8datamodel/Surfaces.h"

#include "reflection/property.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/Controller.h"

#include <memory>

namespace RBX {

template <>
const Reflection::Type& Reflection::Type::singleton<Surface>();

// SIZE 0x18
template <int normalId>
class SurfaceDescriptor : public Reflection::PropertyDescriptor
{
public:
	SurfaceDescriptor(const char* name)
		: Reflection::PropertyDescriptor(
			  PartInstance::classDescriptor(),
			  Reflection::Type::singleton<Surface>(),
			  name,
			  "Data",
			  Reflection::PropertyDescriptor::LEGACY
		  )
	{
	}

	virtual bool equalValues(const Reflection::DescribedBase* a, const Reflection::DescribedBase* b) const
	{
		return false;
	}

	virtual bool isReadOnly() const { return false; }

	virtual void readValue(
		Reflection::DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
	) const
	{
		static_cast<PartInstance*>(instance)->getSurfaces()[static_cast<NormalId>(normalId)].readValue(element, binder);
	}

	virtual void writeValue(const Reflection::DescribedBase* instance, XmlElement* element) const {}

	virtual bool hasStringValue() const { return false; }

	virtual std::string getStringValue(const Reflection::DescribedBase* instance) const
	{
		return PropertyDescriptor::getStringValue(instance);
	}

	virtual bool setStringValue(Reflection::DescribedBase* instance, const std::string& value) const
	{
		hasStringValue();

		return false;
	}
};

// SIZE 0x0c
template <int normalId, class T, class Getter, class Setter>
class SurfaceGetSet : public Reflection::TypedPropertyDescriptor<T>::GetSet
{
public:
	SurfaceGetSet(Getter get, Setter set) : get(get), set(set) {}

	virtual bool isReadOnly() const { return false; }

	virtual T getValue(const Reflection::DescribedBase* instance) const
	{
		const Surfaces& surfaces = static_cast<const PartInstance*>(instance)->getSurfaces();

		return (surfaces[static_cast<NormalId>(normalId)].*get)();
	}

	virtual void setValue(Reflection::DescribedBase* instance, const T& value) const
	{
		Surfaces& surfaces = static_cast<PartInstance*>(instance)->getSurfaces();

		(surfaces[static_cast<NormalId>(normalId)].*set)(value);
	}

private:
	Getter get; // 0x04
	Setter set; // 0x08
};

// SIZE 0x1c
template <int normalId, class T>
class SurfacePropDescriptor : public Reflection::TypedPropertyDescriptor<T>
{
public:
	template <class Getter, class Setter>
	SurfacePropDescriptor(
		const char* name,
		const char* category,
		Getter get,
		Setter set,
		Reflection::PropertyDescriptor::Functionality flags = Reflection::PropertyDescriptor::STANDARD
	)
		: Reflection::TypedPropertyDescriptor<T>(
			  PartInstance::classDescriptor(),
			  name,
			  category,
			  std::auto_ptr<typename Reflection::TypedPropertyDescriptor<T>::GetSet>(
				  new SurfaceGetSet<normalId, T, Getter, Setter>(get, set)
			  ),
			  flags
		  )
	{
	}
};

// SIZE 0x20
template <int normalId, class T>
class SurfaceEnumPropDescriptor : public Reflection::EnumPropertyDescriptor
{
	std::auto_ptr<typename Reflection::TypedPropertyDescriptor<T>::GetSet> getset; // 0x1c

public:
	template <class Getter, class Setter>
	SurfaceEnumPropDescriptor(
		const char* name,
		const char* category,
		Getter get,
		Setter set,
		Reflection::PropertyDescriptor::Functionality flags = Reflection::PropertyDescriptor::STANDARD
	)
		: Reflection::EnumPropertyDescriptor(
			  PartInstance::classDescriptor(), Reflection::EnumDesc<T>::singleton(), name, category, flags
		  ),
		  getset(new SurfaceGetSet<normalId, T, Getter, Setter>(get, set))
	{
	}

	virtual bool isReadOnly() const { return getset->isReadOnly(); }

	T getValue(const Reflection::DescribedBase* instance) const { return getset->getValue(instance); }

	void setValue(Reflection::DescribedBase* instance, const T& value) const { getset->setValue(instance, value); }

	virtual bool equalValues(const Reflection::DescribedBase* a, const Reflection::DescribedBase* b) const
	{
		return getValue(a) == getValue(b);
	}

	virtual int getEnumValue(const Reflection::DescribedBase* instance) const { return getValue(instance); }

	virtual bool setEnumValue(Reflection::DescribedBase* instance, int intValue) const
	{
		if (Reflection::EnumDesc<T>::singleton().isValue(intValue)) {
			setValue(instance, static_cast<T>(intValue));
			return true;
		}
		else {
			return false;
		}
	}

	virtual unsigned int getIndexValue(const Reflection::DescribedBase* instance) const
	{
		return Reflection::EnumDesc<T>::singleton().convertToIndex(getValue(instance));
	}

	virtual bool setIndexValue(Reflection::DescribedBase* instance, unsigned int index) const
	{
		T value;

		if (Reflection::EnumDesc<T>::singleton().convertToValue(index, value)) {
			setValue(instance, value);
			return true;
		}
		else {
			return false;
		}
	}

	virtual bool hasStringValue() const { return true; }

	virtual std::string getStringValue(const Reflection::DescribedBase* instance) const
	{
		return Reflection::EnumDesc<T>::singleton().convertToString(getValue(instance));
	}

	virtual bool setStringValue(Reflection::DescribedBase* instance, const std::string& text) const
	{
		T value;

		if (Reflection::EnumDesc<T>::singleton().convertToValue(text, value)) {
			setValue(instance, value);
			return true;
		}
		else {
			return false;
		}
	}

	virtual bool setStringValue(Reflection::DescribedBase* instance, const Name& name) const // vtable+0x34
	{
		T value;

		if (Reflection::EnumDesc<T>::singleton().convertToValue(name, value)) {
			setValue(instance, value);
			return true;
		}
		else {
			return false;
		}
	}

	virtual void readValue(
		Reflection::DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder
	) const
	{
		if (!element->isXsiNil()) {
			if (element->isValueType<std::string>()) {
				std::string sValue;

				if (element->getValue(sValue)) {
					T e;

					if (Reflection::EnumDesc<T>::singleton().convertToValue(sValue, e)) {
						setValue(instance, e);
						return;
					}
				}
			}

			int value;

			if (element->getValue(value)) {
				setValue(instance, static_cast<T>(value));
			}
		}
	}

	virtual void writeValue(const Reflection::DescribedBase* instance, XmlElement* element) const
	{
		element->setValue(static_cast<int>(getValue(instance)));
	}
};

static SurfaceDescriptor<NORM_Y> desc_LegacyTop("Top");
static SurfaceDescriptor<NORM_Y_NEG> desc_LegacyBottom("Bottom");
static SurfaceDescriptor<NORM_X_NEG> desc_LegacyLeft("Back");
static SurfaceDescriptor<NORM_X> desc_LegacyRight("Front");
static SurfaceDescriptor<NORM_Z_NEG> desc_LegacyFront("Right");
static SurfaceDescriptor<NORM_Z> desc_LegacyBack("Left");

static SurfaceEnumPropDescriptor<NORM_Y, SurfaceType> desc_TopType(
	"TopSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType
);

static SurfaceEnumPropDescriptor<NORM_Y, Controller::InputType> desc_TopSurfaceInput(
	"TopSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput
);

static SurfacePropDescriptor<NORM_Y, float> desc_TopParamA(
	"TopParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA
);

static SurfacePropDescriptor<NORM_Y, float> desc_TopParamB(
	"TopParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB
);

static SurfaceEnumPropDescriptor<NORM_Y_NEG, SurfaceType> desc_BottomType(
	"BottomSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType
);

static SurfaceEnumPropDescriptor<NORM_Y_NEG, Controller::InputType> desc_BottomSurfaceInput(
	"BottomSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput
);

static SurfacePropDescriptor<NORM_Y_NEG, float> desc_BottomParamA(
	"BottomParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA
);

static SurfacePropDescriptor<NORM_Y_NEG, float> desc_BottomParamB(
	"BottomParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB
);

static SurfaceEnumPropDescriptor<NORM_X_NEG, SurfaceType> desc_LeftType(
	"LeftSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType
);

static SurfaceEnumPropDescriptor<NORM_X_NEG, Controller::InputType> desc_LeftSurfaceInput(
	"LeftSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput
);

static SurfacePropDescriptor<NORM_X_NEG, float> desc_LeftParamA(
	"LeftParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA
);

static SurfacePropDescriptor<NORM_X_NEG, float> desc_LeftParamB(
	"LeftParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB
);

static SurfaceEnumPropDescriptor<NORM_X, SurfaceType> desc_RightType(
	"RightSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType
);

static SurfaceEnumPropDescriptor<NORM_X, Controller::InputType> desc_RightSurfaceInput(
	"RightSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput
);

static SurfacePropDescriptor<NORM_X, float> desc_RightParamA(
	"RightParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA
);

static SurfacePropDescriptor<NORM_X, float> desc_RightParamB(
	"RightParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB
);

static SurfaceEnumPropDescriptor<NORM_Z_NEG, SurfaceType> desc_FrontType(
	"FrontSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType
);

static SurfaceEnumPropDescriptor<NORM_Z_NEG, Controller::InputType> desc_FrontSurfaceInput(
	"FrontSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput
);

static SurfacePropDescriptor<NORM_Z_NEG, float> desc_FrontParamA(
	"FrontParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA
);

static SurfacePropDescriptor<NORM_Z_NEG, float> desc_FrontParamB(
	"FrontParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB
);

static SurfaceEnumPropDescriptor<NORM_Z, SurfaceType> desc_BackType(
	"BackSurface", "Surface", &Surface::getSurfaceType, &Surface::setSurfaceType
);

static SurfaceEnumPropDescriptor<NORM_Z, Controller::InputType> desc_BackSurfaceInput(
	"BackSurfaceInput", "Surface Inputs", &Surface::getInput, &Surface::setSurfaceInput
);

static SurfacePropDescriptor<NORM_Z, float> desc_BackParamA(
	"BackParamA", "Surface Inputs", &Surface::getParamA, &Surface::setParamA
);

static SurfacePropDescriptor<NORM_Z, float> desc_BackParamB(
	"BackParamB", "Surface Inputs", &Surface::getParamB, &Surface::setParamB
);

// FUNCTION: WEBSERVICE 0x10100bd0
// FUNCTION: ROBLOX 0x005ddff0
const bool Surfaces::isSurfaceDescriptor(const Reflection::PropertyDescriptor& desc)
{
	if (&desc == &desc_TopType) {
		return true;
	}

	if (&desc == &desc_BottomType) {
		return true;
	}

	if (&desc == &desc_LeftType) {
		return true;
	}

	if (&desc == &desc_RightType) {
		return true;
	}

	if (&desc == &desc_FrontType) {
		return true;
	}

	return &desc == &desc_BackType;
}

// FUNCTION: WEBSERVICE 0x10100c10
// FUNCTION: ROBLOX 0x005de030
const Reflection::PropertyDescriptor& Surfaces::getSurfaceType(NormalId face) const
{
	switch (face) {
	default:
		return desc_TopType;
	case NORM_Y_NEG:
		return desc_BottomType;
	case NORM_Z:
		return desc_BackType;
	case NORM_Z_NEG:
		return desc_FrontType;
	case NORM_X:
		return desc_RightType;
	case NORM_X_NEG:
		return desc_LeftType;
	}
}

// FUNCTION: WEBSERVICE 0x10100c70
// FUNCTION: ROBLOX 0x005de090
const Reflection::PropertyDescriptor& Surfaces::getSurfaceInput(NormalId face) const
{
	switch (face) {
	default:
		return desc_TopSurfaceInput;
	case NORM_Y_NEG:
		return desc_BottomSurfaceInput;
	case NORM_Z:
		return desc_BackSurfaceInput;
	case NORM_Z_NEG:
		return desc_FrontSurfaceInput;
	case NORM_X:
		return desc_RightSurfaceInput;
	case NORM_X_NEG:
		return desc_LeftSurfaceInput;
	}
}

// FUNCTION: WEBSERVICE 0x10100cd0
// FUNCTION: ROBLOX 0x005de0f0
const Reflection::PropertyDescriptor& Surfaces::getParamA(NormalId face) const
{
	switch (face) {
	default:
		return desc_TopParamA;
	case NORM_Y_NEG:
		return desc_BottomParamA;
	case NORM_Z:
		return desc_BackParamA;
	case NORM_Z_NEG:
		return desc_FrontParamA;
	case NORM_X:
		return desc_RightParamA;
	case NORM_X_NEG:
		return desc_LeftParamA;
	}
}

// FUNCTION: WEBSERVICE 0x10100d30
// FUNCTION: ROBLOX 0x005de150
const Reflection::PropertyDescriptor& Surfaces::getParamB(NormalId face) const
{
	switch (face) {
	default:
		return desc_TopParamB;
	case NORM_Y_NEG:
		return desc_BottomParamB;
	case NORM_Z:
		return desc_BackParamB;
	case NORM_Z_NEG:
		return desc_FrontParamB;
	case NORM_X:
		return desc_RightParamB;
	case NORM_X_NEG:
		return desc_LeftParamB;
	}
}

// FUNCTION: WEBSERVICE 0x10100d90
// FUNCTION: ROBLOX 0x005de1b0
Surfaces::Surfaces(PartInstance* container)
	: Top(container, NORM_Y), Bottom(container, NORM_Y_NEG), Left(container, NORM_X_NEG), Right(container, NORM_X),
	  Front(container, NORM_Z_NEG), Back(container, NORM_Z)
{
}

// FUNCTION: WEBSERVICE 0x10100de0
// FUNCTION: ROBLOX 0x005de200
const Surface& Surfaces::operator[](NormalId normalId) const
{
	switch (normalId) {
	case NORM_Y_NEG:
		return Bottom;
	case NORM_Z:
		return Back;
	case NORM_Z_NEG:
		return Front;
	case NORM_X:
		return Right;
	case NORM_X_NEG:
		return Left;
	default:
		return Top;
	}
}

Surface& Surfaces::operator[](NormalId normalId)
{
	switch (normalId) {
	case NORM_Y_NEG:
		return Bottom;
	case NORM_Z:
		return Back;
	case NORM_Z_NEG:
		return Front;
	case NORM_X:
		return Right;
	case NORM_X_NEG:
		return Left;
	default:
		return Top;
	}
}

// FUNCTION: WEBSERVICE 0x10100e30
// FUNCTION: ROBLOX 0x005de250
const bool Surfaces::isStandardPart() const
{
	return Bottom.getSurfaceType() == INLET && Front.getSurfaceType() == NO_SURFACE &&
		   Back.getSurfaceType() == NO_SURFACE && Left.getSurfaceType() == NO_SURFACE &&
		   Right.getSurfaceType() == NO_SURFACE;
}

// FUNCTION: WEBSERVICE 0x10100ea0
// FUNCTION: ROBLOX 0x005de2c0
template <>
const Reflection::Type& Reflection::Type::singleton<Surface>()
{
	static Type type("Surface", typeid(Surface), "Complex");

	return type;
}

} // namespace RBX
