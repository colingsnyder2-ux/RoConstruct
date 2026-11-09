// from server: 100% by EspClaude
// from server: 86% by EspClaude
// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client roc_espclaude_30cca9b2e8392a0d.cpp

// Candidate translation unit (score above; library headers required).
#ifndef REFLECTION_PROPERTY_H
#define REFLECTION_PROPERTY_H

#include "decomp.h"
#include "reflection/enumconverter.h"
#include "reflection/member.h"
#include "reflection/type.h"

#include <memory>
#include <string>
#include <typeinfo>

class XmlElement;

namespace RBX {

class IReferenceBinder;

extern const char* const category_Part;

namespace Reflection {

class ConstProperty;
class DescribedBase;
class Property;
class EnumDescriptor;

// SIZE 0x18
class __declspec(novtable) PropertyDescriptor : public MemberDescriptor
{
public:
	enum Functionality
	{
		LEGACY = 0,
		UI = 1,
		STREAMING = 4,
		STANDARD = 5,
	};

	typedef ConstProperty ConstMemberType;
	typedef Property MemberType;

	virtual bool isReadOnly() const = 0;                                                      // vtable+0x04
	virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const = 0;       // vtable+0x08
	virtual bool hasStringValue() const = 0;                                                  // vtable+0x0c
	virtual std::string getStringValue(const DescribedBase* instance) const = 0;              // vtable+0x10
	virtual bool setStringValue(DescribedBase* instance, const std::string& value) const = 0; // vtable+0x14
	virtual void read(
		DescribedBase* instance,
		const XmlElement* element,
		IReferenceBinder& binder
	) const; // vtable+0x18

	XmlElement* write(const DescribedBase* instance, bool ignoreWriteProtection) const;

	bool isPublic() const { return bIsPublic; }
	bool canStreamWrite() const { return bCanStreamWrite; }

	unsigned int bIsPublic : 1;       // 0x10
	unsigned int bCanStreamWrite : 1; // 0x10
	unsigned int bExe2009 : 1;

	const Type& type; // 0x14

protected:
	PropertyDescriptor(
		ClassDescriptor& classDescriptor,
		const Type& type,
		const char* name,
		const char* category,
		Functionality flags
	);

private:
	virtual void writeValue(const DescribedBase* instance, XmlElement* element) const = 0; // vtable+0x1c
	virtual void readValue(
		DescribedBase* instance,
		const XmlElement* element,
		IReferenceBinder& binder
	) const = 0; // vtable+0x20
};

DECOMP_SIZE_ASSERT(PropertyDescriptor, 0x18)

inline std::string PropertyDescriptor::getStringValue(const DescribedBase* instance) const
{
	hasStringValue();

	return "";
}

// SIZE 0x1c
template <class T>
class TypedPropertyDescriptor : public PropertyDescriptor
{
public:
	// SIZE 0x04
	class __declspec(novtable) GetSet
	{
	public:
		virtual bool isReadOnly() const = 0;                                      // vtable+0x00
		virtual T getValue(const DescribedBase* instance) const = 0;              // vtable+0x04
		virtual void setValue(DescribedBase* instance, const T& value) const = 0; // vtable+0x08
	};

	T getValue(const DescribedBase* instance) const { return getset->getValue(instance); }

	void setValue(DescribedBase* instance, const T& value) const { getset->setValue(instance, value); }

	virtual bool isReadOnly() const { return getset->isReadOnly(); }

	virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const
	{
		return getValue(a) == getValue(b);
	}

	virtual bool hasStringValue() const { return false; }

	virtual std::string getStringValue(const DescribedBase* instance) const
	{
		STUB(0x10094120);
		return std::string();
	}

	virtual bool setStringValue(DescribedBase* instance, const std::string& value) const
	{
		STUB(0x100941a0);
		return false;
	}

protected:
	TypedPropertyDescriptor(
		ClassDescriptor& classDescriptor,
		const char* name,
		const char* category,
		std::auto_ptr<GetSet> getset,
		Functionality flags
	)
		: PropertyDescriptor(classDescriptor, Type::singleton<T>(), name, category, flags), getset(getset)
	{
	}

