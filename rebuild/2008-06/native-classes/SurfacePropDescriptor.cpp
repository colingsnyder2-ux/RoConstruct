// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 v8datamodel/Surfaces.cpp per-face property templates (RTTI names): SurfaceGetSet<id, Type, Get, Set>,
// SurfaceDescriptor<id>, SurfacePropDescriptor<id, Type>, SurfaceEnumPropDescriptor<id, Enum>.
#undef _RELEASEASSERT
#include <stdexcept>
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"
#include "reflection/reflection.h"
namespace RBX {
	// 005ecc00. The templates below sit in the same translation unit and inline it (getValue 005ecd90 adds the face
	// offset to the Surfaces* with no call).
	Surface& Surfaces::operator[](NormalId face)
	{
		switch (face)
		{
		case NORM_Y_NEG: return Bottom;
		case NORM_Z: return Back;
		case NORM_Z_NEG: return Front;
		case NORM_X: return Right;
		case NORM_X_NEG: return Left;
		default: return Top;
		}
	}

	template<NormalId id, typename Type, typename GetFunction, typename SetFunction>
	class SurfaceGetSet : public Reflection::TypedPropertyDescriptor<Type>::GetSet
	{
	private:
		GetFunction get;
		SetFunction set;

	public:
		SurfaceGetSet(GetFunction g, SetFunction s)
			: get(g),
			  set(s)
		{
		}

		virtual bool isReadOnly() const
		{
			return false;
		}
		virtual bool isWriteOnly() const
		{
			return false;
		}
		virtual Type getValue(const Reflection::DescribedBase* instance) const
		{
			PartInstance* o = (PartInstance*)instance;
			return (o->getSurfaces()[id].*get)();
		}
		virtual void setValue(Reflection::DescribedBase* instance, const Type& value) const
		{
			PartInstance* o = (PartInstance*)instance;
			(o->getSurfaces()[id].*set)(value);
		}
	};

	// vftable 00840374 (id 1): dtor, isReadOnly 0060a2f0 (false), isWriteOnly 00565950 (true), equalValues 005eed40,
	// 005eed50 / 005eee80 throw std::runtime_error, hasStringValue 0060a2f0, getStringValue 005eecf0,
	// setStringValue 005eedf0, read 0056be00 (base), writeValue 00458e90 (empty), readValue 005eecc0.
	template<NormalId id>
	class SurfaceDescriptor : public Reflection::PropertyDescriptor
	{
	public:
		SurfaceDescriptor(const char* name)
			: PropertyDescriptor(PartInstance::classDescriptor(), Reflection::Type::singleton<Surface>(), name, "Data", LEGACY)
		{
		}

		virtual bool isReadOnly() const
		{
			return false;
		}
		virtual bool isWriteOnly() const
		{
			return true;
		}
		virtual bool equalValues(const Reflection::DescribedBase* a, const Reflection::DescribedBase* b) const
		{
			return false;
		}
		virtual void getVariant(const Reflection::DescribedBase* instance, Reflection::Value& value) const
		{
			throw std::runtime_error("SurfaceDescriptor::set not implemented");
		}
		virtual void setVariant(Reflection::DescribedBase* instance, const Reflection::Value& value) const
		{
			throw std::runtime_error("SurfaceDescriptor::get not implemented");
		}
		virtual bool hasStringValue() const
		{
			return false;
		}
		virtual std::string getStringValue(const Reflection::DescribedBase* instance) const
		{
			return PropertyDescriptor::getStringValue(instance);
		}
		virtual bool setStringValue(Reflection::DescribedBase* instance, const std::string& text) const
		{
			return PropertyDescriptor::setStringValue(instance, text);
		}
		virtual void readValue(Reflection::DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			static_cast<PartInstance*>(instance)->getSurfaces()[id].readValue(element, binder);
		}
		virtual void writeValue(const Reflection::DescribedBase* instance, XmlElement* element) const
		{
		}
	};

	template<NormalId id, typename Type>
	class SurfacePropDescriptor : public Reflection::TypedPropertyDescriptor<Type>
	{
	public:
		template<typename GetFunction, typename SetFunction>
		SurfacePropDescriptor(const char* name, const char* category, GetFunction get, SetFunction set, Functionality flags)
			: Reflection::TypedPropertyDescriptor<Type>::TypedPropertyDescriptor(PartInstance::classDescriptor(), name, category,
			  std::auto_ptr<Reflection::TypedPropertyDescriptor<Type>::GetSet>(new SurfaceGetSet<id, Type, GetFunction, SetFunction>(get, set)), flags)
		{
		}
	};

