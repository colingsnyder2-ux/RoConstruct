// 2008-06 native rows of the CLuaFunction translation unit of the application range 00424000..00430000 (inactive).
// Verified by tests/record_native_app_unit424_2008.py; the unit map is in its receipt.
//
// The CLuaFunction unit (0042cf40..0042e45f: the COM object CComObject<CLuaFunction> 0080ebd8, LuaArgs::push 0042db20)
// reaches the ScriptContext service and is, in link order, the first to emit these RBX template COMDATs:
//   * Name::doDeclare<sScriptContext>() 0042ced0 (pushes the class-name array "ScriptContext") and its
//     Name::callDoDeclare<sScriptContext>() 0042d090 (5-byte jmp);
//   * ServiceProvider::doGetClassIndex<ScriptContext>() 0042d030 and callDoGetClassIndex<ScriptContext>() 0042d180;
//   * ServiceProvider::create<ScriptContext>() const 0042dfd0 (callers: CLuaFunction 0042e229 and the app units
//     00453f59..) and the find<ScriptContext>() const 0042de90 it calls. find is emitted here only through create and
//     is not exact: the original calls ~shared_ptr<Instance> out of line (00600660) where the native boost header
//     inlines it (the same open row shape as find<C>() 00490af0.. in app-unit48c-2008);
//   * Creatable<Instance>::create<ScriptContext>() 0042d3f0 (malloc 0x1f8 = sizeof(ScriptContext), constructor
//     005ae490) with its shared_ptr<ScriptContext>(ScriptContext*, Deleter) 0042d2c0;
//   * FactoryProduct<ScriptContext, Instance, sScriptContext>::Creator::create() const 0042dde0, the only slot of the
//     Creator vtable 00810710 (RTTI .?AVCreator@?$FactoryProduct@VScriptContext@RBX@@VInstance@2@$1?sScriptContext@2@
//     3PADA@RBX@@: the class name is a non-const char array).
// Headers are read-only here (script/ScriptContext.h, v8tree/Service.h, util/Object.h, util/Name.h). Service.h and
// Object.h only declare the ServiceProvider index / find / create templates and Creator::create, so their template
// definitions are given below (the same definitions as ServiceProvider.cpp, AppUnit480_2008PlayerTemplates.cpp and
// AppUnit634_2008Value.cpp).
// >>> native-status (generated) -- do not edit >>>
// AppUnit424_2008ScriptContextTemplates | 2008-06 | draft (no current byte proof)
// 0/2 mapped addresses byte-exact | 2 unproved | no mapped strings | by auto (+1) (mixed 2)
// <<< native-status | src efe7be4d | roc native-status --write
#include "script/ScriptContext.h"
#include "v8tree/Service.h"
#include "util/Object.h"
#include "util/Name.h"
#include "boost/thread/once.hpp"

namespace RBX
{
	template<class Class> size_t ServiceProvider::doGetClassIndex()
	{
		static size_t index = newIndex();
		return index;
	}

	template<class Class> void ServiceProvider::callDoGetClassIndex()
	{
		doGetClassIndex<Class>();
	}

	template<class Class> size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

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

	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

	template const Name& Name::declare<sScriptContext>();
	template ScriptContext* ServiceProvider::create<ScriptContext>() const;
	template boost::shared_ptr<Object> FactoryProduct<ScriptContext, Instance, sScriptContext>::Creator::create() const;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::ScriptContext>;