	TypedPropertyDescriptor(
		ClassDescriptor& classDescriptor,
		const Type& type,
		const char* name,
		const char* category,
		std::auto_ptr<GetSet> getset,
		Functionality flags
	)
		: PropertyDescriptor(classDescriptor, type, name, category, flags), getset(getset)
	{
	}

private:
	virtual void writeValue(const DescribedBase* instance, XmlElement* element) const { STUB(0x10094410); }

	virtual void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
	{
		STUB(0x10094420);
	}

protected:
	std::auto_ptr<GetSet> getset; // 0x18
};

// SIZE 0x1c
class __declspec(novtable) EnumPropertyDescriptor : public PropertyDescriptor
{
public:
	const EnumDescriptor& enumDescriptor; // 0x18

protected:
	EnumPropertyDescriptor(
		ClassDescriptor& classDescriptor,
		const EnumDescriptor& enumDescriptor,
		const char* name,
		const char* category,
		Functionality functionality
	)
		: PropertyDescriptor(classDescriptor, enumDescriptor, name, category, functionality),
		  enumDescriptor(enumDescriptor)
	{
	}
};

DECOMP_SIZE_ASSERT(EnumPropertyDescriptor, 0x1c)

// SIZE 0x18
class __declspec(novtable) RefPropertyDescriptor : public PropertyDescriptor
{
public:
	virtual DescribedBase* getRefValue(const DescribedBase* instance) const = 0;       // vtable+0x24
	virtual void setRefValue(DescribedBase* instance, DescribedBase* value) const = 0; // vtable+0x28

protected:
	RefPropertyDescriptor(
		ClassDescriptor& classDescriptor,
		const Type& type,
		const char* name,
		const char* category,
		Functionality functionality
	)
		: PropertyDescriptor(classDescriptor, type, name, category, functionality)
	{
	}

	virtual bool hasStringValue() const { return false; }

	virtual std::string getStringValue(const DescribedBase* instance) const
	{
		return PropertyDescriptor::getStringValue(instance);
	}

	virtual bool setStringValue(DescribedBase* instance, const std::string& value) const
	{
		hasStringValue();

		return false;
	}
};

DECOMP_SIZE_ASSERT(RefPropertyDescriptor, 0x18)

// SIZE 0x1c
template <class Class, class T>
class PropDescriptor : public TypedPropertyDescriptor<T>
{
public:
	template <class Getter, class Setter>
	class GetSetImpl : public TypedPropertyDescriptor<T>::GetSet
	{
	public:
		GetSetImpl(Getter get, Setter set) : get(get), set(set) {}

		virtual bool isReadOnly() const { return false; }

		virtual T getValue(const DescribedBase* object) const
		{
			const Class* instance = static_cast<const Class*>(object);
			return (instance->*get)();
		}

		virtual void setValue(DescribedBase* object, const T& value) const
		{
			(static_cast<Class*>(object)->*set)(value);
		}

	private:
		Getter get;
		Setter set;
	};

