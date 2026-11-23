// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// Inactive native 2008-06 recovery: the class-name / service-index template rows of the clipboard verb unit inside the
// application range 00410000..00414000 (tests/record_native_app_unit410.py, receipt app-unit410-working.json). All
// headers are read-only here.
//
// The clipboard verb unit (CutVerb vtable 0080e990, CopyVerb 0080e960, PasteVerb 0080e934) creates ModelInstance,
// Script, LocalScript and ChangeHistoryService (Creatable / Creator rows counted by app-unit40c-2008) and looks up the
// Selection service. Its COMDAT run holds, in link order:
//   * Name::doDeclare<sC>() (101 B, `static const Name& n = declare(sC, -1)`) for Model 00413650, Script 004136c0,
//     LocalScript 00413730 and ChangeHistoryService 004137a0 (each pushes its class-name array);
//   * ServiceProvider::doGetClassIndex<Selection>() 00413810 (91 B, `static size_t index = newIndex()`, newIndex
//     00572690), called by find<Selection> 00415200;
//   * the matching tail jumps callDoDeclare<sC>() 00413a20 / 00413a30 / 00413a40 / 00413a50 and
//     callDoGetClassIndex<Selection>() 00413a60.
// Name::doDeclare / callDoDeclare are inline in native util/Name.h and are instantiated through Name::declare<sC>()
// (as AppUnit400_2008Names.cpp does); v8tree/Service.h declares doGetClassIndex / callDoGetClassIndex without
// bodies, so the definitions below are the ones AppUnit454_2008WndServices.cpp uses.
// Profile: document-swap flags, VS2008 RTM 21022.
#include "v8tree/Service.h"
#include "v8datamodel/ModelInstance.h"
#include "script/Script.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/Selection.h"

namespace RBX
{
	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }

	template const Name& Name::declare<sModel>();
	template const Name& Name::declare<sScript>();
	template const Name& Name::declare<sLocalScript>();
	template const Name& Name::declare<sChangeHistoryService>();
	template size_t ServiceProvider::doGetClassIndex<Selection>();
	template void ServiceProvider::callDoGetClassIndex<Selection>();

	// 00415200 (placeholder func_00415200, 328 B): ServiceProvider::find<Selection>() const, called by
	// ServiceProvider::create<Selection> 004153b0, CSelectionTreeCtrl::setDataModel 00426bf0 and CWorkspace::cleanup
	// 0046b0e0: boost::call_once 00557330 of callDoGetClassIndex<Selection> 00413a60 (flag 0096cc30), doGetClassIndex
	// 00413810, serviceArray +0x190 resize 004124c0, findServiceByClassName 00572a90 with className() (Name::declare
	// 004068c0 behind call_once 00406ec0), out-of-line ~shared_ptr 00600660 (boost-noinline-shared-destructor). Same
	// template bodies as AppUnit450ServiceFind.cpp.
	template<class Class, class Derived, const char* Name>
	const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }

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

	template Selection* ServiceProvider::find<Selection>() const;
}
