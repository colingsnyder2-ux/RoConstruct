// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Surfaces.h"
#include "v8datamodel/Surface.h"
#include "util/SurfaceType.h"
// util/Controller.h is not included: v8datamodel/PartInstance.h already brings v8world/Controller.h (C2011 otherwise),
// the same include set as SurfacePropDescriptor.cpp.
#include "util/NormalId.h"
#include "reflection/reflection.h"
#include "v8xml/XmlElement.h"

namespace RBX
{
	template<NormalId face, typename Enum>
	class SurfaceEnumPropDescriptor : public Reflection::EnumPropertyDescriptor
	{
	private:
		template<typename GetFunction, typename SetFunction>
		class GetSetImpl : public Reflection::TypedPropertyDescriptor<Enum>::GetSet
		{
		private:
			GetFunction get;
			SetFunction set;
		public:
			GetSetImpl(GetFunction get, SetFunction set) : get(get), set(set) {}
			virtual bool isReadOnly() const { return false; }
			virtual bool isWriteOnly() const { return false; }
			virtual Enum getValue(const Reflection::DescribedBase* object) const
			{
				PartInstance* o = (PartInstance*)object;
				return (o->getSurfaces()[face].*get)();
			}
			virtual void setValue(Reflection::DescribedBase* object, const Enum& value) const
			{
				PartInstance* o = (PartInstance*)object;
				(o->getSurfaces()[face].*set)(value);
			}
		};
		std::auto_ptr<typename Reflection::TypedPropertyDescriptor<Enum>::GetSet> getset;
	public:
		template<typename GetFunction, typename SetFunction>
		SurfaceEnumPropDescriptor(char const* name, char const* category, GetFunction get, SetFunction set,
			Reflection::PropertyDescriptor::Functionality flags)
			: Reflection::EnumPropertyDescriptor(PartInstance::classDescriptor(), Reflection::EnumDesc<Enum>::singleton(), name, category, flags),
			  getset(new GetSetImpl<GetFunction, SetFunction>(get, set))
		{
		}
		virtual bool isReadOnly() const { return getset->isReadOnly(); }
		virtual bool isWriteOnly() const { return getset->isWriteOnly(); }
		virtual void getVariant(const Reflection::DescribedBase* instance, Reflection::Value& value) const
		{
			value = getset->getValue(instance);
		}
		virtual bool setIndexValue(Reflection::DescribedBase* instance, unsigned index) const
		{
			Enum val;
			if (Reflection::EnumDesc<Enum>::singleton().convertToValue(index, val))
			{
				getset->setValue(instance, val);
				return true;
			}
			return false;
		}
	};

	template SurfaceEnumPropDescriptor<NORM_Y, SurfaceType>::SurfaceEnumPropDescriptor(const char*, const char*, SurfaceType (Surface::*)() const, void (Surface::*)(SurfaceType), Reflection::PropertyDescriptor::Functionality);
	template SurfaceEnumPropDescriptor<NORM_Y, Controller::InputType>::SurfaceEnumPropDescriptor(const char*, const char*, Controller::InputType (Surface::*)() const, void (Surface::*)(Controller::InputType), Reflection::PropertyDescriptor::Functionality);
}