	// clang-format off
	// FUNCTION: WEBSERVICE 0x100433c0
	// RBX::Reflection::TypedPropertyDescriptor<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >::TypedPropertyDescriptor<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
	// FUNCTION: WEBSERVICE 0x10043430
	// RBX::Reflection::TypedPropertyDescriptor<G3D::Color3>::TypedPropertyDescriptor<G3D::Color3>
	// FUNCTION: WEBSERVICE 0x100434e0
	// RBX::Reflection::TypedPropertyDescriptor<float>::TypedPropertyDescriptor<float>
	// FUNCTION: WEBSERVICE 0x10048bd0
	// RBX::Reflection::TypedPropertyDescriptor<bool>::TypedPropertyDescriptor<bool>
	// FUNCTION: WEBSERVICE 0x1007deb0
	// RBX::Reflection::TypedPropertyDescriptor<int>::TypedPropertyDescriptor<int>
	// TEMPLATE: WEBSERVICE 0x10094df0
	// RBX::Reflection::BoundProp<RBX::TextureId,1>::BoundProp<RBX::TextureId,1><RBX::Sky>
	// TEMPLATE: WEBSERVICE 0x10094ec0
	// RBX::Reflection::BoundProp<int,1>::BoundProp<int,1><RBX::Sky>
	// TEMPLATE: WEBSERVICE 0x10094f90
	// RBX::Reflection::BoundProp<bool,1>::BoundProp<bool,1><RBX::Sky>
	// FUNCTION: WEBSERVICE 0x100996a0
	// RBX::Reflection::PropDescriptor<RBX::PVInstance,bool>::getset<bool (__thiscall RBX::PVInstance::*)(void)const ,void (__thiscall RBX::PVInstance::*)(bool)>
	// STUB: WEBSERVICE 0x10094c50
	// RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>::TypedPropertyDescriptor<RBX::TextureId>
	// FUNCTION: WEBSERVICE 0x1009ba30
	// RBX::Reflection::TypedPropertyDescriptor<RBX::BrickColor>::TypedPropertyDescriptor<RBX::BrickColor>
	// FUNCTION: WEBSERVICE 0x1009bce0
	// RBX::Reflection::PropDescriptor<RBX::PartInstance,RBX::BrickColor>::getset<RBX::BrickColor (__thiscall RBX::PartInstance::*)(void)const ,void (__thiscall RBX::PartInstance::*)(RBX::BrickColor)>
	// FUNCTION: WEBSERVICE 0x1009bd50
	// RBX::Reflection::PropDescriptor<RBX::PartInstance,float>::getset<float (__thiscall RBX::PartInstance::*)(void)const ,void (__thiscall RBX::PartInstance::*)(float)>
	// FUNCTION: WEBSERVICE 0x1009bdc0
	// RBX::Reflection::PropDescriptor<RBX::PartInstance,bool>::getset<bool (__thiscall RBX::PartInstance::*)(void)const ,void (__thiscall RBX::PartInstance::*)(bool)>
	// FUNCTION: WEBSERVICE 0x100a15f0
	// RBX::Reflection::PropDescriptor<RBX::Humanoid,float>::getset<float (__thiscall RBX::Humanoid::*)(void)const ,void (__thiscall RBX::Humanoid::*)(float const &)>
	// FUNCTION: WEBSERVICE 0x100a1660
	// RBX::Reflection::PropDescriptor<RBX::Humanoid,bool>::getset<bool (__thiscall RBX::Humanoid::*)(void)const ,void (__thiscall RBX::Humanoid::*)(bool)>
	// FUNCTION: WEBSERVICE 0x100a16d0
	// RBX::Reflection::PropDescriptor<RBX::Humanoid,float>::getset<float (__thiscall RBX::Humanoid::*)(void)const ,void (__thiscall RBX::Humanoid::*)(float)>
	// TEMPLATE: WEBSERVICE 0x100b36d0
	// RBX::Reflection::PropDescriptor<RBX::DebugSettings,bool>::getset<bool (__thiscall RBX::DebugSettings::*)(void)const ,void (__thiscall RBX::DebugSettings::*)(bool)>
	// TEMPLATE: WEBSERVICE 0x100be0e0
	// RBX::Reflection::PropDescriptor<RBX::Team,int>::getset<int (__thiscall RBX::Team::*)(void)const ,void (__thiscall RBX::Team::*)(int)>
	// TEMPLATE: WEBSERVICE 0x100be140
	// RBX::Reflection::PropDescriptor<RBX::Team,RBX::BrickColor>::getset<RBX::BrickColor (__thiscall RBX::Team::*)(void)const ,void (__thiscall RBX::Team::*)(RBX::BrickColor)>
	// TEMPLATE: WEBSERVICE 0x100be1a0
	// RBX::Reflection::PropDescriptor<RBX::Team,bool>::getset<bool (__thiscall RBX::Team::*)(void)const ,void (__thiscall RBX::Team::*)(bool)>
	// FUNCTION: WEBSERVICE 0x100ca3f0
	// RBX::Reflection::PropDescriptor<RBX::Tool,int>::GetSetImpl<int (__thiscall RBX::Tool::*)(void)const ,void (__thiscall RBX::Tool::*)(int)>::getValue
	// TEMPLATE: WEBSERVICE 0x100ca830
	// RBX::Reflection::PropDescriptor<RBX::Tool,int>::getset<int (__thiscall RBX::Tool::*)(void)const ,void (__thiscall RBX::Tool::*)(int)>
	// FUNCTION: WEBSERVICE 0x100cd3c0
	// RBX::Reflection::PropDescriptor<RBX::Flag,RBX::BrickColor>::GetSetImpl<RBX::BrickColor (__thiscall RBX::Flag::*)(void)const ,void (__thiscall RBX::Flag::*)(RBX::BrickColor)>::getValue
	// STUB: WEBSERVICE 0x100cd400
	// RBX::Reflection::PropDescriptor<RBX::Flag,RBX::BrickColor>::GetSetImpl<RBX::BrickColor (__thiscall RBX::Flag::*)(void)const ,void (__thiscall RBX::Flag::*)(RBX::BrickColor)>::setValue
	// TEMPLATE: WEBSERVICE 0x100cd6e0
	// RBX::Reflection::PropDescriptor<RBX::Flag,RBX::BrickColor>::getset<RBX::BrickColor (__thiscall RBX::Flag::*)(void)const ,void (__thiscall RBX::Flag::*)(RBX::BrickColor)>
	// TEMPLATE: WEBSERVICE 0x100d7fa0
	// RBX::Reflection::PropDescriptor<RBX::Motor,float>::getset<float (__thiscall RBX::Motor::*)(void)const ,void (__thiscall RBX::Motor::*)(float)>
	// STUB: WEBSERVICE 0x100dc050
	// RBX::Reflection::PropDescriptor<RBX::Accoutrement,int>::getset<int (__thiscall RBX::Accoutrement::*)(void)const ,void (__thiscall RBX::Accoutrement::*)(int)>
	// TEMPLATE: WEBSERVICE 0x100e4a40
	// RBX::Reflection::PropDescriptor<RBX::VelocityMotor,float>::getset<float (__thiscall RBX::VelocityMotor::*)(void)const ,void (__thiscall RBX::VelocityMotor::*)(float)>
	// TEMPLATE: WEBSERVICE 0x100ee870
	// RBX::Reflection::PropDescriptor<RBX::Message,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >::getset<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const & (__thiscall RBX::Message::*)(void)const ,void (__thiscall RBX::Message::*)(std::basic_string<char,std::char_traits<char>,std::allocator<char> > const &)>
	// FUNCTION: WEBSERVICE 0x100fdac0
	// RBX::Reflection::PropDescriptor<RBX::SpawnLocation,RBX::BrickColor>::getset<RBX::BrickColor (__thiscall RBX::SpawnLocation::*)(void)const ,void (__thiscall RBX::SpawnLocation::*)(RBX::BrickColor)>
	// TEMPLATE: WEBSERVICE 0x100ff7d0
	// RBX::Reflection::PropDescriptor<RBX::Decal,float>::getset<float (__thiscall RBX::Decal::*)(void)const ,void (__thiscall RBX::Decal::*)(float)>
	// TEMPLATE: WEBSERVICE 0x100ff830
	// RBX::Reflection::PropDescriptor<RBX::Texture,float>::getset<float (__thiscall RBX::Texture::*)(void)const ,void (__thiscall RBX::Texture::*)(float)>
	// TEMPLATE: WEBSERVICE 0x100ffc90
	// RBX::Reflection::PropDescriptor<RBX::Decal,RBX::TextureId>::PropDescriptor<RBX::Decal,RBX::TextureId><RBX::TextureId (__thiscall RBX::Decal::*)(void)const ,void (__thiscall RBX::Decal::*)(RBX::TextureId)>
	// TEMPLATE: WEBSERVICE 0x1018c700
	// RBX::Reflection::PropDescriptor<RBX::Network::Player,bool>::getset<bool (__thiscall RBX::Network::Player::*)(void)const ,void (__thiscall RBX::Network::Player::*)(bool)>
	// TEMPLATE: WEBSERVICE 0x1018ce60
	// RBX::Reflection::PropDescriptor<RBX::Network::Player,RBX::BrickColor>::getset<RBX::BrickColor (__thiscall RBX::Network::Player::*)(void)const ,void (__thiscall RBX::Network::Player::*)(RBX::BrickColor)>
	// TEMPLATE: WEBSERVICE 0x10191910
	// RBX::Reflection::PropDescriptor<RBX::Network::Players,int>::getset<int (__thiscall RBX::Network::Players::*)(void)const ,void (__thiscall RBX::Network::Players::*)(int)>
	// clang-format on
	template <class Getter, class Setter>
	static std::auto_ptr<typename TypedPropertyDescriptor<T>::GetSet> getset(Getter get, Setter set)
	{
		return std::auto_ptr<typename TypedPropertyDescriptor<T>::GetSet>(new GetSetImpl<Getter, Setter>(get, set));
	}