	template<NormalId id, typename Enum>
	class SurfaceEnumPropDescriptor : public Reflection::EnumPropertyDescriptor
	{
	private:
		std::auto_ptr<typename Reflection::TypedPropertyDescriptor<Enum>::GetSet> getset;

	public:
		template<typename GetFunction, typename SetFunction>
		SurfaceEnumPropDescriptor(const char* name, const char* category, GetFunction get, SetFunction set, Functionality flags)
			: EnumPropertyDescriptor(PartInstance::classDescriptor(), Reflection::EnumDesc<Enum>::singleton(), name, category, flags),
			  getset(new SurfaceGetSet<id, Enum, GetFunction, SetFunction>(get, set))
		{
		}

		// 0059d490 / 00565960: forwarded to the getset (+0x1c).
		virtual bool isReadOnly() const
		{
			return getset->isReadOnly();
		}
		virtual bool isWriteOnly() const
		{
			return getset->isWriteOnly();
		}
		// Per-Enum overrides (vftable slots 4 / 5: 005ef1e0 / 005ef3a0 for SurfaceType, 005ef210 / 005ef3d0 for
		// InputType; they read the getset at +0x1c). Bodies of the remaining overrides are not recovered in this unit.
		virtual void getVariant(const Reflection::DescribedBase*, Reflection::Value&) const;
		virtual void setVariant(Reflection::DescribedBase*, const Reflection::Value&) const;
		virtual bool equalValues(const Reflection::DescribedBase*, const Reflection::DescribedBase*) const;
		virtual bool hasStringValue() const;
		virtual std::string getStringValue(const Reflection::DescribedBase*) const;
		virtual bool setStringValue(Reflection::DescribedBase*, const std::string&) const;
		virtual void writeValue(const Reflection::DescribedBase*, XmlElement*) const;
		virtual void readValue(Reflection::DescribedBase*, const XmlElement*, IReferenceBinder&) const;
		virtual unsigned getIndexValue(const Reflection::DescribedBase*) const;
		virtual bool setIndexValue(Reflection::DescribedBase*, unsigned) const;
		virtual int getEnumValue(const Reflection::DescribedBase*) const;
		virtual bool setEnumValue(Reflection::DescribedBase*, int) const;
	};

	// Dynamic initializers 007f7000..007f7140 (in this order). INFERRED: object names from the donor Surfaces.cpp
	// (desc_Legacy<face>); the name strings ("Top", "Bottom", "Back", "Front", "Right", "Left") are the target's.
	static SurfaceDescriptor<NORM_Y> desc_LegacyTop("Top");
	static SurfaceDescriptor<NORM_Y_NEG> desc_LegacyBottom("Bottom");
	static SurfaceDescriptor<NORM_X_NEG> desc_LegacyLeft("Back");
	static SurfaceDescriptor<NORM_X> desc_LegacyRight("Front");
	static SurfaceDescriptor<NORM_Z_NEG> desc_LegacyFront("Right");
	static SurfaceDescriptor<NORM_Z> desc_LegacyBack("Left");

	// Constructor instantiations (one per face): SurfaceEnumPropDescriptor 005ed6c0 005eda40 005edde0 005edf00 005ee120
	// 005ee260 005ee4a0 005ee650 005ee7a0 005ee8c0 005eea70 005eeb20, SurfacePropDescriptor 005edd40 005ee080 005ee400
	// 005ee700 005ee9d0 005eec20.
	template SurfaceEnumPropDescriptor<NORM_Y, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Y, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
	template SurfacePropDescriptor<NORM_Y, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Y_NEG, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Y_NEG, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
	template SurfacePropDescriptor<NORM_Y_NEG, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_X_NEG, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_X_NEG, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
	template SurfacePropDescriptor<NORM_X_NEG, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_X, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_X, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
	template SurfacePropDescriptor<NORM_X, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Z_NEG, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Z_NEG, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
	template SurfacePropDescriptor<NORM_Z_NEG, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Z, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Z, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
	template SurfacePropDescriptor<NORM_Z, float>::SurfacePropDescriptor(const char*, const char*, float (Surface::*)() const, void (Surface::*)(float), Reflection::PropertyDescriptor::Functionality);
}
