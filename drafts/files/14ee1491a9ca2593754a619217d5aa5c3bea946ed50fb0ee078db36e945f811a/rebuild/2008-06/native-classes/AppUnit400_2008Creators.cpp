// 2008-06 native Creatable / FactoryProduct template instances of the application range 00400000..0040c000
// (inactive). Verified by tests/record_native_app_unit400_2008.py. All headers are read-only here.
//
// The rows lie in the COMDAT run of the unit whose static initializers 007ee760..007eebe0 declare the class names
// (Name::doDeclare rows, AppUnit400_2008Names.cpp). Each class has up to four bodies, in link order:
//   * boost::detail::shared_count(C*, Creatable<Instance>::Deleter) (131 B);
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) (171 B, the enable_shared_from_this hook-up);
//   * Creatable<Instance>::create<C>() (120 B: malloc(sizeof(C)), C(), shared_ptr<C>(p, Deleter()));
//   * FactoryProduct<C, D, N>::Creator::create() const (175 B, slot 0 of the Creator vtable): calls
//     Creatable<Instance>::create<C>() and returns it as shared_ptr<Object>.
// Classes in link order: RunService (00405e60..), DebugSettings (00406ed0, 00407450, 00407820, 00408ce0),
// CRenderSettings (00408d90..00408f50), Team (00409000..), Network::Player (00409270..), Selection (004094e0..).
// sizeof(C) comes from the native headers and is checked by the malloc size each create<C> passes.
#include "util/RunStateOwner.h"
#include "v8datamodel/DebugSettings.h"
#include "CRenderSettings.h"
#include "v8datamodel/Team.h"
#include "Network/Player.h"
#ifdef NATIVE_APPUNIT400_PENDING
#include "v8datamodel/Selection.h"
#endif
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::RunService> RBX::Creatable<RBX::Instance>::create<RBX::RunService>();
template boost::shared_ptr<RBX::DebugSettings> RBX::Creatable<RBX::Instance>::create<RBX::DebugSettings>();
template boost::shared_ptr<CRenderSettings> RBX::Creatable<RBX::Instance>::create<CRenderSettings>();
template boost::shared_ptr<RBX::Team> RBX::Creatable<RBX::Instance>::create<RBX::Team>();
template boost::shared_ptr<RBX::Network::Player> RBX::Creatable<RBX::Instance>::create<RBX::Network::Player>();
// Selection: create<Selection> 00409620 (with shared_ptr<Selection>(Selection*, Deleter) 00409570) and its Creator
// 004096a0 need a Selection constructor; the native v8datamodel/Selection.h leaves Selection abstract (no
// onEvent(AncestorChanged) override, no constructor), so they are built only with NATIVE_APPUNIT400_PENDING against a
// generated header copy (proposal).
#ifdef NATIVE_APPUNIT400_PENDING
template boost::shared_ptr<RBX::Selection> RBX::Creatable<RBX::Instance>::create<RBX::Selection>();
#endif

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::RunService, RBX::Instance, RBX::sRunService>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::DebugSettings, RBX::GlobalSettings::Item, RBX::sDebugSettings>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<CRenderSettings, RBX::GlobalSettings::Item, sRenderSettings>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Team, RBX::Instance, RBX::sTeam>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Network::Player, RBX::Instance, RBX::Network::sPlayer>::Creator::create() const;
#ifdef NATIVE_APPUNIT400_PENDING
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Selection, RBX::Instance, RBX::sSelection>::Creator::create() const;
#endif