	// clang-format off
	// STUB: WEBSERVICE 0x1012d340
	// RBX::Reflection::EnumPropDescriptor<RBX::SpecialShape,enum RBX::SpecialShape::MeshType>::EnumPropDescriptor<RBX::SpecialShape,enum RBX::SpecialShape::MeshType><enum RBX::SpecialShape::MeshType const (__thiscall RBX::SpecialShape::*)(void)const ,void (__thiscall RBX::SpecialShape::*)(enum RBX::SpecialShape::MeshType)>
	// STUB: WEBSERVICE 0x100b46b0
	// RBX::Reflection::EnumPropDescriptor<RBX::DebugSettings,enum RBX::Debugable::AssertAction>::EnumPropDescriptor<RBX::DebugSettings,enum RBX::Debugable::AssertAction><enum RBX::Debugable::AssertAction (__thiscall RBX::DebugSettings::*)(void)const ,void (__thiscall RBX::DebugSettings::*)(enum RBX::Debugable::AssertAction)>
	// STUB: WEBSERVICE 0x100b48e0
	// RBX::Reflection::EnumPropDescriptor<RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting>::EnumPropDescriptor<RBX::DebugSettings,enum RBX::DebugSettings::ErrorReporting><enum RBX::DebugSettings::ErrorReporting (__thiscall RBX::DebugSettings::*)(void)const ,void (__thiscall RBX::DebugSettings::*)(enum RBX::DebugSettings::ErrorReporting)>
	// TEMPLATE: WEBSERVICE 0x100b4610
	// RBX::Reflection::PropDescriptor<RBX::DebugSettings,bool>::PropDescriptor<RBX::DebugSettings,bool><bool (__thiscall RBX::DebugSettings::*)(void)const ,void (__thiscall RBX::DebugSettings::*)(bool)>
	// FUNCTION: WEBSERVICE 0x100ffd30
	// RBX::Reflection::PropDescriptor<RBX::Decal,float>::PropDescriptor<RBX::Decal,float><float (__thiscall RBX::Decal::*)(void)const ,void (__thiscall RBX::Decal::*)(float)>
	// TEMPLATE: WEBSERVICE 0x100ffdd0
	// RBX::Reflection::PropDescriptor<RBX::Texture,float>::PropDescriptor<RBX::Texture,float><float (__thiscall RBX::Texture::*)(void)const ,void (__thiscall RBX::Texture::*)(float)>
	// clang-format on
	template <class Getter, class Setter>
	PropDescriptor(
		const char* name,
		const char* category,
		Getter get,
		Setter set,
		typename PropertyDescriptor::Functionality flags = PropertyDescriptor::STANDARD
	)
		: TypedPropertyDescriptor<T>(Class::classDescriptor(), name, category, getset(get, set), flags)
	{
	}
};

// SIZE 0x1c
template <class T, int bound>
class BoundProp : public TypedPropertyDescriptor<T>
{
public:
	// SIZE 0x18
	template <class Class>
	class BoundPropGetSet : public TypedPropertyDescriptor<T>::GetSet
	{
	public:
		BoundPropGetSet(BoundProp<T, bound>* desc, T Class::* member, void (Class::*changed)())
			: desc(desc), member(member), changed(changed)
		{
		}

