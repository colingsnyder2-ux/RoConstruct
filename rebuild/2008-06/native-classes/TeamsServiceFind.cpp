// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// 2008-06 native ServiceProvider::find<Teams>() const 0049a580 (320 B; registry placeholder func_0049a580). Identity:
// callers create<Teams> 004b3b40 (ServiceProviderTeamsCreate.cpp), find<Teams>(const Instance*) 0049ab50
// (ServiceProviderStaticFind2008.cpp) and DataModel::clearContents 00578ef0; body: getClassIndex<Teams> (call_once
// 00557330 on callDoGetClassIndex<Teams>, doGetClassIndex 004962f0), serviceArray.resize 004124c0, findServiceByClassName
// 00572a90 with FactoryProduct<Teams>::className 0048a1e0, shared_ptr assign 004025b0 and the out-of-line
// ~shared_ptr<Instance> 00600660. The COMDAT sits in the Players unit (onChildAdded's find<Teams>(this)). Same template
// body and flags/profile as PlayersServiceFind.cpp (find<Players> 004125d0); ServiceProviderTeamsCreate.cpp keeps the
// inline-destructor profile its create<Teams> 004b3b40 needs, so find<Teams> lives in this unit.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/Teams.h"

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

	template Teams* ServiceProvider::find<Teams>() const;                     // 0049a580
}
