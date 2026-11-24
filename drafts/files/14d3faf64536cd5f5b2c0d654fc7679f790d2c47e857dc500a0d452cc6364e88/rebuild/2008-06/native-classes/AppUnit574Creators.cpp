// 2008-06 native rows of the Creatable / ServiceProvider template instances that the DataModel translation unit
// (v8datamodel/DataModel.cpp, 00574f10..0057c1af) emits inside the application range 00574000..00578000, inactive.
// Verified by tests/record_native_app_unit574.py. Every header is a committed native header, read-only here.
//
// The rows lie in the COMDAT run of the DataModel unit (link order, evidence names):
//   * boost::shared_ptr<C>(C*, Creatable<Instance>::Deleter) for Workspace 00576b20, GuiRoot 00576bd0 and
//     LocalBackpack 00576d10 (171 B each, the enable_shared_from_this hook-up; each calls the shared_count instance
//     005766c0 / 00576750 / 00576810 that creatable-shared-count counts). shared_ptr<DataModel> 00576a70 is not built:
//     it needs create<DataModel>, i.e. a declared DataModel() (DataModel.h proposal);
//   * Creatable<Instance>::create<Workspace, DataModel*>(DataModel*) 00576ff0 (malloc 0x45c, Workspace(IDataState*)
//     005a4d90 with the DataModel -> IDataState conversion), create<GuiRoot>() 00577090 (malloc 0x144, GuiRoot()
//     00573b10) and create<LocalBackpack>() 005771b0 (malloc 0x1ac, LocalBackpack() 005fceb0);
//   * ServiceProvider::doGetClassIndex<LocalBackpack>() 00575630 and callDoGetClassIndex<LocalBackpack>() 00576800.
#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "LocalBackpack2008/LocalBackpack2008.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/DataModel.h"
#include "gui/Gui.h"
#include "util/Object.h"

namespace RBX
{
	template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
	template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }

	template size_t ServiceProvider::doGetClassIndex<LocalBackpack>();
	template void ServiceProvider::callDoGetClassIndex<LocalBackpack>();
}

template boost::shared_ptr<RBX::Workspace> RBX::Creatable<RBX::Instance>::create<RBX::Workspace, RBX::DataModel*>(RBX::DataModel*);
template boost::shared_ptr<RBX::GuiRoot> RBX::Creatable<RBX::Instance>::create<RBX::GuiRoot>();
template boost::shared_ptr<RBX::LocalBackpack> RBX::Creatable<RBX::Instance>::create<RBX::LocalBackpack>();

// Batch 51: 00574f80 (18 B, registry placeholder func_00574f80) is DataModel::setUiMessageBrickCount, the inline
// v8datamodel/DataModel.h body `uiMessage = "[[[progress]]]"` (std::string::operator=(const char*) import on
// this +0x234 with the literal 0082fd64). The DataModel.cpp object emits it out of line because its address is the
// member pointer of the "SetMessageBrickCount" function descriptor: the dynamic initializer 007f3670 pushes
// security 1 / "SetMessageBrickCount" 008304b4 / the 8-byte member pointer {00574f80, 0} and calls the
// BoundFuncDesc<DataModel, void(), 0> constructor 00579920 on the static object 00974eb8 (donor openrbx
// v8datamodel/DataModel.cpp func_SetUIMessageBrickCount; the target binary passes security 1).
// BLOCKED: the core v8datamodel/DataModel.h does not declare it. Proposal, public section next to getGuiRoot:
//     void setUiMessageBrickCount() { uiMessage = "[[[progress]]]"; }   // 00574f80
// Define DATAMODEL_HEADER_DECLARES_SETUIMESSAGEBRICKCOUNT (or drop the guard) once the core header declares it.
#ifdef DATAMODEL_HEADER_DECLARES_SETUIMESSAGEBRICKCOUNT
#include "reflection/reflection.h"
namespace RBX
{
	static Reflection::BoundFuncDesc<DataModel, void(), 0> func_SetUIMessageBrickCount(&DataModel::setUiMessageBrickCount, "SetMessageBrickCount", static_cast<Reflection::FunctionDescriptor::Security>(1));
}
#endif
