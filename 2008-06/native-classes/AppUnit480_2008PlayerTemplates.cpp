// 2008-06 native rows of the RBX::Network::Player translation unit that starts inside 00480000..0048c000
// (inactive). Verified by tests/record_native_app_unit480_2008.py; the unit map is in its receipt.
//
// The Player unit (Network/Player.cpp, 004897a0..) emits, in link order, the first COMDAT copies of templates it
// instantiates through the services and class names it uses:
//   * Name::doDeclare<sX>() (101 B) / Name::callDoDeclare<sX>() (5 B jmp) for the class names it declares; this
//     file builds the ones no other receipt counts: Workspace 00489c30 / 0048aa70, ShirtGraphic 00489f40 /
//     0048aae0, Clothing 00489fb0 / 0048aaf0, Pants 0048a020 / 0048ab00, Shirt 0048a090 / 0048ab10, Skin 0048a170 /
//     0048ab30, Teams 0048a1e0 / 0048ab40 (callDoDeclare -> doDeclare jumps read in the original; the string each
//     doDeclare pushes is the class-name array the header declares);
//   * ServiceProvider::doGetClassIndex<C>() (91 B) / callDoGetClassIndex<C>() (5 B jmp) for the services
//     ServiceProvider::create<C>() const 00490f10 / 00490af0 / 00490c30 / 00490d70 creates: TimerService 0048a400 /
//     0048ad50 (Name "Timer" 0048a250), Workspace 0048a460 / 0048ad60 (Name "Workspace" 00489c30), SpawnerService
//     0048a4c0 / 0048ad70 (Name "SpawnerService" 00489ed0), StarterPackService 0048a520 / 0048ad80 (Name
//     "StarterPack" 00489d10).
// Headers are read-only here. Name::declare / doDeclare / callDoDeclare are the util/Name.h templates; v8tree/Service.h
// declares ServiceProvider::getClassIndex / doGetClassIndex / callDoGetClassIndex without bodies, so their template
// definitions are given below (the same definitions ServiceChangeHistory.cpp uses).
#include "util/Name.h"
#include "v8tree/Service.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Clothing.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/TimerService.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Hopper.h"

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

	template const Name& Name::declare<sWorkspace>();
	template const Name& Name::declare<sShirtGraphic>();
	template const Name& Name::declare<sClothing>();
	template const Name& Name::declare<sPants>();
	template const Name& Name::declare<sShirt>();
	template const Name& Name::declare<sSkin>();
	template const Name& Name::declare<sTeams>();

	template size_t ServiceProvider::getClassIndex<TimerService>();
	template size_t ServiceProvider::getClassIndex<Workspace>();
	template size_t ServiceProvider::getClassIndex<SpawnerService>();
	template size_t ServiceProvider::getClassIndex<StarterPackService>();
}