		virtual bool isReadOnly() const { return false; }

		virtual T getValue(const DescribedBase* instance) const { return static_cast<const Class*>(instance)->*member; }

		virtual void setValue(DescribedBase* instance, const T& value) const
		{
			Class* object = static_cast<Class*>(instance);

			if (object->*member != value) {
				object->*member = value;

				if (changed != NULL) {
					(object->*changed)();
				}

				object->raisePropertyChanged(*desc);
			}
		}

	private:
		BoundProp<T, bound>* desc; // 0x04
		T Class::* member;         // 0x08
		void (Class::*changed)();  // 0x10
	};

	template <class Class>
	BoundProp(
		const char* name,
		const char* category,
		T Class::* member,
		typename PropertyDescriptor::Functionality flags = PropertyDescriptor::STANDARD
	)
		: TypedPropertyDescriptor<T>(
			  Class::classDescriptor(),
			  name,
			  category,
			  std::auto_ptr<typename TypedPropertyDescriptor<T>::GetSet>(),
			  flags
		  )
	{
		this->getset.reset(new BoundPropGetSet<Class>(this, member, NULL));
	}
};

// SIZE 0x20
template <class Class, class T>
class EnumPropDescriptor : public EnumPropertyDescriptor
{
public:
	// SIZE 0x04
	class __declspec(novtable) GetSet
	{
	public:
		virtual T getValue(const DescribedBase* instance) const = 0;              // vtable+0x00
		virtual void setValue(DescribedBase* instance, const T& value) const = 0; // vtable+0x04
	};

