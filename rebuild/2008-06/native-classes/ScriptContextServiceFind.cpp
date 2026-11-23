// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// 2008-06 native ServiceProvider::find<ScriptContext>() const 0042de90 (320 B; registry placeholder func_0042de90).
// Identity: called by ServiceProvider::create<ScriptContext>() const 0042dfd0 (AppUnit424_2008ScriptContextTemplates.cpp,
// the CLuaFunction unit) and by Script::... 00586bf0 (AppUnit57C_2008Script.cpp note); body: getClassIndex<ScriptContext>,
// serviceArray.resize 004124c0, findServiceByClassName 00572a90 with FactoryProduct<ScriptContext>::className, shared_ptr
// assign 004025b0 and the out-of-line ~shared_ptr<Instance> 00600660. The AppUnit424 copy inlines that destructor (404 B),
// so this template body uses the same noinline-destructor profile as TeamsServiceFind.cpp / PlayersServiceFind.cpp.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "script/ScriptContext.h"

extern template boost::shared_ptr<RBX::Instance>::~shared_ptr();

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

	template<class Class>
	size_t ServiceProvider::doGetClassIndex()
	{
		static size_t index = newIndex();
		return index;
	}

	template<class Class>
	void ServiceProvider::callDoGetClassIndex()
	{
		doGetClassIndex<Class>();
	}

	template<class Class>
	size_t ServiceProvider::getClassIndex()
	{
		static boost::once_flag flag = BOOST_ONCE_INIT;
		boost::call_once(&callDoGetClassIndex<Class>, flag);
		return doGetClassIndex<Class>();
	}

	template<class Class>
	Class* ServiceProvider::find() const
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
			if (service)
				return service;
		}

		boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
		if (!item)
			return NULL;

		service = static_cast<Class*>(item.get());
		serviceArray[index] = item;
		return service;
	}

	template ScriptContext* ServiceProvider::find<ScriptContext>() const;     // 0042de90
}
