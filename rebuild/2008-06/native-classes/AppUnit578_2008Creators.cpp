// 2008-06 native rows of the Creatable / FactoryProduct / ServiceProvider template instances that the DataModel
// translation unit (v8datamodel/DataModel.cpp, 00574f10..0057c1af) emits inside the application range
// 00578000..0057c000, inactive. Verified by tests/record_native_app_unit578_2008.py. Every header is a committed
// native header, read-only here.
//
// The rows lie in the COMDAT run of the DataModel unit (link order):
//   * boost::shared_ptr<LocalBackpackItem>(LocalBackpackItem*, Creatable<Instance>::Deleter) 00578030 (171 B, the
//     enable_shared_from_this hook-up; calls the shared_count instance 00577fa0);
//   * Creatable<Instance>::create<LocalBackpackItem>() 005780e0 (120 B: malloc 0x188 = sizeof(LocalBackpackItem),
//     LocalBackpackItem() 005fccd0, shared_ptr<LocalBackpackItem>(p, Deleter()));
//   * FactoryProduct<LocalBackpackItem, Widget, sLocalBackpackItem>::Creator::create() const 00578160 (175 B, slot 0
//     of the Creator vtable 0082fffc) and FactoryProduct<LocalBackpack, RelativePanel, sLocalBackpack>::Creator::
//     create() const 00578210 (slot 0 of 00830018; calls create<LocalBackpack> 005771b0);
//   * shared_count(Tool*, Deleter) 005782c0 (counted by creatable-shared-count), shared_ptr<Tool>(Tool*, Deleter)
//     00578350, Creatable<Instance>::create<Tool>() 00578400 (malloc 0x270 = sizeof(Tool), Tool() 00600240) and
//     FactoryProduct<Tool, BackpackItem, sTool>::Creator::create() const 00578480 (slot 0 of 00830020);
//   * ServiceProvider::find<LocalBackpack>() const 00578530 (320 B) and ServiceProvider::create<LocalBackpack>()
//     const 00578930 (228 B), called by DataModel::initializeContents 0057a9f0.
// LocalBackpack2008/LocalBackpack2008.h declares the const char class-name arrays the RTTI names (3QBDB);
// v8datamodel/Tool.h does the same for sTool. The template definitions below are the ones
// native-classes/AppUnit448_2008Services.cpp and AppUnit400_2008Creators.cpp use for the declarations in
// util/Object.h and v8tree/Service.h.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "LocalBackpack2008/LocalBackpack2008.h"
#include "v8datamodel/Tool.h"
#include "util/Object.h"

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class> Class* ServiceProvider::find() const
	{
		size_t index = getClassIndex<Class>();
		Class* service;
		if (index + 1 > serviceArray.size())
		{
			serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
			service = NULL;
		}
		else
		{
			service = static_cast<Class*>(serviceArray[index].get());
			if (service != NULL)
				return service;
		}
		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;
		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	template<class Class> Class* ServiceProvider::create() const
	{
		Class* service = find<Class>();
		if (service == NULL)
		{
			boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
			service = value.get();
			size_t index = getClassIndex<Class>();
			serviceArray[index] = value;
			service->setParent(const_cast<ServiceProvider*>(this));
		}
		return service;
	}

	template LocalBackpack* ServiceProvider::find<LocalBackpack>() const;
	template LocalBackpack* ServiceProvider::create<LocalBackpack>() const;
}

template boost::shared_ptr<RBX::LocalBackpackItem> RBX::Creatable<RBX::Instance>::create<RBX::LocalBackpackItem>();
template boost::shared_ptr<RBX::Tool> RBX::Creatable<RBX::Instance>::create<RBX::Tool>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LocalBackpackItem, RBX::Widget, RBX::sLocalBackpackItem>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::LocalBackpack, RBX::RelativePanel, RBX::sLocalBackpack>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Tool, RBX::BackpackItem, RBX::sTool>::Creator::create() const;