	template <class Getter, class Setter>
	class GetSetImpl : public GetSet
	{
	public:
		GetSetImpl(Getter getter, Setter setter) : getter(getter), setter(setter) {}

		virtual T getValue(const DescribedBase* instance) const
		{
			return (static_cast<const Class*>(instance)->*getter)();
		}

		virtual void setValue(DescribedBase* instance, const T& value) const
		{
			(static_cast<Class*>(instance)->*setter)(value);
		}

	private:
		Getter getter; // 0x04
		Setter setter; // 0x10
	};

	template <class Getter, class Setter>
	EnumPropDescriptor(
		const char* name,
		const char* category,
		Getter getter,
		Setter setter,
		typename PropertyDescriptor::Functionality functionality = PropertyDescriptor::STANDARD
	)
		: EnumPropertyDescriptor(Class::classDescriptor(), EnumDesc<T>::singleton(), name, category, functionality),
		  getset(new GetSetImpl<Getter, Setter>(getter, setter))
	{
	}

	virtual bool isReadOnly() const { return false; }

	virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const
	{
		return getset->getValue(a) == getset->getValue(b);
	}

	virtual bool hasStringValue() const { return true; }

	virtual std::string getStringValue(const DescribedBase* instance) const
	{
		STUB(0x10094440);
		return std::string();
	}

	virtual bool setStringValue(DescribedBase* instance, const std::string& value) const
	{
		STUB(0x10094450);
		return false;
	}

private:
	virtual void writeValue(const DescribedBase* instance, XmlElement* element) const { STUB(0x10094460); }

	virtual void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
	{
		STUB(0x10094470);
	}

	std::auto_ptr<GetSet> getset; // 0x1c
};

// SIZE 0x08
class ConstProperty
{
public:
	ConstProperty(const ConstProperty& other) : descriptor(other.descriptor), instance(other.instance) {}
	ConstProperty(const PropertyDescriptor* descriptor, const DescribedBase* instance)
		: descriptor(descriptor), instance(instance)
	{
	}

