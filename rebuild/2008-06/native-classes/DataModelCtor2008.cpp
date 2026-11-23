// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native DataModel::DataModel() 0057b9f0 (inactive) and Creatable<Instance>::create<DataModel> 0057c080.
// Evidence (2008 disassembly; the 2007 donor DataModel.cpp:40 is the same shape): VerbContainer(NULL) at +0x1c8, the
// workspace member (+0x204) created from `this` (create<Workspace> 00576ff0), two GuiRoot creates (0057 7090, +0x21c/+0x224,
// folded with other create<> bodies), guiTarget 0 (+0x22c), forceArrowCursor = 1 (+0x230), uiMessage string (+0x234),
// dirty/renderEnabled 0 (+0x258/+0x259), mutex = shared_ptr(new boost::recursive_mutex) (+0x25c/+0x260), then setName("Level").
// INFERRED: member names/order follow native-headers/v8datamodel/DataModel.h.
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "gui/Gui.h"
#include "util/Object.h"

namespace RBX
{
	DataModel::DataModel()
		: VerbContainer(NULL),
		  workspace(Creatable<Instance>::create<Workspace>(this)),
		  guiRoot(Creatable<Instance>::create<GuiRoot>()),
		  guiHooks(Creatable<Instance>::create<GuiRoot>()),
		  guiTarget(NULL),
		  forceArrowCursor(true),
		  tempMetric(NULL),
		  dirty(false),
		  renderEnabled(false),
		  mutex(new boost::recursive_mutex)
	{
		setName("Level");
	}
}

// 0057c080: Creatable<Instance>::create<DataModel>() (malloc(0x264), DataModel(), shared_ptr with the Creatable deleter)
template boost::shared_ptr<RBX::DataModel> RBX::Creatable<RBX::Instance>::create<RBX::DataModel>();
