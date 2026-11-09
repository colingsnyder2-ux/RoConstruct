// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_6c421854277b7abe.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
#define AbstractFactoryProduct GuidItem<Instance>, public AbstractFactoryProduct
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
#include "util/StateStack.h"
namespace RBX { template<class T> class __declspec(novtable) StateStackStub { public: virtual void setDirty(bool) = 0; virtual bool isDirty() const = 0; size_t getStackSize() const; }; }
#define StateStack StateStackStub
#include "v8tree/Verb.h"
#undef StateStack
#include <boost/scoped_ptr.hpp>
namespace RBX { class TimeState; }
namespace boost { template<> class scoped_ptr<RBX::TimeState> { public: RBX::TimeState* operator->() const; RBX::TimeState* get() const; }; }
#define tempMetric tempMetric; bool exeFlag
#include "v8datamodel/Lighting.h"
#include "v8datamodel/DataModel.h"
#undef tempMetric
#include "v8datamodel/TimeState.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/Teams.h"
#include "v8datamodel/JointsService.h"
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/GuiBuilder.h"
#include "script/ScriptContext.h"
#include "gui/GUI.h"
#include "util/Log.h"
#include "util/IMetric.h"
#include "util/standardout.h"
#include "util/Http.h"
#include "util/Sound.h"

namespace RBX
{
#pragma warning (push)
#pragma warning (disable : 4355)
	DataModel::DataModel()
		: VerbContainer(NULL),
		  workspace(Creatable::create<Workspace>(this)),
		  guiRoot(Creatable::create<GuiRoot>()),
		  guiHooks(Creatable::create<GuiRoot>()),
		  mutex(new boost::recursive_mutex),
		  guiTarget(NULL),
		  forceArrowCursor(true),
		  exeFlag(false),
		  dirty(false),
		  drawId(0)
	{
		setName("Level");
	}
#pragma warning (pop)
}
