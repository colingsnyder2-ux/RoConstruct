// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_6f0d189a6d77d9cd.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#undef _DEBUG
#define _DLL
#define lineSegment(a, b, c) lineSegment(a, b, c) = 0; virtual void exeAdornExtra()
#include "RbxGraphics/Adorn.h"
#undef lineSegment
#define private public
#include "util/IRenderable.h"
#undef private
#include "util/Object.h"
#define hasListeners() hasListeners() const { return listeners.size() > 0; } bool hasListenersEmpty()
#include "util/Events.h"
#undef hasListeners
namespace RBX { template<class T> class GuidItem { public: virtual ~GuidItem() {} char guidPad[0xc]; }; }
namespace RBX { template<class T> class GuidAFP : public AbstractFactoryProduct<T> { protected: virtual void onGuidChanged() {} }; }
#define AbstractFactoryProduct GuidItem<Instance>, public GuidAFP
#include "util/Guid.h"
namespace RBX { class GuidStub { public: typedef Guid::Data Data; void assign(const Data&) {} operator const Guid&() const { return *(const Guid*)0; } }; }
#define Guid GuidStub
#include "v8tree/Instance.h"
#undef Guid
#undef AbstractFactoryProduct
#include "v8datamodel/PVInstance.h"
#define candidatePrimaryPart candidatePrimaryPart; std::vector<boost::shared_ptr<PartInstance> > exeModelVector
#include "v8datamodel/ModelInstance.h"
#undef candidatePrimaryPart
#include "v8datamodel/RootInstance.h"
#include "v8datamodel/Stats.h"
#include "v8tree/Verb.h"
#include "script/Script.h"
#include "v8world/IMoving.h"
#include "gui/GuiEvent.h"
#include "util/RunStateOwner.h"
#include "util/ContentProvider.h"
#include "util/Profiling.h"
#include "util/UIEvent.h"
#define render3dSelect(a, b) render3dSelect(a, b) { return; } void exeCheckCamera(); void exeUnusedSelect(a, b)
#define idleMouseEvent idleMouseEvent; int exeField3cc; struct ExeCamSlot {
#define isSimulating exeCamSlotEnd; }; bool isSimulating
#include "v8datamodel/Workspace.h"
#undef idleMouseEvent
#undef isSimulating
#undef render3dSelect
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/Camera.h"
#include "v8datamodel/Selection.h"

#include "v8datamodel/Stats.h"
#include "util/RunStateOwner.h"
#include "script/ScriptContext.h"
namespace RBX
{
	template<class T, class A, class B, class C> boost::shared_ptr<T> create3(A a, B b, C c);

	void Workspace::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (oldProvider)
		{
			Notifier<RunService, Heartbeat>::disconnect(oldProvider->find<RunService>(), this);
			if (statsItem)
			{
				statsItem->setParent(NULL);
				statsItem.reset();
			}
		}
		if (newProvider)
		{
			scriptContext = newProvider->create<ScriptContext>();
			RunService* runService = newProvider->find<RunService>();
			Notifier<RunService, Heartbeat>::connect(runService, this);
			if (Stats::Item* item = newProvider->create<Stats::Item>())
			{
				statsItem = create3<WorkspaceStatsItem>(this, world.get(), runService);
				statsItem->setParent(item);
			}
		}
	}
}
