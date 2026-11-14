// Inactive native 2008-06 recovery: rows of the CChatPrompt unit inside the application range 00410000..00414000
// (tests/record_native_app_unit410.py, receipt app-unit410-working.json).
//
// The class comes from the committed native-headers/CChatPrompt.h (read-only; layout 0xa8 bytes, the size the
// CRuntimeClass 0080df88 and CreateObject 00411ef0 use). CChatPrompt.cpp (compiled unchanged by the recorder) defines
// the constructor and bind(); this file defines the members the header declares without a body:
//   * ~CChatPrompt() 004129c0: stores vtable 0080e1ac, calls bind(NULL, NULL) 00412800, then the member destructors
//     (context +0x9c, brush +0x94 with the inline ~CBrush -> ~CGdiObject 004111a0, chat +0x8c) and ~CEditView;
//   * IMPLEMENT_DYNCREATE(CChatPrompt, CEditView) (DECLARE_DYNCREATE is in the header): classCChatPrompt 0080df88
//     ("CChatPrompt", 0xa8, 0xffff, CreateObject 00411ef0, _GetBaseClass 00411350), GetThisClass / GetRuntimeClass
//     00411360 (identical code, folded; 00432e60 calls it directly).
// and the ServiceProvider / Name templates the unit instantiates for Network::Players (bind calls create<Players>):
//   * Name::doDeclare<sPlayers>() 00411420 ("Players" 0093784c) and callDoDeclare 00411890;
//   * ServiceProvider::doGetClassIndex<Players>() 00411490 (newIndex 00572690) and callDoGetClassIndex 00411930;
//   * ServiceProvider::find<Players>() const 004125d0 and create<Players>() const 00412710.
// v8tree/Service.h and util/Object.h declare these templates without bodies; the definitions below are the ones
// AppUnit454_2008WndServices.cpp / AppUnit48C_2008Services.cpp use. Profile: document-swap flags, RTM 21022.
#include <afxext.h>
#include <boost/thread/once.hpp>
#include "CChatPrompt.h"
#include "ChatEnter.h"
#include "v8datamodel/DataModel.h"
#include "v8tree/Service.h"
#include "Network/Players.h"

CChatPrompt::~CChatPrompt()
{
    bind(NULL, NULL);
}

IMPLEMENT_DYNCREATE(CChatPrompt, CEditView)

namespace RBX
{
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }
	// Players is a DescribedNonCreatable, so find<Players> reaches NonFactoryProduct::className (as in
	// NetworkPlayers.cpp / AppUnit454_2008ReportStats.cpp).
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

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

	template Network::Players* ServiceProvider::find<Network::Players>() const;
	template Network::Players* ServiceProvider::create<Network::Players>() const;
	template const Name& Name::declare<Network::sPlayers>();
}
