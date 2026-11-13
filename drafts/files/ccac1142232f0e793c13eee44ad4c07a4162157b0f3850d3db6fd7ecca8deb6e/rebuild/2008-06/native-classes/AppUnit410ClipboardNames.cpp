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
}