	// clang-format off
	// TEMPLATE: WEBSERVICE 0x100ab2e0
	// RBX::Reflection::ConstProperty::getValue<bool>
	// TEMPLATE: WEBSERVICE 0x100ab340
	// RBX::Reflection::ConstProperty::getValue<float>
	// TEMPLATE: WEBSERVICE 0x100ab610
	// RBX::Reflection::ConstProperty::getValue<int>
	// TEMPLATE: WEBSERVICE 0x100ab670
	// RBX::Reflection::ConstProperty::getValue<double>
	// TEMPLATE: WEBSERVICE 0x100ab8d0
	// RBX::Reflection::ConstProperty::getValue<RBX::BrickColor>
	// clang-format on
	template <class T>
	T getValue() const
	{
		const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(descriptor);

		if (typed == NULL) {
#if defined(_MSC_VER) && _MSC_VER <= 1400
			throw std::bad_cast("bad cast");
#else
			throw std::bad_cast();
#endif
		}

		return typed->getValue(instance);
	}

	const DescribedBase* getInstance() const { return instance; }

	const PropertyDescriptor& getDescriptor() const { return *descriptor; }

	std::string getStringValue() const { return descriptor->getStringValue(instance); }

protected:
	const PropertyDescriptor* descriptor; // 0x00
	const DescribedBase* instance;        // 0x04
};

DECOMP_SIZE_ASSERT(ConstProperty, 0x08)

// SIZE 0x08
class Property : public ConstProperty
{
public:
	Property(const Property& other) : ConstProperty(other) {}

	Property(const PropertyDescriptor* descriptor, DescribedBase* instance) : ConstProperty(descriptor, instance) {}

	DescribedBase* getInstance() const { return const_cast<DescribedBase*>(instance); }

	// clang-format off
	// STUB: WEBSERVICE 0x100ab3a0
	// RBX::Reflection::Property::setValue<bool>
	// STUB: WEBSERVICE 0x100ab400
	// RBX::Reflection::Property::setValue<float>
	// STUB: WEBSERVICE 0x100aba10
	// RBX::Reflection::Property::setValue<int>
	// STUB: WEBSERVICE 0x100abb90
	// RBX::Reflection::Property::setValue<G3D::Vector3>
	// STUB: WEBSERVICE 0x100abbf0
	// RBX::Reflection::Property::setValue<G3D::CoordinateFrame>
	// STUB: WEBSERVICE 0x100abc50
	// RBX::Reflection::Property::setValue<G3D::Color3>
	// STUB: WEBSERVICE 0x100abcb0
	// RBX::Reflection::Property::setValue<RBX::BrickColor>
	// clang-format on
	template <class T>
	void setValue(const T& value)
	{
		const TypedPropertyDescriptor<T>* typed = dynamic_cast<const TypedPropertyDescriptor<T>*>(descriptor);

		if (typed == NULL) {
#if defined(_MSC_VER) && _MSC_VER <= 1400
			throw std::bad_cast("bad cast");
#else
			throw std::bad_cast();
#endif
		}

		typed->setValue(getInstance(), value);
	}
};

DECOMP_SIZE_ASSERT(Property, 0x08)

} // namespace Reflection
} // namespace RBX

#endif // REFLECTION_PROPERTY_H

#include "reflection/enumconverter.h"
#include "reflection/object.h"
#include "v8xml/XmlElement.h"

namespace RBX {
namespace Reflection {

PropertyDescriptor::PropertyDescriptor(
	ClassDescriptor& classDescriptor,
	const Type& type,
	const char* name,
	const char* category,
	Functionality flags
)
	: MemberDescriptor(classDescriptor, name, category), type(type), bIsPublic(flags), bCanStreamWrite(flags >> 1), bExe2009(flags >> 2)
{
	classDescriptor.MemberDescriptorContainer<PropertyDescriptor>::declare(this);
}

} // namespace Reflection
} // namespace RBX
